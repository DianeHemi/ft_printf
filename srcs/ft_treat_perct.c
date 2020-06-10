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

int	ft_treat_perct(int char_count)
{
	ft_putchar('%');
	return (char_count + 1);
}
