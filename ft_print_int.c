/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:11:03 by khestia           #+#    #+#             */
/*   Updated: 2022/01/11 13:25:37 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_null_int(t_print *tab, char c)
{
	int	i;

	i = tab->prc;
	if (tab->plus)
		tab->total += write(1, "+", 1);
	if (tab->spase && !tab->plus)
		tab->total += write(1, " ", 1);
	if (tab->dot == 0)
		tab->wdt--;
	while (tab->wdt > tab->prc && tab->dash == 0)
	{
		tab->total += write(1, &c, 1);
		tab->wdt--;
	}
	while (tab->prc)
	{
		tab->total += write(1, "0", 1);
		tab->prc--;
	}
	if (tab->dot == 0)
		tab->total += write(1, "0", 1);
	while (tab->wdt-- > i && tab->dash != 0)
		tab->total += write(1, &c, 1);
}

void	ft_print_int(t_print *tab)
{
	int		i;
	int		lentotal;
	char	*s;
	char	c;

	i = va_arg(tab->args, int);
	if (tab->zero != 0 && tab->dash != 0)
		tab->zero = 0;
	if (tab->zero != 0 && tab->dot != 0)
		tab->zero = 0;
	if (tab->zero != 0 && tab->dot == 0)
		c = '0';
	else
		c = ' ';
	if (i == 0)
		ft_null_int(tab, c);
	else
	{
		s = ft_itoa(i);
		lentotal = ft_strlen(s);
		if (tab->dash != 0)
			ft_left_int(s, tab, lentotal, c);
		else
			ft_right_int(s, tab, lentotal, c);
	}
}

static void	ft_right_int_minus(char *s, t_print *tab, int lentotal, char c)
{
	if (c == ' ')
	{
		while (tab->wdt > lentotal && tab->wdt > tab->prc + 1)
		{
			tab->total += write(1, &c, 1);
			tab->wdt--;
		}
	}
	if (s[0] == '-')
		tab->total += write(1, "-", 1);
	if (c == '0')
	{
		while (tab->wdt > lentotal && tab->wdt > tab->prc + 1)
		{
			tab->total += write(1, &c, 1);
			tab->wdt--;
		}
	}
	while (tab->prc > lentotal - 1)
	{
		tab->total += write(1, "0", 1);
		tab->prc--;
	}
	ft_putint(s, tab);
}

void	ft_right_int(char *s, t_print *tab, int lentotal, char c)
{
	if (s[0] == '-')
		ft_right_int_minus(s, tab, lentotal, c);
	else
	{
		if (tab->plus)
			tab->total += write(1, "+", 1);
		if (tab->spase && !tab->plus)
			tab->total += write(1, " ", 1);
		while (tab->wdt > lentotal && tab->wdt > tab->prc)
		{
			tab->total += write(1, &c, 1);
			tab->wdt--;
		}
		while (tab->prc > lentotal)
		{
			tab->total += write(1, "0", 1);
			tab->prc--;
		}
		ft_putint(s, tab);
	}
}

void	ft_left_int(char *s, t_print *tab, int lentotal, char c)
{
	int	i;

	i = 0;
	if (s[0] == '-')
	{
		tab->total += write(1, "-", 1);
		tab->prc++;
	}
	if (s[0] != '-' && tab->plus)
	{
		tab->total += write(1, "+", 1);
		tab->prc++;
	}
	if (s[0] != '-' && tab->spase && !tab->plus)
	{
		tab->total += write(1, " ", 1);
		tab->prc++;
	}
	while (tab->prc-- > lentotal && ++i)
		tab->total += write(1, "0", 1);
	ft_putint(s, tab);
	while (tab->wdt-- > lentotal + i)
		tab->total += write(1, &c, 1);
}
