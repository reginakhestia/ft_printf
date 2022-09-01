/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:26:07 by khestia           #+#    #+#             */
/*   Updated: 2022/01/11 13:26:10 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_perc(t_print *tab)
{
	char	c;

	if (tab->zero != 0 && tab->dash != 0)
		tab->zero = 0;
	if (tab->zero != 0)
		c = '0';
	else
		c = ' ';
	if (tab->dash == 0)
	{
		while (tab->wdt > 1)
		{
			tab->total += write(1, &c, 1);
			tab->wdt--;
		}
	}
	tab->total += write(1, "%", 1);
	if (tab->dash != 0)
	{
		while (tab->wdt > 1)
		{
			tab->total += write(1, &c, 1);
			tab->wdt--;
		}
	}
}
