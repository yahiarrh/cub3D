/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:56:58 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/11/18 21:22:43 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	v_walls(char **f)
{
	int i;
	int s;
	int l;

	i = 1;
	while (f[i])
	{
		s = ft_start(f[i], 0);
		l = ft_start(f[i], 1);
		 if (f[i][s] != '1' || f[i][l] != '1')
			ft_putstr_fd("Probleme in walls\n", 2);
		i++;
	}
}

bool	cha_v2(char c)
{	
	if (!c || c == '0' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E' || c == '\n')
		return (true);
	return (false);
}
