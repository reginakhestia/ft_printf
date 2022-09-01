/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:04:39 by khestia           #+#    #+#             */
/*   Updated: 2022/01/11 13:04:41 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	if (tab->dash == 0)
	{
		while (tab->wdt - 1 > 0)
		{
			tab->total += write(1, " ", 1);
			tab->wdt--;
		}
	}
	tab->total += write(1, &c, 1);
	if (tab->dash != 0)
	{
		while (tab->wdt - 1 > 0)
		{
			tab->total += write(1, " ", 1);
			tab->wdt--;
		}
	}
}
