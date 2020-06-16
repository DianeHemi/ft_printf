/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:02:17 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/10 15:35:46 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_str_tolower(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

static int	ft_hexa_errors(t_printf *flags, unsigned int nb, int *char_count)
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
			*char_count = ft_write_input(' ', *char_count);
			return (1);
		}
	}
	if (flags->dot == 0 && nb == 0 && flags->width > 0)
	{
		while (flags->width > 0)
		{
			*char_count = ft_write_input(' ', *char_count);
			flags->width--;
		}
		return (1);
	}
	return (0);
}

int			ft_treat_hexa(va_list args, t_printf *flags,
		int char_count, int type)
{
	char			*hexa;
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	if (ft_hexa_errors(flags, nb, &char_count))
		return (char_count);
	if (flags->dot < 0)
		flags->dot = 0;
	hexa = ft_ull_base(nb, 16);
	if (type == 1)
		hexa = ft_str_tolower(hexa);
	if (flags->dot >= 0 && (size_t)flags->dot < ft_strlen(hexa))
		flags->dot = ft_strlen(hexa);
	if (flags->minus == 1)
		char_count += ft_assembly(flags, hexa);
	char_count += ft_treat_width(flags, flags->dot, flags->zero);
	if (flags->minus == 0)
		char_count += ft_assembly(flags, hexa);
	free(hexa);
	return (char_count);
}
