/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:23:20 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/01/15 11:14:53 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
char *g_free(char *str)
{
	free(str);
	return (NULL);
}

char	*g_calloc(int ct)
{
	char	*ptr;
	int		i;

	if (ct < 1)
		return (NULL);
	ptr = malloc(ct);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < ct)
		ptr[i++] = 0;
	return (ptr);
}
int	g_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int	g_check_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}
char	*get_next_line(int fd)
{
	static char	*sttc_str;
	char		*to_ret;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	sttc_str = get_line(fd, sttc_str);
	if (!sttc_str)
		return (NULL);
}
