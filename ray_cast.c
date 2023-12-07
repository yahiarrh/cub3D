/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:37:24 by msaidi            #+#    #+#             */
/*   Updated: 2023/12/07 22:29:52 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int	g(double a)
{
	return (a / 64);
}

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
		step = 	fabs(delta.y);
	if (step == 0)
		mlx_put_pixel(info->img, a->x, a->y, KHRA);
	while (i <= step)
	{
		mlx_put_pixel(info->img, round(p.x), round(p.y), KHRA);
		p.x += delta.x / step;
		p.y += delta.y / step;
		i++;
	}
}

t_point	*hori_inter(t_map *info)
{
	t_point	*a;
	t_point	step;
	int		offset;

	a = malloc(sizeof(t_point));
	a->y = floor(info->player->p->y / 64) * 64;
	step.y = -64;
	offset = -1;
	if (sin(info->ray_ang) > 0)
	{
		a->y += 64;
		step.y *= -1;
		offset = 0;
	}
	a->x = (a->y - info->player->p->y) / tan(info->ray_ang) + info->player->p->x;
	step.x = step.y / tan(info->ray_ang);
	while (g(a->x) > 0 && g(a->y) > 0 && g(a->y) < info->col
	&& g(a->x) < ft_strlen(info->map[g(a->y) + offset])
	&& info->map[g(a->y) + offset][g(a->x)]
	&& info->map[g(a->y) + offset][g(a->x)] != '1')
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
	a->x = floor(info->player->p->x / 64) * 64;
	step.x = -64;
	offset = -1;
	if (cos(info->ray_ang) > 0)
	{
		offset = 0;
		(a->x += 64) && (step.x *= (-1));
	}
	a->y = tan(info->ray_ang) * (a->x - info->player->p->x) + info->player->p->y;
	step.y = tan(info->ray_ang) * step.x;
	while (g(a->x) > 0 && g(a->y) > 0
		&& g(a->y) < info->col
		&& g(a->x) < ft_strlen(info->map[g(a->y) + offset]) && info->map[g(a->y) + offset][g(a->x)]
		&& info->map[g(a->y)][g(a->x) + offset] != '1')
	{
		a->x += step.x;
		a->y += step.y;
	}
	return (a);
}
double	ft_distance(t_point	*a, t_point *b)
{
	return (sqrt(pow((b->x - a->x), 2) + pow((b->y - a->y), 2)));	
}
double	bring_back(double a)
{
	if (a < 0)
		return (0.0);
	if (a >= HEIGHT)
		return (HEIGHT - 1.0);
	return (a);
}

void	render_wall(t_map *info, int x)
{
	t_point	s;
	t_point	e;
	double	pro_plan;
	double	player_plan;

	player_plan = (WIDTH / 2) / tan(rad_switch(30));
	info->dist_towall *= cos(info->ray_ang - info->player->angle);
	pro_plan = (player_plan / info->dist_towall) * TILE;
	s.x = x;
	e.x = x;
	s.y = bring_back((HEIGHT / 2) - (pro_plan / 2));
	e.y = bring_back((HEIGHT / 2) + (pro_plan / 2));
	dda_line(&s, &e, info);
}
void	render_rays(t_map *info, int x)
{
	t_point	*hori;
	t_point	*verti;

	hori = hori_inter(info);
	verti = verti_inter(info);
	if (ft_distance(info->player->p, hori) < ft_distance(info->player->p, verti))
		info->dist_towall = ft_distance(info->player->p, hori);
	else
		info->dist_towall = ft_distance(info->player->p, verti);
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
