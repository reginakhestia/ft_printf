/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:35:00 by khestia           #+#    #+#             */
/*   Updated: 2022/01/11 13:35:05 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_init_tab(t_print *tab)
{
	tab->type = '0';
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->dot = 0;
	tab->dash = 0;
	tab->perc = 0;
	tab->total = 0;
	tab->len = 0;
	tab->plus = 0;
	tab->spase = 0;
	tab->sharp = 0;
	return (tab);
}

int	ft_mini_atoi(const char *s, int i)
{
	int	num;

	num = 0;
	while (ft_isdigit(s[i]) != 0)
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}
	return (num);
}

void	ft_type(t_print *tab, const char *s, int i)
{
	if (tab->prc < 0)
	{
		tab->prc = 0;
		tab->dot = 0;
	}
	if (s[i] == '%')
		ft_print_perc(tab);
	else if (ft_strchr("cspdiuxX", s[i]) != 0)
		ft_get_type(tab, s, i);
	ft_reset_tab(tab);
}

int	ft_flags(t_print *tab, const char *s, int i)
{
	while (!ft_strchr("cspdiuxX%", s[i]) && s[i] != '.')
	{
		ft_get_before(tab, s, i);
		i++;
	}
	while (!ft_strchr("cspdiuxX%", s[i]))
	{
		if (s[i] == '.')
			tab->dot = 1;
		else if (ft_isdigit(s[i]) != 0 && tab->prc == 0)
			tab->prc = ft_mini_atoi(s, i);
		else if (ft_isdigit(s[i]) != 0 && tab->prc != 0)
			tab->len = 0;
		else if (s[i] == '*')
			tab->prc = va_arg(tab->args, int);
		i++;
	}
	ft_type(tab, s, i);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	t_print	*tab;
	int		i;
	int		res;

	i = -1;
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_init_tab(tab);
	va_start(tab->args, s);
	while (s[++i])
	{
		if (s[i] == '%')
			i = ft_flags(tab, s, i + 1);
		else
			tab->total += write(1, &s[i], 1);
	}
	va_end(tab->args);
	res = tab->total;
	free (tab);
	return (res);
}
