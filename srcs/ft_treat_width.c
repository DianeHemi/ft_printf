/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 15:26:20 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/29 13:27:01 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_treat_width(t_printf *flags, int min, int has_zero)
{
	int char_count;
	int len;

	char_count = 0;
	len = flags->width;
	if ((flags->dot >= len && flags->conv != '%')
			|| len == 0 || min == len || len < min)
		return (char_count);
	while (len > min)
	{
		if (has_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len--;
		char_count++;
	}
	return (char_count);
}

int		ft_assembly(t_printf *flags, char *str)
{
	int char_count;
	int len;
	int dot;

	char_count = 0;
	len = ft_strlen(str);
	dot = flags->dot;
	if (flags->dot > 0)
	{
		while (dot > 0 && dot > len)
		{
			char_count = ft_write_input('0', char_count);
			dot--;
		}
		char_count = ft_putstr(str, char_count);
		return (char_count);
	}
	else if (flags->width > 0 && str[0] == '0' && flags->dot == 0)
		char_count = ft_write_input(' ', char_count);
	else
		char_count = ft_putstr(str, char_count);
	return (char_count);
}
