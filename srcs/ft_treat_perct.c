/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_perct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:21:05 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/10 14:21:18 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_treat_perct(t_printf *flags, int char_count)
{
	if (flags->minus == 1)	
		char_count = ft_write_input('%', char_count);
	char_count += ft_treat_width(flags, 1, flags->zero);
	if (flags->minus == 0)	
		char_count = ft_write_input('%', char_count);
	return (char_count);
}
