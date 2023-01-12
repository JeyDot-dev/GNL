/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:24:23 by jsousa-a          #+#    #+#             */
/*   Updated: 2023/01/12 22:05:09 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
//TODO buffer size to remove
//# define BUFFER_SIZE 100000000
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
//TODO all includes below to remove

# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*get_next_line(int fd);

#endif
