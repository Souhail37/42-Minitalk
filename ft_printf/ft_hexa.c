/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:34:19 by sismaili          #+#    #+#             */
/*   Updated: 2021/12/19 16:04:55 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	ft_looper(unsigned int number, char *base)
{
	if (number >= 16)
	{
		ft_looper(number / 16, base);
		ft_looper(number % 16, base);
	}
	else
		ft_putchar(base[number]);
}

int	ft_hexa(unsigned int n, char arg)
{
	int		i;
	char	*base;

	i = 0;
	i = ft_count(n);
	if (arg == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	ft_looper(n, base);
	return (i);
}
