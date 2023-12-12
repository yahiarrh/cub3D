/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:35:50 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/12/12 11:30:49 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	valid_pl_col(int j, int flag)
{
	if (flag != 2)
		ft_putstr_fd("It must be N,N,N\n", 2);
	if (j != 3)
		ft_putstr_fd("It must be 3 nums\n", 2);
}

void	init_txt(t_map *info)
{
	info->t = get_ptr(sizeof(t_txt), 1);
	ft_memset(info->t, 0, sizeof(t_txt));
	info->t->no = mlx_load_png(info->e->n);
	if (!info->t->no)
		ft_putstr_fd("", 2);
	info->t->so = mlx_load_png(info->e->s);
	if (!info->t->so)
		ft_putstr_fd("", 2);
	info->t->we = mlx_load_png(info->e->w);
	if (!info->t->we)
		ft_putstr_fd("", 2);
	info->t->ea = mlx_load_png(info->e->e);
	if (!info->t->ea)
		ft_putstr_fd("", 2);
	info->t->n = mlx_load_png("pngs/gun/hold.png");
	info->t->n1 = mlx_load_png("pngs/gun/shoot.png");
}

bool	no_wall(t_map *info, t_point *a)
{
	int	i;

	i = -1;
	while (i++ < 5)
	{
		if (info->map[g(a->y + i)][g(a->x + i)] == '1')
			return (0);
		if (info->map[g(a->y)][g(a->x + i)] == '1')
			return (0);
		if (info->map[g(a->y - i)][g(a->x)] == '1')
			return (0);
		if (info->map[g(a->y)][g(a->x - i)] == '1')
			return (0);
	}
	return (1);
}

void	destroy_txt(t_map *map)
{
	mlx_delete_texture(map->t->ea);
	mlx_delete_texture(map->t->no);
	mlx_delete_texture(map->t->we);
	mlx_delete_texture(map->t->so);
	mlx_delete_texture(map->t->n);
	mlx_delete_texture(map->t->n1);
}
