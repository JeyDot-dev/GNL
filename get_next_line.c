/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:23:20 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/01/11 08:18:13 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
int	g_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
char *g_strdup_free(char *str)
{
	char	*cpy;
	int		i;
	int		len;

									printf("---STR = %s\n", str);
	if (!str || !*str)
		return (NULL);
	i = 0;
	len = g_strlen(str);
	cpy = malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = 0;
	free(str);
									printf("CPY = %s\n", cpy);
	return (cpy);
}
int	g_check_n(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);

}
char *g_cat(char *sttc_str, char *buffer, int read_ct)
{
	int		i[2];
	char	*newstr;

	if (read_ct == -42)
	{
//		if (*sttc_str == 0)
//			return (NULL);
		read_ct = 0;
	}
	else if (read_ct < 1 || !buffer)
		return (sttc_str);
	i[0] = -1;
	i[1] = 0;
	newstr = malloc(sizeof(char) * g_strlen(sttc_str) + read_ct + 1);
	if (!newstr)
		return (NULL);
	while (sttc_str && sttc_str[++i[0]])
		newstr[i[0]] = sttc_str[i[0]];
	while (i[1] < read_ct)
		newstr[i[0]++] = buffer[i[1]++];
	newstr[i[0]] = 0;
	if (sttc_str)
		free(sttc_str);
	return (newstr);
}
char	*g_cut_from_n(char *str)
{
	char	*temp;
	int	i;
	int	j;
	int len;

	if (!str)
		return (NULL);
	i = g_check_n(str) + 1;
	len = g_strlen(str);
	temp = malloc(sizeof(char) * (len + 1 - i));
	if (!temp)
		return (NULL);
	j = 0;
	while (i < len)
		temp[j++] = str[i++];
	temp[j] = 0;
	free(str);
	return (temp);
}
char	*g_cut_to_n(char *str)
{
	char	*newstr;
	int		i[2];

	if (!str)
		return (NULL);
	i[0] = g_check_n(str);
	newstr = malloc(sizeof(char) * (i[0] + 2));
	if (!newstr)
		return (NULL);
	i[1] = -1;
	while (++i[1] <= i[0])
		newstr[i[1]] = str[i[1]];
	newstr[i[1]] = 0;
	return (newstr);
}

char	*get_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*sttc_str;
	char		*str_return;
	int			read_ct;

	if (!sttc_str)
		sttc_str = malloc(1);
	if (!sttc_str)
		return (NULL);
	read_ct = BUFFER_SIZE;
	if (sttc_str && g_check_n(sttc_str) >= 0)
	{
		str_return = g_cut_to_n(sttc_str);
		sttc_str = g_cut_from_n(sttc_str);
		return (str_return);
	}
	while (read_ct == BUFFER_SIZE)
	{
		read_ct = read(fd, buffer, BUFFER_SIZE);
		if (read_ct > 0)
			sttc_str = g_cat(sttc_str, buffer, read_ct);
		if (read_ct < BUFFER_SIZE && g_check_n(sttc_str) >= 0)
			return (g_strdup_free(sttc_str));
	}
	if (sttc_str && *sttc_str)
	{
		return (g_strdup_free(sttc_str));
	}
	if (sttc_str)
		free(sttc_str);
	return (NULL);
}
char	*get_next_line(int fd)
{
	char	*s_return;

	if (BUFFER_SIZE < 1 || fd < 1)
		return (NULL);
	s_return = get_line(fd);
	if (!s_return)
		return (NULL);
	return (s_return);

}

/*int	main(void)
{
//	char *str1;
//	str1 = malloc(1);
	char *str2;
	str2 = malloc(6);
	str2[0] = 'X';
	str2[1] = 'A';
	str2[2] = '\n';
	str2[3] = 'A';
	str2[4] = 'X';
	str2[5] = 0;
	str2 = g_cut_to_n(str2);
	str2 = g_cat(str2, str2, 3);
	printf("%s", str2);
}*/
