/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:23:20 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/01/14 18:02:09 by jsousa-a         ###   ########.fr       */
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

	if (ct < 2)
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
	while (str && str[i])
		i++;
	return (i);
}
char *g_strdup(char *str)
{
	char	*cpy;
	int		i;
	int		len;

//									printf("---strdup STR = %s\n", str);
	if (!str)
		return (NULL);
	i = 0;
	len = g_strlen(str);
	if (len < 1)
		return (NULL);
	cpy = g_calloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
//	free(str);
//									printf("strdup CPY = %s\n", cpy);
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

	if (!buffer || read_ct < 1)
		return (sttc_str);
	i[0] = 0;
	i[1] = 0;
	newstr = g_calloc(sizeof(char) * g_strlen(sttc_str) + read_ct + 1);
	if (!newstr)
		return (NULL);
	while (sttc_str && sttc_str[i[0]])
	{
		newstr[i[0]] = sttc_str[i[0]];
		i[0]++;
	}
	while (i[1] < read_ct)
		newstr[i[0]++] = buffer[i[1]++];
	if (sttc_str)
		sttc_str = g_free(sttc_str);
//										printf("******G_CAT RESULT : %s******\n", newstr);
	return (newstr);
}
char	*g_cut_from_n(char *str)
{
	char	*temp;
	int	i;
	int	j;
	int len;

//									printf("^^^start of g_cut_from^^^\n");
	if (!str)
		return (NULL);
	i = g_check_n(str) + 1;
	len = g_strlen(str);
	if (i < len)
		temp = g_calloc(sizeof(char) * (len + 1 - i));
	else
		return (NULL);
	if (!temp)
		return (NULL);
	j = 0;
	while (i < len)
		temp[j++] = str[i++];
//									printf("str = %s\n", str);
//									printf("test\n");
//									write(1, &temp[0], 1);
//								printf("g_cut from before free\n");
	return (temp);
}
char	*g_cut_to_n(char *str)
{
	char	*newstr;
	int		i[2];
//										printf("---start of g_cut_to---\n");
//										printf("---sttc value at g_cut_to : %s---\n", str);
	if (!str || !*str)
		return (NULL);
	i[0] = g_check_n(str);
	if (i[0] < g_strlen(str))
		newstr = g_calloc(sizeof(char) * (i[0] + 2));
	else
		return (NULL);
	if (!newstr)
		return (NULL);
	i[1] = -1;
	while (++i[1] <= i[0])
		newstr[i[1]] = str[i[1]];
//	free(str);
//										printf("---g_cut_to result : %s\n", newstr);
	return (newstr);
}
char	*get_line(int fd, char *sttc_str)
{
	char		*buffer;
	ssize_t		read_ct;

	read_ct = BUFFER_SIZE;
	buffer = g_calloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (read_ct == BUFFER_SIZE && g_check_n(sttc_str) < 0)
	{
		read_ct = read(fd, buffer, BUFFER_SIZE);
		if (read_ct == -1)
		{
			free(buffer);
			free(sttc_str);
			return (NULL);
		}
		if (read_ct > 0)
			sttc_str = g_cat(sttc_str, buffer, read_ct);
	}
	free (buffer);
	if (sttc_str && *sttc_str)
		return (sttc_str);
	return (NULL);
}
char	*get_next_line(int fd)
{
	static char	*sttc_str;
	char		*to_ret;
	char		*temp;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	sttc_str = get_line(fd, sttc_str);
	if (!sttc_str)
		return (NULL);
	else if (g_check_n(sttc_str) >= 0)
	{
		to_ret = g_cut_to_n(sttc_str);
		temp = g_cut_from_n(sttc_str);
		free(sttc_str);
		sttc_str = temp;
	}
	else
		to_ret = g_strdup(sttc_str);
	return (to_ret);
}
/*int	main(void)
{
//	char *str1;
//	str1 = g_calloc(1);
	char *str2;
	str2 = g_calloc(6);
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
