/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchampda <dchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:57:42 by dchampda          #+#    #+#             */
/*   Updated: 2020/06/17 16:32:33 by dchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_strndup(const char *s, int len)
{
	char	*copy;
	size_t	i;

	i = 0;
	if (!(copy = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] != '\0' && len > 0)
	{
		copy[i] = s[i];
		i++;
		len--;
	}
	copy[i] = '\0';
	return (copy);
}

int			ft_putstr(char *str, int char_count)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (char_count + i);
}

static int	ft_str_assembly(t_printf *flags, char *str)
{
	int		char_count;
	int		len;
	int		len_str;

	char_count = 0;
	len = flags->width;
	if (str)
		len_str = ft_strlen(str);
	else
		len_str = 0;
	while (len - len_str > 0)
	{
		if (flags->zero == 0)
			ft_putchar(' ');
		else
			ft_putchar('0');
		char_count++;
		len--;
	}
	return (char_count);
}

static int	ft_str_errors(t_printf *flags, int *char_count)
{
	if (flags->dot == 0 && flags->width < 1)
	{
		write(1, "", 0);
		return (1);
	}
	else if (flags->dot == 0 && flags->width > 0)
	{
		while (flags->width > 0)
		{
			write(1, " ", 1);
			*char_count += 1;
			flags->width--;
		}
		return (1);
	}
	return (0);
}

int			ft_treat_str(va_list args, t_printf *flags, int char_count)
{
	char	*str;
	int		need_free;

	str = va_arg(args, char*);
	need_free = 0;
	if (!str)
		str = "(null)";
	if (ft_str_errors(flags, &char_count))
		return (char_count);
	if (flags->dot > 0 && (size_t)flags->dot < ft_strlen(str))
	{
		str = ft_strndup(str, flags->dot);
		need_free = 1;
	}
	if (flags->minus == 1)
		char_count = ft_putstr(str, char_count);
	char_count += ft_str_assembly(flags, str);
	if (flags->minus == 0)
		char_count = ft_putstr(str, char_count);
	if (need_free == 1)
		free(str);
	return (char_count);
}
