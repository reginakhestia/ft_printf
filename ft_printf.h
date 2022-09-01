/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khestia <khestia@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:35:17 by khestia           #+#    #+#             */
/*   Updated: 2022/01/11 13:35:19 by khestia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_print
{
	va_list	args;
	char	type;
	int		wdt;
	int		prc;
	int		zero;
	int		dot;
	int		dash;
	int		perc;
	int		total;
	int		len;
	int		spase;
	int		plus;
	int		sharp;
}	t_print;

t_print	*ft_init_tab(t_print *tab);
int		ft_mini_atoi(const char *s, int i);
int		ft_isdigit(int c);
void	ft_type(t_print *tab, const char *s, int i);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_flags(t_print *tab, const char *s, int i);
int		ft_printf(const char *s, ...);
void	ft_print_string(t_print *tab);
void	ft_right_str(t_print *tab, char *s, int i);
void	ft_left_str(t_print *tab, char *s, int i);
void	ft_print_sixteen(t_print *tab);
void	ft_len(t_print *tab, unsigned int x);
void	ft_convert(unsigned int x, t_print *tab);
char	ft_getchar(unsigned int i);
void	ft_print_high_sixteen(t_print *tab);
void	ft_convert_h(unsigned int x, t_print *tab);
char	ft_getchar_h(unsigned int i);
void	ft_print_char(t_print *tab);
void	ft_right_six(unsigned int x, t_print *tab, char c);
void	ft_left_six(unsigned int x, t_print *tab, char c);
void	ft_right_six_h(unsigned int x, t_print *tab, char c);
void	ft_left_six_h(unsigned int x, t_print *tab, char c);
char	*ft_itoa(int n);
void	ft_print_int(t_print *tab);
void	ft_right_int(char *s, t_print *tab, int lentotal, char c);
void	ft_left_int(char *s, t_print *tab, int lentotal, char c);
char	*ft_strdup(const char *s1);
char	*ft_uitoa(unsigned int n);
void	ft_right_uint(char *s, t_print *tab, int len, char c);
void	ft_left_uint(char *s, t_print *tab, int len, char c);
void	ft_print_pointer(t_print *tab);
void	ft_pointer_right(t_print *tab, unsigned long p);
void	ft_pointer_left(t_print *tab, unsigned long p);
void	ft_convert_p(unsigned long p, t_print *tab);
char	ft_getchar_p(unsigned long i);
void	ft_lenp(t_print *tab, unsigned long p);
void	ft_print_unsigned_int(t_print *tab);
void	ft_putint(char *s, t_print *tab);
void	ft_null_int(t_print *tab, char c);
void	ft_print_perc(t_print *tab);
void	ft_reset_tab(t_print *tab);
void	ft_get_type(t_print *tab, const char *s, int i);
void	ft_get_before(t_print *tab, const char *s, int i);
void	ft_len(t_print *tab, unsigned int x);

#endif
