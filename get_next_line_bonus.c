/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:46:10 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/01/17 14:57:32 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*g_getline(char *sttc_str)
{
	char	*line;
	int		n_ct;
	int		len;
	int		i;

	if (!sttc_str || !*sttc_str)
		return (NULL);
	n_ct = g_check_n(sttc_str);
	len = g_strlen(sttc_str);
	if (n_ct >= 0)
		line = g_calloc(sizeof(char) * (n_ct + 2));
	else
		line = g_calloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (sttc_str[i])
	{
		line[i] = sttc_str[i];
		if (sttc_str[i] == '\n')
			break ;
		i++;
	}
	return (line);
}

char	*g_trim(char *sttc_str)
{
	int		from_n;
	int		i;
	char	*cpy;

	if (!sttc_str)
		return (NULL);
	if (*sttc_str == 0)
		return (g_free(sttc_str));
	from_n = g_check_n(sttc_str) + 1;
	i = g_strlen(sttc_str);
	if ((from_n >= 1 && (i - from_n) > 0))
		cpy = g_calloc(sizeof(char) * (i - from_n + 1));
	else
		return (g_free(sttc_str));
	if (!cpy)
		return (g_free(sttc_str));
	i = 0;
	while (sttc_str[from_n])
		cpy[i++] = sttc_str[from_n++];
	free(sttc_str);
	return (cpy);
}

char	*g_cat(char *sttc_str, char *buffer, int ct_count)
{
	char	*cpy;
	int		i;
	int		j;
	int		len;

	if (ct_count < 1)
		return (sttc_str);
	len = g_strlen(sttc_str) + ct_count;
	cpy = g_calloc(len + 1);
	if (!cpy)
		return (sttc_str);
	i = 0;
	while (sttc_str[i])
	{
		cpy[i] = sttc_str[i];
		i++;
	}
	j = 0;
	while (i < len)
	{
		cpy[i++] = buffer[j++];
	}
	free(sttc_str);
	return (cpy);
}

char	*g_readfile(int fd, char *sttc_str)
{
	char	*buffer;
	int		ct_read;

	if (!sttc_str)
		sttc_str = g_calloc(1);
	if (!sttc_str)
		return (NULL);
	buffer = g_calloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (g_free(sttc_str));
	ct_read = BUFFER_SIZE;
	while (ct_read > 0)
	{
		ct_read = read(fd, buffer, BUFFER_SIZE);
		if (ct_read == -1)
		{
			free(buffer);
			return (g_free(sttc_str));
		}
		sttc_str = g_cat(sttc_str, buffer, ct_read);
		if (g_check_n(sttc_str) >= 0)
			break ;
	}
	free(buffer);
	return (sttc_str);
}

char	*get_next_line(int fd)
{
	static char	*sttc_str[4096];
	char		*to_ret;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	sttc_str[fd] = g_readfile(fd, sttc_str[fd]);
	if (!sttc_str[fd])
		return (NULL);
	to_ret = g_getline(sttc_str[fd]);
	sttc_str[fd] = g_trim(sttc_str[fd]);
	return (to_ret);
}
