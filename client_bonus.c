/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 03:12:03 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/12/15 04:49:38 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_bits(int pid, char c)
{
	int	i;
	int	check;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			check = kill(pid, SIGUSR1);
		else
			check = kill(pid, SIGUSR2);
		usleep(50);
		i--;
	}
	return (check);
}

void	check_if_sent(int check)
{
	if (check == 0)
		ft_putstr("signal has been sent successfully !\n");
	else
		ft_putstr("something went wrong while sending the message !\n");
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
		while (str[i])
		{
			check = send_bits(pid, str[i]);
			i++;
		}
		send_bits(pid, '\n');
		check_if_sent(check);
	}
	else
	{
		ft_putstr("Syntax error\n");
	}
}
