/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:50:48 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/12/10 18:31:28 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	int			i;
	char		*sub;

	if (!s)
		return (NULL);
	if (len == 0 || ft_strlen(s) <= start)
		return (ft_strdup(""));
	i = 0;
	if (ft_strlen(s + start) < len)
		sub = (char *)get_ptr(sizeof(char) * (ft_strlen(s + start) + 1), 1);
	if (ft_strlen(s + start) >= len)
		sub = (char *)get_ptr(sizeof(char) * (len + 1), 1);
	if (!sub)
		return (0);
	while (s[start] && i < len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
