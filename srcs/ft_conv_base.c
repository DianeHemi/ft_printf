/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 12:15:22 by dchampda          #+#    #+#             */
/*   Updated: 2020/05/27 12:15:23 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_conv_base(char	*str, int len, unsigned long long nb, int base)
{
	while (nb != 0)
	{
		if ((nb % base) < 10)
			str[len - 1] = (nb % base) + 48;
		else
			str[len - 1] = (nb % base) + 55;
		nb /= base;
		len--;
	}
	return (str);
}

char	*ft_ull_base(unsigned long long nb, int base)
{
	char				*str;
	unsigned long long 	nb_cpy;
	int					len;

	len = 0;
	nb_cpy = nb;
	if (nb == 0)
		return (ft_strdup("0"));
	while (nb != 0)
	{
		nb /= base;
		len++;
	}
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (0);
	str[len] = '\0';
	ft_conv_base(str, len, nb_cpy, base);
	return (str);
}
