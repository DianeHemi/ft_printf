/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:55:41 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/17 15:48:44 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_init_flags(t_printf *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->dot = -1;
	flags->star = 0;
	flags->perct = 0;
	flags->conv = 0;
}

int		ft_read_input(va_list args, const char *input, int char_count)
{
	int			i;
	t_printf	*flags;

	i = 0;
	if (!(flags = (t_printf*)malloc(sizeof(t_printf))))
		return (-1);
	while (input[i])
	{
		if (input[i] != '%')
			char_count = ft_write_input(input[i], char_count);
		else if (input[i] == '%' && input[i + 1])
		{
			ft_init_flags(flags);
			i = ft_parse_flags(args, (char *)input, ++i, flags);
			if (flags->conv == 0)
				break ;
			if (ft_strchr("cspdiuxX%", input[i]))
				char_count += ft_parse_conv(args, flags);
			else if (input[i])
				char_count = ft_write_input(input[i], char_count);
		}
		i++;
	}
	free(flags);
	return (char_count);
}

int		ft_printf(const char *input, ...)
{
	va_list		args;
	int			char_count;

	char_count = 0;
	if (!input)
		return (-1);
	va_start(args, input);
	char_count = ft_read_input(args, input, char_count);
	va_end(args);
	return (char_count);
}
