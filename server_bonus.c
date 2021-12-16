/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 02:56:31 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/12/16 05:09:27 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void	handler(int signum, siginfo_t *info, void *context)
{
	static char	*bin;
	int			index;

	index = 0;
	(void) context;
	if (bin == NULL)
		bin = ft_strdup("");
	if (signum == SIGUSR1)
		bin = ft_strjoin(bin, "1\0");
	if (signum == SIGUSR2)
		bin = ft_strjoin(bin, "0\0");
	if (ft_strlen(bin) == 8)
	{
		if (get_char(bin) == 0)
			index = 1;
		ft_putchar(get_char(bin));
		free(bin);
		bin = NULL;
	}
	if (index == 1)
		kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_putstr("PID = ");
	ft_putnbr(pid);
	ft_putstr("\n");
	while (1)
		pause();
}
