/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:17:56 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/12/10 18:17:33 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	put_pixel(mlx_image_t *img, unsigned int x, unsigned int y, uint32_t c)
{
	uint32_t	*p;

	p = (uint32_t *)img->pixels + (sizeof(uint8_t) * (y * img->width) + x);
	*p = c;
}

t_point	*hori_inter(t_map *info)
{
	t_point	*a;
	t_point	step;
	int		offset;

	a = malloc(sizeof(t_point));
	a->y = floor(info->player->p->y / TILE) * TILE;
	step.y = -TILE;
	offset = -1;
	if (sin(info->ray_ang) > 0)
	{
		a->y += TILE;
		step.y *= -1;
		offset = 0;
	}
	a->x = (a->y - info->player->p->y) / tan(info->ray_ang)
		+ info->player->p->x;
	step.x = step.y / tan(info->ray_ang);
	while (wall_check(info, a, offset, 0))
	{
		a->x += step.x;
		a->y += step.y;
	}
	return (a);
}

t_point	*verti_inter(t_map *info)
{
	t_point	*a;
	t_point	step;
	int		offset;

	a = malloc(sizeof(t_point));
	a->x = floor(info->player->p->x / TILE) * TILE;
	step.x = -TILE;
	offset = -1;
	if (cos(info->ray_ang) > 0)
	{
		offset = 0;
		a->x += TILE;
		step.x *= (-1);
	}
	a->y = tan(info->ray_ang) * (a->x - info->player->p->x)
		+ info->player->p->y;
	step.y = tan(info->ray_ang) * step.x;
	while (wall_check(info, a, offset, 1))
	{
		a->x += step.x;
		a->y += step.y;
	}
	return (a);
}
