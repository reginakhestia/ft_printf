/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:34:21 by khestia           #+#    #+#             */
/*   Updated: 2022/01/11 13:34:22 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string(t_print *tab)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(tab->args, char *);
	if (!s)
	{
		s = "(null)";
		if (tab->dot == 0)
		{
			tab->dot = 1;
			tab->prc = 6;
		}
	}
	if (tab->dash != 0)
		ft_left_str(tab, s, i);
	if (tab->dash == 0)
		ft_right_str(tab, s, i);
}

void	ft_right_str(t_print *tab, char *s, int i)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	if (tab->prc < 0)
		tab->prc = len;
	if (tab->prc < len && tab->dot != 0)
		len = tab->prc;
	if (tab->wdt > len)
	{
		while (tab->wdt - len > 0)
		{
			tab->total += write(1, " ", 1);
			tab->wdt--;
		}
	}
	while (len)
	{
		tab->total += write(1, &s[i], 1);
		i++;
		len--;
	}
}

void	ft_left_str(t_print *tab, char *s, int i)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	if (tab->prc < 0)
		tab->prc = len;
	if (tab->prc < len && tab->dot != 0)
		len = tab->prc;
	while (i != len)
	{
		tab->total += write(1, &s[i], 1);
		i++;
	}
	if (tab->wdt > len)
	{
		while (tab->wdt != len)
		{
			tab->total += write(1, " ", 1);
			tab->wdt--;
		}
	}
}
