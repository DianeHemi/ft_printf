/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 11:40:32 by dchampda          #+#    #+#             */
/*   Updated: 2020/05/26 11:40:34 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_uint_errors(t_printf *flags, unsigned int nb, int *char_count)
{
	if (flags->dot == 0 && nb == 0 && flags->width < 2)
	{
		if (flags->width < 1)
		{
			write(1, "", 0);
			return (1);
		}
		else
		{
			write(1, " ", 1);
			*char_count += 1;
			return (1);
		}
	}
	if (flags->dot == 0 && nb == 0 && flags->width > 0)
	{
		while (flags->width > 0)
		{
			ft_putchar(' ');
			*char_count += 1;
			flags->width--;
		}
		return (1);
	}
	return (0);
}

int			ft_treat_uint(va_list args, t_printf *flags, int char_count)
{
	int	tmp;
	unsigned int nb;
	char 		*str;

	tmp = va_arg(args, int);
	nb = (unsigned int)tmp;

	if (ft_uint_errors(flags, nb, &char_count))
		return (char_count);

	if (flags->dot < 0)
		flags->dot = 0;
	str = ft_uitoa(nb);
	if ((size_t)flags->dot < ft_strlen(str))
		flags->dot = ft_strlen(str);
	if (flags->minus == 1)
		char_count += ft_assembly(flags, str);
	char_count += ft_treat_width(flags, flags->dot, flags->zero);
	if (flags->minus == 0)
		char_count += ft_assembly(flags, str);
	free(str);
	return (char_count);
}
