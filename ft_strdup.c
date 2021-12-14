/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kid-bouh <kid-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:17:46 by kid-bouh          #+#    #+#             */
/*   Updated: 2021/12/14 03:17:54 by kid-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;
	int		n;

	i = 0;
	n = ft_strlen(s);
	if (!s)
		return (NULL);
	p = malloc((n + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (i < (int)n)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
