/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:37:24 by msaidi            #+#    #+#             */
/*   Updated: 2023/12/09 14:31:26 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int	g(double a)
{
	return (a / TILE);
}

int	which_h(t_map *info)
{
	double	an;

	an = info->ray_ang;
	if (sin(an) <= 0 && !info->is_ver)
		return(info->t->so->height);
	else if (sin(an) > 0 && !info->is_ver)
		return(info->t->no->height);
	if (cos(an) <= 0 && info->is_ver)
		return(info->t->we->height);
	else if (cos(an) > 0 && info->is_ver)
		return(info->t->ea->height);
	return(0.0);
}
int	which_w(t_map *info)
{
	double	an;

	an = info->ray_ang;
	if (sin(an) <= 0 && !info->is_ver)
		return(info->t->so->width);
	else if (sin(an) > 0 && !info->is_ver)
		return(info->t->no->width);
	if (cos(an) <= 0 && info->is_ver)
		return(info->t->we->width);
	else if (cos(an) > 0 && info->is_ver)
		return(info->t->ea->width);
	return(0.0);
}

int	calcul_x(t_map *info)
{
	int	x;
	int	xt;

	x = fmod(info->player->in_p, TILE);
	xt = x * (which_w(info) / TILE);
	return (xt);
}


double	calcul_y(t_map *info, double y1, double y2)
{
	double ytext;
	// printf("Y1 :: %f Y2 :: %f\n", y1,y2);
	y2 = y1 + ((info->wsh / 2) - (HEIGHT / 2));
	ytext = y2 * which_h(info) / info->wsh;
	return (ytext);
}

mlx_texture_t *which_c(t_map *info)
{
	double		an;

	an = info->ray_ang;
	if (!info->is_ver && sin(an) <= 0)
		return(info->t->so);
	if (!info->is_ver && sin(an) > 0)
		return(info->t->no);
	if (info->is_ver && cos(an) > 0)
		return(info->t->ea);
	if (info->is_ver && cos(an) <= 0)
		return(info->t->we);
	return(NULL);
}
uint32_t	color(mlx_texture_t *img, unsigned int x, unsigned int y)
{
	uint32_t	*colour;

	colour = (uint32_t *)img->pixels + ((y * img->width) + x);
	return (*colour);
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
	a->x = calcul_x(info);
	while (i <= step)
	{
		// printf("Y1 :: %f Y2 :: %f\n", p.y, a->y);
		a->y = calcul_y(info, p.y, b->y);
		mlx_put_pixel(info->img, round(p.x), round(p.y), color(which_c(info), a->x, a->y));
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
	a->y = floor(info->player->p->y / TILE) * TILE;
	step.y = -TILE;
	offset = -1;
	if (sin(info->ray_ang) > 0)
	{
		a->y += TILE;
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
	a->x = floor(info->player->p->x / TILE) * TILE;
	step.x = -TILE;
	offset = -1;
	if (cos(info->ray_ang) > 0)
	{
		offset = 0;
		(a->x += TILE) && (step.x *= (-1));
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
	if (ft_distance(info->player->p, hori) < ft_distance(info->player->p, verti))
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