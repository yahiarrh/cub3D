/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:56:58 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/11/22 13:59:16 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	v_walls(char **f)
{
	int i;
	int s;
	int l;

	i = 1;
	while (f[i])
	{
		s = ft_start(f[i], 0);
		l = ft_start(f[i], 0);
		if (f[i][s] != '1' || f[i][l] != '1')
			ft_putstr_fd("Probleme in walls\n", 2);
		i++;
	}
}

bool	cha_v2(char c)
{	
	if (c == '0' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E')
		return (true);
	return (false);
}
void	trim_spc(t_map **map)
{
	int	i;
	int	j;

	i = 1;
	while ((*map)->map[i] && i < count_word((*map)->map) - 1)
	{
		j = ft_strlen((*map)->map[i]);
		while (j && !cha_v((*map)->map[i][j]))
		{
			if ((*map)->map[i][j] == ' ' ||  (*map)->map[i][j] == '\t')
				(*map)->map[i][j] = '\0';
			j--;
		}
		i++;
	}
}