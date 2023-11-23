/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:22:14 by msaidi            #+#    #+#             */
/*   Updated: 2023/11/23 20:50:46 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	p_init(t_map **map)
{
	(*map)->player  = malloc(sizeof(t_player));
	ft_memset((*map)->player, 0, sizeof(t_player));
	(*map)->player->r = 5;
	(*map)->player->speed = 2.5;
	(*map)->player->rotspeed = 1;
}

void	draw_player(mlx_image_t *img, t_map *coor)
{
	int i;
	int j;
	

	i = coor->player->x * 32;
	j = coor->player->y * 32;
	mlx_put_pixel(img, i + 16, j + 16, (254 << 24 | 0 << 16 | 0 << 8 | 254));
	
}
