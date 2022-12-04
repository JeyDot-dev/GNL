/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:23:20 by jsousa-a          #+#    #+#             */
/*   Updated: 2022/12/04 01:44:19 by jsousa-a         ###   ########.fr       */
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
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
/*int		checknlorzero(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}*/
int		ft_charcount_fd(int fd)
{
	int	ct;
	int	i;
	int	check;
	static char buffct[BUFFER_SIZE];

	ct = 0;
	check = 1;
										printf("before while\n");
	while (check > 0)
	{
		i = 0;
		check = read(fd, buffct, BUFFER_SIZE);
		if (check)
		{
			while (buffct[i] && buffct[i] != '\n')
				i++;
			ct += i;
			if (i < BUFFER_SIZE && (!buffct[i] || buffct[i] == '\n'))
				return (ct);
		}
	}
	return (ct);
}
char	*get_next_line(int fd)
{
	int		fdtemp;
	int		size;
	char	*buffer;

	fdtemp = fd;
	size = ft_charcount_fd(fdtemp);
	if (size)
		buffer = ft_calloc(size + 1, 1);
	if (!buffer)
		return (NULL);
	read(fd, buffer, size);
	return (buffer);
}

