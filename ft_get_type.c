/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:03:07 by khestia           #+#    #+#             */
/*   Updated: 2022/01/11 13:03:16 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_type(t_print *tab, const char *s, int i)
{
	tab->type = s[i];
	if (s[i] == 'c')
		ft_print_char(tab);
	if (s[i] == 's')
		ft_print_string(tab);
	if (s[i] == 'p')
		ft_print_pointer(tab);
	if (s[i] == 'd' || s[i] == 'i')
		ft_print_int(tab);
	if (s[i] == 'u')
		ft_print_unsigned_int(tab);
	if (s[i] == 'x')
		ft_print_sixteen(tab);
	if (s[i] == 'X')
		ft_print_high_sixteen(tab);
}

void	ft_get_before(t_print *tab, const char *s, int i)
{
	if (s[i] == '0' && !ft_strchr("1234567890", s[i - 1]))
		tab->zero = 1;
	else if (s[i] == '-')
		tab->dash = 1;
	else if (s[i] == '+')
		tab->plus = 1;
	else if (s[i] == ' ' && !tab->plus)
		tab->spase = 1;
	else if (s[i] == '#')
		tab->sharp = 1;
	else if (ft_isdigit(s[i]) != 0 && tab->wdt == 0)
		tab->wdt = ft_mini_atoi(s, i);
	else if (ft_isdigit(s[i]) != 0 && tab->wdt != 0)
		tab->len = 0;
	else if (s[i] == '*')
	{
		tab->wdt = va_arg(tab->args, int);
		if (tab->wdt < 0)
		{
			tab->wdt *= -1;
			tab->dash = 1;
		}
	}
}

void	ft_reset_tab(t_print *tab)
{
	tab->type = '0';
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->dot = 0;
	tab->dash = 0;
	tab->perc = 0;
	tab->len = 0;
	tab->plus = 0;
	tab->spase = 0;
	tab->sharp = 0;
}
