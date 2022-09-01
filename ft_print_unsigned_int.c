/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:34:40 by khestia           #+#    #+#             */
/*   Updated: 2022/01/11 13:34:41 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_count_ch(unsigned int n)
{
	unsigned int	n1;
	unsigned int	i;

	i = 0;
	n1 = n;
	if (n1 == 0)
		return (1);
	while (n1 != 0)
	{
		i++;
		n1 = n1 / 10;
	}
	return (i);
}

static char	*ft_mi(char *s, unsigned int i, unsigned int j, unsigned int n)
{
	s[i] = '\0';
	while (i > j)
	{
		s[i - 1] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (s);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int		i;
	unsigned int		j;
	char				*s;

	j = 0;
	i = ft_count_ch(n);
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	else
		s = ft_mi(s, i, j, n);
	return (s);
}

void	ft_print_unsigned_int(t_print *tab)
{
	unsigned int	i;
	int				len;
	char			*s;
	char			c;

	i = va_arg(tab->args, unsigned int);
	s = ft_uitoa(i);
	len = ft_strlen(s);
	if ((tab->zero != 0 && tab->dash != 0) || (tab->dot != 0 && tab->zero != 0))
		tab->zero = 0;
	if (tab->zero != 0)
		c = '0';
	else
		c = ' ';
	if (i == 0)
		ft_null_int(tab, c);
	else
	{
		if (tab->dash != 0)
			ft_left_uint(s, tab, len, c);
		else
			ft_right_uint(s, tab, len, c);
	}
	free(s);
}
