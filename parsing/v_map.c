/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:56:58 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/11/22 17:01:20 by yrrhaibi         ###   ########.fr       */
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

void	p_info(t_map **map, int x, int y, char c)
{
	(*map)->player->x = x;
	(*map)->player->y = y;

	if (c == 'N')
		(*map)->player->dirction = - M_PI/2;
	else if (c == 'S')
		(*map)->player->dirction = M_PI/2;
	else if (c == 'W')
		(*map)->player->dirction = M_PI;
	else if (c == 'E')
		(*map)->player->dirction = 0;
}

void	v_body_help(char **map, int i, int j)
{
	if (!cha_v(map[i][j]))
		ft_putstr_fd("Probleme in map\n", 2);
	if (!j && cha_v2(map[i][j]) && (!cha_v(map[i - 1][j])
		|| !cha_v(map[i + 1][j]) || !cha_v(map[i][j + 1])))
		ft_putstr_fd("Probleme in map\n", 2);
	else if (j && cha_v2(map[i][j]) && (!cha_v(map[i - 1][j])
			|| !cha_v(map[i + 1][j]) || !cha_v(map[i][j + 1])))
		ft_putstr_fd("Probleme in map\n", 2);
}