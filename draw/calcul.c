/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:13:20 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/12/10 18:17:31 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

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

int	g(double a)
{
	return (a / TILE);
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
	double	ytext;

	y2 = y1 + ((info->wsh / 2) - (HEIGHT / 2));
	ytext = y2 * which_h(info) / info->wsh;
	return (ytext);
}
