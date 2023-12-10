/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:37:24 by msaidi            #+#    #+#             */
/*   Updated: 2023/12/10 18:17:38 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	dda_line(t_point *a, t_point *b, t_map	*info)
{
	double	i;
	t_point	delta;
	t_point	p;
	double	step;

	i = 1;
	p.x = a->x;
	p.y = a->y;
	delta.x = b->x - a->x;
	delta.y = b->y - a->y;
	if (fabs(delta.x) > fabs(delta.y))
		step = fabs(delta.x);
	else
		step = fabs(delta.y);
	a->x = calcul_x(info);
	while (i <= step)
	{
		a->y = calcul_y(info, p.y, b->y);
		put_pixel(info->img, round(p.x), round(p.y),
			color(which_c(info), a->x, a->y));
		p.x += delta.x / step;
		p.y += delta.y / step;
		i++;
	}
}

void	render_wall(t_map *info, int x)
{
	t_point	s;
	t_point	e;
	double	player_plan;

	player_plan = (WIDTH / 2) / tan(rad_switch(30));
	info->dist_towall *= cos(info->ray_ang - info->player->angle);
	info->wsh = (TILE / info->dist_towall) * player_plan;
	s.x = x;
	e.x = x;
	s.y = bring_back((HEIGHT / 2) - (info->wsh / 2));
	e.y = bring_back((HEIGHT / 2) + (info->wsh / 2));
	dda_line(&s, &e, info);
}

void	render_rays(t_map *info, int x)
{
	t_point	*hori;
	t_point	*verti;

	hori = hori_inter(info);
	verti = verti_inter(info);
	if (ft_distance(info->player->p, hori) < ft_distance(info->player->p,
			verti))
	{
		info->dist_towall = ft_distance(info->player->p, hori);
		info->is_ver = 0;
		info->player->in_p = hori->x;
	}
	else
	{
		info->dist_towall = ft_distance(info->player->p, verti);
		info->is_ver = 1;
		info->player->in_p = verti->y;
	}
	free(hori);
	free(verti);
	render_wall(info, x);
}

void	cast_rays(t_map *info)
{
	int		i;
	double	step;

	info->ray_ang = info->player->angle - rad_switch(30);
	step = rad_switch(60) / WIDTH;
	i = -1;
	while (++i < WIDTH)
	{
		render_rays(info, i);
		info->ray_ang += step;
	}
}
