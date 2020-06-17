/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:54:23 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/17 15:51:40 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int		ft_parse_flags(va_list args, char *input, int i, t_printf *flags)
{
	while (ft_strchr(ALLSYMBOLS, input[i]))
	{
		if (input[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (input[i] == '-')
			ft_flag_minus(flags);
		if (ft_strchr("0123456789", input[i]) && flags->dot == -1)
			ft_flag_digit(flags, input[i]);
		if (input[i] == '*' && flags->dot == -1)
			ft_flag_width(args, flags);
		if (input[i] == '.')
			i = ft_flag_dot(input, i, flags, args);
		if (ft_strchr("cspdiuxX%", input[i]))
		{
			flags->conv = input[i];
			if ((flags->dot > 0 && ft_strchr("diuxX", flags->conv)))
				flags->zero = 0;
			break ;
		}
		i++;
	}
	return (i);
}

int		ft_parse_conv(va_list args, t_printf *flags)
{
	int char_count;

	char_count = 0;
	if (flags->conv == 'c')
		char_count = ft_treat_char(args, char_count, flags);
	else if (flags->conv == 's')
		char_count = ft_treat_str(args, flags, char_count);
	else if (flags->conv == 'p')
		char_count = ft_treat_ptr(args, flags, char_count);
	else if (flags->conv == 'd' || flags->conv == 'i')
		char_count = ft_treat_int(args, flags, char_count);
	else if (flags->conv == 'u')
		char_count = ft_treat_uint(args, flags, char_count);
	else if (flags->conv == 'x')
		char_count = ft_treat_hexa(args, flags, char_count, 1);
	else if (flags->conv == 'X')
		char_count = ft_treat_hexa(args, flags, char_count, 0);
	else if (flags->conv == '%')
		char_count = ft_treat_perct(flags, char_count);
	return (char_count);
}
