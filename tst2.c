/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsousa-a <jsousa-a@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:29:20 by jsousa-a          #+#    #+#             */
/*   Updated: 2022/12/05 01:30:19 by jsousa-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft(void)
{
	static int	a = -1;

	a++;
	return (a);
}

int	main(void)
{
	printf("%i\n", ft());
	printf("%i\n", ft());
	printf("%i\n", ft());
	printf("%i\n", ft());
}
