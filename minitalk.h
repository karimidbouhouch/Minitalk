/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:15:21 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/12/15 04:49:01 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *str);
int		ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s);
void	ft_putnbr(int n);

#endif