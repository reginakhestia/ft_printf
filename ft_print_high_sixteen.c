/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_high_sixteen.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:05:07 by khestia           #+#    #+#             */
/*   Updated: 2022/01/11 13:30:58 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_else(t_print *tab, char c, unsigned int x)
{
	ft_len(tab, x);
	tab->total += tab->len;
	if (tab->sharp)
		tab->wdt -= 2;
	if (tab->len >= tab->wdt && tab->len >= tab->prc)
	{
		if (tab->sharp)
			tab->total += write(1, "0X", 2);
		ft_convert_h(x, tab);
	}
	else if (tab->dash != 0)
		ft_left_six_h(x, tab, c);
	else
		ft_right_six_h(x, tab, c);
}

void	ft_print_high_sixteen(t_print *tab)
{
	unsigned int	x;
	char			c;

	x = va_arg(tab->args, unsigned int);
	if ((tab->zero != 0 && tab->dash != 0) || (tab->zero != 0 && tab->dot != 0))
		tab->zero = 0;
	if (tab->zero != 0 && tab->dot == 0)
		c = '0';
	else
		c = ' ';
	if (!x)
		ft_null_int(tab, c);
	else
		ft_else(tab, c, x);
}

void	ft_right_six_h(unsigned int x, t_print *tab, char c)
{
	while (tab->wdt > tab->len && tab->wdt > tab->prc)
	{
		tab->total += write(1, &c, 1);
		tab->wdt--;
	}
	if (tab->sharp)
		tab->total += write(1, "0X", 2);
	if (tab->prc > tab->len)
	{
		while (tab->prc - tab->len > 0)
		{
			tab->total += write(1, "0", 1);
			tab->prc--;
		}
	}
	ft_convert_h(x, tab);
}

void	ft_left_six_h(unsigned int x, t_print *tab, char c)
{
	int	i;

	i = 0;
	if (tab->sharp)
	{
		tab->total += write(1, "0X", 2);
	}
	if (tab->prc > tab->len)
	{
		while (tab->prc - tab->len > 0)
		{
			tab->total += write(1, "0", 1);
			tab->prc--;
			i++;
		}
	}
	ft_convert_h(x, tab);
	i += tab->len;
	while (tab->wdt - i > 0)
	{
		tab->total += write(1, &c, 1);
		tab->wdt--;
	}
}

void	ft_convert_h(unsigned int x, t_print *tab)
{
	unsigned int	del;
	unsigned int	c1;
	char			c;

	del = x / 16;
	if (x > 0)
	{
		ft_convert_h(del, tab);
		c1 = x % 16;
		c = ft_getchar_h(c1);
		write(1, &c, 1);
	}
	else if (del != 0 && del < 16)
	{
		c = ft_getchar_h(del);
		write(1, &c, 1);
	}
	else
		return ;
}
