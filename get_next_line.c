/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:23:20 by jsousa-a          #+#    #+#             */
/*   Updated: 2022/12/06 01:27:02 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*t;

	t = (unsigned char *) s;
	while (n > 0)
	{
		*t = 0;
		n--;
		t++;
	}
}
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!*lst && new)
		*lst = new;
	else if (lst && new && *lst)
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
}
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
char	*ft_strdup(const char *s)
{
	char	*scpy;
	int		i;

	i = 0;
	scpy = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!scpy)
		return (NULL);
	while (s[i])
	{
		scpy[i] = s[i];
		i++;
	}
	return (scpy);
}
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = ft_strdup(content);
	new->next = NULL;
	return (new);
}
void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst->content);
	free(lst);
}
void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = temp;
	}
	lst = NULL;
}
/*int		checknlorzero(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}*/
int	postnl(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n' && i < BUFFER_SIZE - 1)
		i++;
	else
		return (-1);
	return (i);
}
int	notfirst(void)
{
	static int	i = -1;

	return (++i);
}
int		ft_charcount_fd(int fd, t_list **hlst, t_list *lst)
{
	int	ct;
	int	i;
	int	check;
	int	scndpass;
	static char buffct[BUFFER_SIZE];
//								static int nb = 1;
//								printf("*********** %i : GNL CALL *********\n", nb++);
	ct = 0;
	check = 1;
	scndpass = 0;
	if (notfirst() && *buffct)
		check = -42;
//								printf("-- buffct = %s\n", buffct);
	while (check > 0 || check == -42)
	{
		i = 0;
		if (check == -42)
		{
			i = postnl(buffct);
			if (i >= 0)
				scndpass = i;
//								printf("-- buffct postnl = %s\n", &buffct[i]);
//								printf("---- i = %i\n", i);
			check = 1;
		}
		else 
			check = read(fd, buffct, BUFFER_SIZE);
		if (check && i >= 0)
		{
			lst = ft_lstnew(&buffct[i]);
//									printf("%s", (char *) lst->content);
			ft_lstadd_back(hlst, lst);
			lst = lst->next;
			while (buffct[i] && buffct[i] != '\n')
				i++;
			if (buffct[i] == '\n')
				i++;
			ct += i;
			if (i < BUFFER_SIZE && (!buffct[i] || buffct[i - 1] == '\n'))
				return (ct - scndpass);
		}
	}
	return (ct - scndpass);
}
char	*get_next_line(int fd)
{
	int		i[3];
	char	*buffer;
	char	*lel;
	t_list	*lst;
	t_list	**hlst;

	i[1] = 0;
	i[2] = 0;
	lst = NULL;
	hlst = &lst;
	i[0] = ft_charcount_fd(fd, hlst, lst);
	if (i[0])
	{
		buffer = ft_calloc(i[0] + 1, 1);
		if (!buffer)
			return (NULL);
	}
	lst = *hlst;
//							printf("i[0] = %i\n", i[0]);
	while (i[2] < i[0])
	{
		i[1] = 0;
		lel = (char *) lst->content;
		while (i[1] < BUFFER_SIZE && i[2] < i[0] && lel[i[1]])
		{
			buffer[i[2]++] = lel[i[1]++];
		}
//							printf("-----str = %s------\n", buffer);
//							printf("lst->next = %p -- lst->content = %s\n", lst, lel);
		lst = lst->next;
//							printf("end of while (i[2] = %i)\n", i[2]);
	}
//							printf("Test avant de lstclear\n");
	ft_lstclear(hlst);
	return (buffer);
}

