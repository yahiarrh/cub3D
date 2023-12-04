/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:22:14 by msaidi            #+#    #+#             */
/*   Updated: 2023/12/04 15:57:46 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	p_init(t_map **map)
{
	(*map)->player  = malloc(sizeof(t_player));
	ft_memset((*map)->player, 0, sizeof(t_player));
	(*map)->player->r = 8;
	(*map)->player->speed = 1.2;
	(*map)->player->rotspeed = 0.1;
}

void	draw_player(mlx_image_t *img, t_map *coor)
{
	int x;
	int y;
	int r2 = coor->player->r;
	
	x = -coor->player->r;
	while (x <= coor->player->r)
	{
		y = -coor->player->r;
		while (y <= coor->player->r)
		{
			if (x * x + y * y <= r2 * r2)
				mlx_put_pixel(img, coor->player->p->x + x, coor->player->p->y + y, RED);
			y++;
		}
		x++;
	}
	cast_rays(coor);
}
