/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:24:23 by jsousa-a          #+#    #+#             */
/*   Updated: 2022/12/04 14:35:34 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
//TODO buffer size to remove
					#define BUFFER_SIZE 3
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
//TODO all includes below to remove

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*get_next_line(int fd);

#endif
