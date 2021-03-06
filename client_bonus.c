/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 03:12:03 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/12/16 22:57:16 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_bits(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		usleep(500);
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
	}
}

void	handler(int sig)
{
	(void) sig;
	ft_putstr("signal has been sent successfully\n");
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;
	int		i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = av[2];
		signal(SIGUSR1, handler);
		while (str[i])
		{
			send_bits(pid, str[i]);
			i++;
		}
		send_bits(pid, 0);
		pause();
	}
	else
	{
		ft_putstr("Syntax error !\n");
	}
}
