/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 03:12:03 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/12/16 05:45:05 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(170);
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
	int		check;

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
	}
	else
	{
		ft_putstr("Syntax error !\n");
	}
}
