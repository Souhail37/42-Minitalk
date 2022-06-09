/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:15:09 by sismaili          #+#    #+#             */
/*   Updated: 2021/12/22 19:12:40 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags2(char *args, va_list print, int i)
{
	int		j;
	char	arg;
	int		flag;

	j = 0;
	flag = 0;
	arg = args[i];
	if (arg == 'x' || arg == 'X')
		j += ft_sharp(args, print, arg, i);
	else if (arg == 'd' || arg == 'i')
		j += ft_space_plus(args, print, i);
	else
		j += ft_check_printf(arg, print);
	return (j);
}
