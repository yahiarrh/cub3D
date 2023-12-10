/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:51:06 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/12/10 20:36:45 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	move(t_map *info)
{
	double	e;
	double	f;

	if (mlx_is_key_down(info->mlx, MLX_KEY_W))
	{
		e = cos(info->player->angle) * info->player->speed;
		f = sin(info->player->angle) * info->player->speed;
		if (no_wall(info, &(t_point){e + info->player->p->x,
				f + info->player->p->y}))
		{
			info->player->p->x += e;
			info->player->p->y += f;
		}
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_S))
	{
		e = cos(info->player->angle) * info->player->speed;
		f = sin(info->player->angle) * info->player->speed;
		if (no_wall(info, &(t_point){info->player->p->x - e,
				info->player->p->y - f}))
		{
			info->player->p->x -= e;
			info->player->p->y -= f;
		}
	}
}

void	move2(t_map *info)
{
	double	e;
	double	f;

	if (mlx_is_key_down(info->mlx, MLX_KEY_A))
	{
		e = cos(info->player->angle + rad_switch(90)) * info->player->speed;
		f = sin(info->player->angle + rad_switch(90)) * info->player->speed;
		if (no_wall(info, &(t_point){info->player->p->x - e,
				info->player->p->y - f}))
		{
			info->player->p->x -= e;
			info->player->p->y -= f;
		}
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_D))
	{
		e = cos(info->player->angle + rad_switch(90)) * info->player->speed;
		f = sin(info->player->angle + rad_switch(90)) * info->player->speed;
		if (no_wall(info, &(t_point){e + info->player->p->x,
				f + info->player->p->y}))
		{
			info->player->p->x += e;
			info->player->p->y += f;
		}
	}
}

void	key_change(mlx_key_data_t key, void *par)
{
	t_map	*info;

	info = par;
	if (key.key == MLX_KEY_SPACE && key.action == MLX_PRESS)
		change_txt(info, 1);
	if (key.key == MLX_KEY_SPACE && key.action == MLX_RELEASE)
		change_txt(info, 0);
	if (key.key == MLX_KEY_M && key.action == MLX_PRESS)
		info->mo = !info->mo;
}

void	mouse_fnc(void *param)
{
	t_map	*info;
	int		x;
	int		y;

	info = param;
	mlx_get_mouse_pos(info->mlx, &x, &y);
	x -= WIDTH / 2;
	info->player->angle += (double)x / WIDTH;
	mlx_set_mouse_pos(info->mlx, WIDTH / 2, HEIGHT / 2);
}

void	change_txt(t_map *info, int flag)
{
	if (flag == 1)
	{
		mlx_delete_image(info->mlx, info->txt);
		info->txt = mlx_texture_to_image(info->mlx, info->t->n1);
		mlx_image_to_window(info->mlx, info->txt, 100, 100);
	}
	else
	{
		mlx_delete_image(info->mlx, info->txt);
		info->txt = mlx_texture_to_image(info->mlx, info->t->n);
		mlx_image_to_window(info->mlx, info->txt, 100, 100);
	}
}
