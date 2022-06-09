/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:38:08 by sismaili          #+#    #+#             */
/*   Updated: 2021/12/22 19:18:21 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_space_plus(char *args, va_list print, int i)
{
	int	j;
	int	number;
	int	flag;

	j = 0;
	number = va_arg(print, int);
	flag = 0;
	while (args[i] != '%')
	{
		if (args[i] == '+')
		{
			if (number >= 0)
				j += ft_putchar('+');
			j += ft_putnbr(number);
			return (j);
		}
		if (args[i] == ' ')
			flag = 1;
		i--;
	}
	if (flag && number >= 0)
		j += ft_putchar(' ');
	j += ft_putnbr(number);
	return (j);
}
