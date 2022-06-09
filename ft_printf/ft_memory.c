/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 13:28:17 by sismaili          #+#    #+#             */
/*   Updated: 2021/12/19 15:31:29 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_start(unsigned long n)
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

void	ft_loop(unsigned long number, char *base)
{
	if (number >= 16)
	{
		ft_loop(number / 16, base);
		ft_loop(number % 16, base);
	}
	else
		ft_putchar(base[number]);
}

int	ft_memory(unsigned long n, char arg)
{
	int		i;
	char	*base;

	i = ft_start(n);
	arg = 'p';
	i += ft_putstr("0x");
	base = "0123456789abcdef";
	ft_loop(n, base);
	return (i);
}
