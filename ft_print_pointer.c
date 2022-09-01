/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:26:25 by khestia           #+#    #+#             */
/*   Updated: 2022/01/11 13:26:27 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_null_p(t_print *tab)
{
	int	i;

	i = 2;
	if (tab->dot == 0)
		i = 3;
	if (tab->dash != 0)
	{
		tab->total += write(1, "0x", 2);
		if (tab->dot == 0)
			tab->total += write(1, "0", 1);
	}
	while (tab->wdt > i)
	{
		tab->total += write(1, " ", 1);
		tab->wdt--;
	}
	if (tab->dash == 0)
	{
		tab->total += write(1, "0x", 2);
		if (tab->dot == 0)
			tab->total += write(1, "0", 1);
	}
}

void	ft_print_pointer(t_print *tab)
{
	unsigned long	p;

	p = (unsigned long)va_arg(tab->args, void *);
	if (!p)
		ft_null_p(tab);
	else
	{
		ft_lenp(tab, p);
		tab->total += tab->len + 2;
		if (tab->dash != 0)
			ft_pointer_left(tab, p);
		else
			ft_pointer_right(tab, p);
	}
}

void	ft_pointer_left(t_print *tab, unsigned long p)
{
	write(1, "0x", 2);
	ft_convert_p(p, tab);
	while (tab->wdt > tab->len + 2)
	{
		tab->total += write(1, " ", 1);
		tab->wdt--;
	}
}

void	ft_pointer_right(t_print *tab, unsigned long p)
{
	while (tab->wdt > tab->len + 2)
	{
		tab->total += write(1, " ", 1);
		tab->wdt--;
	}
	write(1, "0x", 2);
	ft_convert_p(p, tab);
}

void	ft_convert_p(unsigned long p, t_print *tab)
{
	unsigned long	del;
	unsigned long	c1;
	char			c;

	del = p / 16;
	if (p > 0)
	{
		ft_convert_p(del, tab);
		c1 = p % 16;
		c = ft_getchar_p(c1);
		write(1, &c, 1);
	}
	else if (del != 0 && del < 16)
	{
		c = ft_getchar_p(del);
		write(1, &c, 1);
	}
	else
		return ;
}
