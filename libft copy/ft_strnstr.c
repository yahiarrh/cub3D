/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:44:54 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/12/10 20:19:33 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, int len)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	j = ft_strlen(needle);
	if (j == 0)
		return ((char *)(haystack));
	if (len == 0 && needle[i])
		return (NULL);
	while (haystack[i] && i < len)
	{
		f = 0;
		while (haystack[i + f] == needle[f] && needle[f] && f < j)
			f++;
		if (f == j && !haystack[i + f])
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
