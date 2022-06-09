/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sharp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:29:44 by sismaili          #+#    #+#             */
/*   Updated: 2021/12/22 19:17:15 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_x(char ch)
{
	if (ch == 'x')
		return ("0x");
	return ("0X");
}

int	ft_sharp(char *args, va_list print, char arg, int i)
{
	int	j;
	int	flag;
	int	number;

	j = 0;
	flag = 0;
	number = va_arg(print, unsigned int);
	while (args[i] != '%')
	{
		if (args[i] == '#' && number != 0)
			flag = 1;
		i--;
	}
	if (flag)
		j += ft_putstr(ft_get_x(arg));
	j += ft_hexa(number, arg);
	return (j);
}
