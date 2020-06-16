/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:46:09 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/10 15:34:52 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define ALLSYMBOLS "cspdiuxX%0123456789.-*"

typedef struct	s_printf
{

	int		minus;
	int		zero;
	int		width;
	int		dot;
	int		star;
	int		perct;
	char	conv;
}				t_printf;

int				ft_printf(const char *input, ...);
int				ft_read_input(va_list args, const char *input);

void			ft_init_flags(t_printf *flags);
int				ft_parse_flags(va_list args, char *input, int i,
			t_printf *flags);
int				ft_parse_conv(va_list args, t_printf *flags);

void			ft_flag_minus(t_printf *flags);
int				ft_flag_dot(char *input, int pos, t_printf *flags,
			va_list args);
int				ft_flag_digit(t_printf *flags, char c);
void			ft_flag_width(va_list args, t_printf *flags);

int				ft_treat_char(va_list args, int char_count, t_printf *flags);
int				ft_treat_str(va_list args, t_printf *flags, int char_count);
int				ft_treat_int(va_list args, t_printf *flags, int char_count);
int				ft_treat_uint(va_list args, t_printf *flags, int char_count);
int				ft_treat_perct(t_printf *flags, int char_count);
int				ft_treat_ptr(va_list args, t_printf *flags, int char_count);
int				ft_treat_hexa(va_list args, t_printf *flags,
			int char_count, int type);

int				ft_treat_width(t_printf *flags, int min, int has_zero);
int				ft_assembly(t_printf *flags, char *str);

char			*ft_strndup(const char *s, int len);
void			ft_putchar(char c);
int				ft_putstr(char *str, int char_count);
char			*ft_str_tolower(char *str);
int				ft_putnbr(int nb, int char_count);
int				ft_put_unbr(unsigned int nb, int char_count);
char			*ft_ull_base(unsigned long long nb, int base);
char			*ft_conv_base(char	*str, int len, unsigned long long nb,
			int base);
char			*ft_uitoa(unsigned int n);
int				ft_write_input(char c, int char_count);

#endif
