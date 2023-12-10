/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:58:59 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/12/10 16:49:58 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strchr(const char *str, int c)
{
	char	ch;
	int		i;

	ch = (char)c;
	i = 0;
	if (c == 0)
		return (ft_strlen(str));
	while (str[i])
	{
		if (str[i] == ch)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strchr1(const char *str, int c)
{
	char	ch;
	int		i;

	ch = (char)c;
	i = 0;
	if (c == 0)
		return ((char *)(str + ft_strlen(str)));
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
