/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:47:25 by sismaili          #+#    #+#             */
/*   Updated: 2021/12/22 19:14:45 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_hexa(unsigned int n, char arg);
int	ft_memory(unsigned long n, char arg);
int	ft_flags2(char *args, va_list print, int i);
int	ft_check_printf(char args, va_list print);
int	ft_printf(const char *args, ...);
int	ft_sharp(char *args, va_list print, char arg, int i);
int	ft_space_plus(char *args, va_list print, int i);

#endif
