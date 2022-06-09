/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:29:56 by sismaili          #+#    #+#             */
/*   Updated: 2021/12/23 15:12:57 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_printf(char args, va_list print)
{
	int	i;

	i = 0;
	if (args == 'c')
		i += ft_putchar(va_arg(print, int));
	else if (args == 's')
		i += ft_putstr(va_arg(print, char *));
	else if (args == 'p')
		i += ft_memory(va_arg(print, unsigned long), args);
	else if (args == 'd' || args == 'i')
		i += ft_putnbr(va_arg(print, int));
	else if (args == 'u')
		i += ft_putnbr_unsigned(va_arg(print, unsigned int));
	else if (args == 'x' || args == 'X')
		i += ft_hexa(va_arg(print, unsigned int), args);
	else
		i += ft_putchar(args);
	return (i);
}

int	ft_isflag(char args, int i)
{
	i++;
	if (args == '#' || args == ' ' || args == '+')
		return (1);
	return (0);
}

int	ft_set(char *args, va_list print, int *i)
{
	int	j;

	j = 0;
	(*i)++;
	if (!ft_isflag(args[*i], *i))
		j += ft_check_printf(args[*i], print);
	else
	{
		while (ft_isflag(args[*i], *i))
			(*i)++;
		j += ft_flags2((char *)args, print, *i);
	}
	return (j);
}

int	ft_printf(const char *args, ...)
{
	va_list	print;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(print, args);
	while (args[i] != '\0')
	{
		if (args[i] == '%')
			j += ft_set((char *)args, print, &i);
		else
			j += ft_putchar(args[i]);
		i++;
	}
	va_end(print);
	return (j);
}
