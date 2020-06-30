/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:00:10 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/10 14:01:00 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_flag_minus(t_printf *flags)
{
	flags->minus = 1;
	flags->zero = 0;
}

int		ft_flag_dot(char *input, int pos, t_printf *flags, va_list args)
{
	int i;

	i = pos + 1;
	if (input[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_strchr("0123456789", input[i]))
		{
			flags->dot = (flags->dot * 10) + (input[i] - '0');
			i++;
		}
	}
	return (i);
}

int		ft_flag_digit(t_printf *flags, char c)
{
	if (flags->star == 1)
		return (0);
	flags->width = (flags->width * 10) + (c - '0');
	return (1);
}

void	ft_flag_width(va_list args, t_printf *flags)
{
	flags->star = 1;
	flags->width = va_arg(args, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->zero = 0;
		flags->width *= -1;
	}
}
