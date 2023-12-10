/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:23:27 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/12/10 18:17:34 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	draw_cube(mlx_image_t *img, int i, int j, uint32_t c)
{
	int	x;
	int	y;

	y = i;
	while (y < i + 16)
	{
		x = j;
		while (x < j + 16)
		{
			mlx_put_pixel(img, x, y, c);
			x++;
		}
		y++;
	}
}

void	draw(mlx_image_t *img, char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '1')
				draw_cube(img, x * 16, y * 16, BLACK);
			else if (cha_v2(map[x][y]))
				draw_cube(img, x * 16, y * 16, WHITE);
			y++;
		}
		x++;
	}
}
