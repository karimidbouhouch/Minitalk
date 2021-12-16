/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:14:28 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/12/16 06:08:43 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	get_char(char *bin)
{
	int	i;
	int	nb;
	int	base;

	i = 7;
	nb = 0;
	base = 1;
	while (i >= 0)
	{
		if (bin[i] == '1')
			nb = nb + base;
		base = base * 2;
		i--;
	}
	return (nb);
}

void	handler(int signum)
{
	static char	*bin;

	if (bin == NULL)
		bin = ft_strdup("");
	if (signum == SIGUSR1)
		bin = ft_strjoin(bin, "1\0");
	if (signum == SIGUSR2)
		bin = ft_strjoin(bin, "0\0");
	if (ft_strlen(bin) == 8)
	{
		ft_putchar(get_char(bin));
		free(bin);
		bin = NULL;
	}
}

int	main(void)
{
	int	pid;

	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	pid = getpid();
	ft_putstr("PID = ");
	ft_putnbr(pid);
	ft_putstr("\n");
	while (1)
	{
		pause();
	}
}
