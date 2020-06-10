/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 15:30:31 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/10 15:30:42 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned int	ft_nb_size(unsigned int nb)
{
	unsigned int	nb_size;

	nb_size = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		nb_size++;
	}
	return (nb_size);
}

static char			*fill_str(char *res, unsigned int nbr, unsigned int nb_size)
{
	res[nb_size] = '\0';
	while (nb_size > 0)
	{
		res[--nb_size] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (res);
}

char				*ft_uitoa(unsigned int n)
{
	char			*res;
	unsigned int	nbr;
	unsigned int	nb_size;

	nbr = n;
	nb_size = ft_nb_size(nbr);
	if (!(res = malloc(sizeof(char) * nb_size + 1)))
		return (NULL);
	fill_str(res, nbr, nb_size);
	return (res);
}
