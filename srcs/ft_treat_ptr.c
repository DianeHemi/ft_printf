/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:51:33 by dchampda          #+#    #+#             */
/*   Updated: 2020/05/25 18:51:38 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"



static int	ft_ptr_assembly(t_printf *flags, char *str)
{
	int char_count;
	int len;
	int dot;

	char_count = 0;
	char_count = ft_putstr("0x", char_count);
	if (flags->width > 0 && flags->zero == 1 && flags->dot < 0)
	{
		char_count = ft_putstr(str, char_count);
		return (char_count);
	}
	len = ft_strlen(str) + 2;
	dot = flags->dot;
	if (flags->dot > 0)
	{
		while (dot > 0 && dot > len)
		{
			ft_putchar('0');
			char_count++;
			dot--;
		}
		char_count = ft_putstr(str, char_count);
		return (char_count);
	}
	else if (flags->width > 0 && str[0] == '0' && flags->dot == 0)
	{
		ft_putchar('0');
		char_count++;
	}
	else
		char_count = ft_putstr(str, char_count);
	return (char_count);
}


static int	ft_ptr_errors(t_printf *flags, int ptr, int *char_count)
{
	if (flags->dot == 0 && ptr == 0)
	{
		*char_count = ft_putstr("0x", *char_count);
		*char_count += ft_treat_width(flags, flags->dot + 2, 1);
		return (1);
	}
	return (0);
}

int			ft_treat_ptr(va_list args, t_printf *flags, int char_count)
{
	unsigned long	ptr;
	char			*str;

	ptr = va_arg(args, unsigned long long);
	if (ft_ptr_errors(flags, ptr, &char_count))
		return (char_count);
	if (flags->dot < 0)
		flags->dot = 0;
	str = ft_ull_base(ptr, 16);
	str = ft_str_tolower(str);
	if (flags->dot >= 0 && (size_t)flags->dot < ft_strlen(str))
		flags->dot = ft_strlen(str);
	if (flags->minus == 1)
		char_count += ft_ptr_assembly(flags, str);
	char_count += ft_treat_width(flags, flags->dot + 2, flags->zero);		
	if (flags->minus == 0)
		char_count += ft_ptr_assembly(flags, str);
	free(str);
	return (char_count);
}
