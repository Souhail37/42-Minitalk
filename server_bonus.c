/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 06:02:45 by sismaili          #+#    #+#             */
/*   Updated: 2022/01/09 16:22:34 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	ft_shift(int handler, char c, int bits)
{
	if (handler == SIGUSR1)
	{
		c |= 128 >> bits;
		usleep (50);
	}
	else if (handler == SIGUSR2)
	{
		c ^= 128 >> bits;
		usleep(50);
	}
	return (c);
}

void	siguser_handler(int handler, siginfo_t *infos, void	*param)
{
	static int		bits = 0;
	static char		c = (char)255;
	static pid_t	pid = -1;

	param = 0;
	if (pid != infos->si_pid && infos->si_pid != 0)
	{
		bits = 0;
		c = (char)255;
		pid = infos->si_pid;
	}
	c = ft_shift(handler, c, bits);
	if (++bits == 8)
	{
		ft_printf("%c", c);
		bits = 0;
		c = (char)255;
	}
	kill(pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_sigaction = siguser_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("pid = %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
