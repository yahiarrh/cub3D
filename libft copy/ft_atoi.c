/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:41:04 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/12/09 17:54:50 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	r;

	i = 0;
	r = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!ft_isdigit(str[i]))
		ft_putstr_fd("Colors must be a number\n", 2);
	while (str[i] && ft_isdigit(str[i]))
	{
		r *= 10;
		r += str[i] - '0';
		i++;
	}
	return (r);
}
