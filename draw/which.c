/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:52:02 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/12/10 18:17:40 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	which_h(t_map *info)
{
	double	an;

	an = info->ray_ang;
	if (sin(an) <= 0 && !info->is_ver)
		return (info->t->so->height);
	else if (sin(an) > 0 && !info->is_ver)
		return (info->t->no->height);
	if (cos(an) <= 0 && info->is_ver)
		return (info->t->we->height);
	else if (cos(an) > 0 && info->is_ver)
		return (info->t->ea->height);
	return (0.0);
}

int	which_w(t_map *info)
{
	double	an;

	an = info->ray_ang;
	if (sin(an) <= 0 && !info->is_ver)
		return (info->t->so->width);
	else if (sin(an) > 0 && !info->is_ver)
		return (info->t->no->width);
	if (cos(an) <= 0 && info->is_ver)
		return (info->t->we->width);
	else if (cos(an) > 0 && info->is_ver)
		return (info->t->ea->width);
	return (0.0);
}

mlx_texture_t	*which_c(t_map *info)
{
	double		an;

	an = info->ray_ang;
	if (!info->is_ver && sin(an) <= 0)
		return (info->t->so);
	if (!info->is_ver && sin(an) > 0)
		return (info->t->no);
	if (info->is_ver && cos(an) > 0)
		return (info->t->ea);
	if (info->is_ver && cos(an) <= 0)
		return (info->t->we);
	return (NULL);
}

int	wall_check(t_map *info, t_point *a, int offset, int flag)
{
	if (flag)
	{
		if (g(a->x) > 0 && g(a->y) > 0
			&& g(a->y) < info->col
			&& g(a->x) < ft_strlen(info->map[g(a->y) + offset])
			&& info->map[g(a->y) + offset][g(a->x)]
			&& info->map[g(a->y)][g(a->x) + offset] != '1')
			return (1);
	}
	else
	{
		if (g(a->x) > 0 && g(a->y) > 0 && g(a->y) < info->col
			&& g(a->x) < ft_strlen(info->map[g(a->y) + offset])
			&& info->map[g(a->y) + offset][g(a->x)]
			&& info->map[g(a->y) + offset][g(a->x)] != '1')
			return (1);
	}
	return (0);
}

uint32_t	color(mlx_texture_t *img, unsigned int x, unsigned int y)
{
	uint32_t	*color;

	color = (uint32_t *)img->pixels + ((y * img->width) + x);
	return (*color);
}
