/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:40:28 by dchampda          #+#    #+#             */
/*   Updated: 2020/05/25 18:40:40 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_treat_char(va_list args, int char_count, t_printf *flags)
{
	char c;

	c = va_arg(args, int);
	if (flags->minus == 1)
	{
		ft_putchar(c);
		if (flags->width > 1)
			char_count+= ft_treat_width(flags, 1 , 0);
	}
	else
	{
		if (flags->width > 1)
			char_count += ft_treat_width(flags, 1 , 0);
		ft_putchar(c);
	}
	return (char_count + 1);
}
