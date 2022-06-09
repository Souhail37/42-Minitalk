/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 05:46:04 by sismaili          #+#    #+#             */
/*   Updated: 2022/01/09 13:19:27 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_sc = 1;

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}

void	a_to_binary(char sig, int pid)
{
	int	shift;

	shift = 0;
	while (shift < 8)
	{
		while (!g_sc)
			usleep(50);
		g_sc = 0;
		ft_printf("send signal..!\n");
		if (sig & (128 >> shift))
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		shift++;
		usleep(100);
	}
}

void	handler_fun(int i)
{
	ft_printf("received signal..!\n");
	g_sc = 1;
	i = 0;
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_printf("Please write the PID and the string to send\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, handler_fun);
	while (av[2][i])
	{
		a_to_binary(av[2][i], pid);
		i++;
	}
	return (0);
}
