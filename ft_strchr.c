/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:35:36 by khestia           #+#    #+#             */
/*   Updated: 2022/01/11 13:35:37 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	ch = (char)c;
	while (i != ft_strlen(str) + 1 && str[i] != ch && str[i])
		i++;
	if (str[i] == ch)
		return (&str[i]);
	else
		return (NULL);
}
