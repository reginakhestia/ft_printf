/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:03:38 by khestia           #+#    #+#             */
/*   Updated: 2022/01/11 13:10:00 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	ft_getchar_h(unsigned int i)
{
	if (i <= 9)
		return (i + '0');
	else if (i == 10)
		return ('A');
	else if (i == 11)
		return ('B');
	else if (i == 12)
		return ('C');
	else if (i == 13)
		return ('D');
	else if (i == 14)
		return ('E');
	else
		return ('F');
}
