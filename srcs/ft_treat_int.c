/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:52:17 by dchampda          #+#    #+#             */
/*   Updated: 2020/05/25 18:52:19 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_int_errors(t_printf *flags, int nb, int *char_count)
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

static int	ft_treat_neg(t_printf *flags, char *str, int char_count)
{
	if (flags->minus == 1)
	{
		ft_putchar('-');
		char_count++;
		char_count += ft_assembly(flags, str + 1);
		char_count += ft_treat_width(flags, (flags->dot + 1), flags->zero);
	}
	else if (flags->width > 0 && flags->zero && flags->dot <= 0)
	{
		ft_putchar('-');
		char_count++;
		char_count += ft_treat_width(flags, flags->dot, flags->zero);
		char_count += ft_assembly(flags, str + 1);
		return (char_count);
	}	
	else if (!flags->zero)
	{
		char_count += ft_treat_width(flags, flags->dot + 1, flags->zero);
		ft_putchar('-');
		char_count++;
		char_count += ft_assembly(flags, str + 1);
	}
	else
	{
		ft_putchar('-');
		char_count += ft_treat_width(flags, flags->dot + 1, flags->zero);
		char_count++;
		char_count += ft_assembly(flags, str + 1);
	}
	return (char_count);
}

int			ft_treat_int(va_list args, t_printf *flags, int char_count)
{
	int		nb;
	char 	*str;

	nb = va_arg(args, int);
	if (ft_int_errors(flags, nb, &char_count))
		return (char_count);
	if (flags->dot < 0)
		flags->dot = 0;
	str = ft_itoa(nb);
	if (nb < 0)
	{
		if ((size_t)flags->dot < ft_strlen(str) - 1)
			flags->dot = ft_strlen(str) - 1;
		char_count += ft_treat_neg(flags, str, char_count);
	}
	else
	{
		if ((size_t)flags->dot < ft_strlen(str))
			flags->dot = ft_strlen(str);
		if (flags->minus == 1)
			char_count += ft_assembly(flags, str);
		char_count += ft_treat_width(flags, flags->dot, flags->zero);
		if (flags->minus == 0)
			char_count += ft_assembly(flags, str);
	}
	free(str);
	return (char_count);
}
