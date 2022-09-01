/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_print_uint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:04:17 by khestia           #+#    #+#             */
/*   Updated: 2022/01/11 13:04:19 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_right_uint(char *s, t_print *tab, int len, char c)
{
	int	i;

	i = 0;
	while (tab->wdt > tab->prc && tab->wdt > len)
	{
		tab->total += write(1, &c, 1);
		tab->wdt--;
	}
	if (tab->prc > len)
	{
		while (tab->prc != len)
		{
			tab->total += write(1, "0", 1);
			tab->prc--;
		}
	}
	while (s[i])
	{
		tab->total += write(1, &s[i], 1);
		i++;
	}
}

void	ft_left_uint(char *s, t_print *tab, int len, char c)
{
	int	i;
	int	a;

	i = 0;
	a = tab->prc;
	while (tab->prc > len)
	{
		tab->total += write(1, "0", 1);
		tab->prc--;
	}
	while (s[i])
	{
		tab->total += write(1, &s[i], 1);
		i++;
	}
	while (tab->wdt > a && tab->wdt > len)
	{
		tab->total += write(1, &c, 1);
		tab->wdt--;
	}
}

char	ft_getchar_p(unsigned long i)
{
	if (i <= 9)
		return (i + '0');
	else if (i == 10)
		return ('a');
	else if (i == 11)
		return ('b');
	else if (i == 12)
		return ('c');
	else if (i == 13)
		return ('d');
	else if (i == 14)
		return ('e');
	else
		return ('f');
}

void	ft_lenp(t_print *tab, unsigned long p)
{
	while (p >= 16)
	{
		p = p / 16;
		tab->len++;
	}
	tab->len++;
}

char	ft_getchar(unsigned int i)
{
	if (i <= 9)
		return (i + '0');
	else if (i == 10)
		return ('a');
	else if (i == 11)
		return ('b');
	else if (i == 12)
		return ('c');
	else if (i == 13)
		return ('d');
	else if (i == 14)
		return ('e');
	else
		return ('f');
}
