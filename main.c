/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:41:12 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/12/09 14:15:47 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"
#include "include/MLX42.h"

double	rad_switch(double deg)
{
	return (deg * M_PI / 180);
}
bool	no_wall(t_map *info, t_point *a)
{
	int	i;

	i = -1;
	while (i++ < 3)
	{
		if (info->map[g(a->y + i)][g(a->x + i)] == '1')
			return (0);
		if (info->map[g(a->y)][g(a->x + i)] == '1')
			return (0);
		if (info->map[g(a->y - i)][g(a->x)] == '1')
			return (0);
	}
	return (1);
}
void	floor_ceiling(t_map *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(info->img, x, y, info->e->f);
			else
				mlx_put_pixel(info->img, x, y, info->e->c);
			x++;
		}
		y++;
	}
}
void	render_3d(t_map *info)
{
	floor_ceiling(info);
	cast_rays(info);
	// draw(info->img, info->map);
	// draw_player(info->img, info);
}

void	key_handle(void	*param)
{
	t_map	*info = param;
	double	e;
	double	f;
	if (mlx_is_key_down(info->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(info->mlx);
	if (mlx_is_key_down(info->mlx, MLX_KEY_F))
		info->player->speed += 0.2;
	if (mlx_is_key_down(info->mlx, MLX_KEY_W))
	{
		e = cos(info->player->angle) * info->player->speed;
		f = sin(info->player->angle) * info->player->speed;
		if (no_wall(info, &(t_point){e + info->player->p->x, f + info->player->p->y}))
		{
			info->player->p->x += cos(info->player->angle) * info->player->speed;
			info->player->p->y += sin(info->player->angle) * info->player->speed;
		}
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_S))
	{
		e = cos(info->player->angle) * info->player->speed;
		f = sin(info->player->angle) * info->player->speed;
		if (no_wall(info, &(t_point){info->player->p->x - e, info->player->p->y - f}))
		{
			info->player->p->x -= cos(info->player->angle) * info->player->speed;
			info->player->p->y -= sin(info->player->angle) * info->player->speed;
		}
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_LEFT))
		info->player->angle -= rad_switch(3.5);
	if (mlx_is_key_down(info->mlx, MLX_KEY_RIGHT))
		info->player->angle += rad_switch(3.5);
	mlx_delete_image(info->mlx, info->img);
	info->img = mlx_new_image(info->mlx, 1920, 1080);
	mlx_image_to_window(info->mlx, info->img, 0, 0);
	render_3d(info);
}

int	main(int ac, char **av)
{
	t_map	*map;
	int	i;

	i = 0;
	map = malloc(sizeof(t_map));
	ft_memset(map, 0, sizeof(map));
	p_init(&map);
	if (ac == 2)
	{
		if (!ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
			ft_putstr_fd("File must be .cub\n", 2);
		check_file(av[1], map);
		init_txt(map);
		map->mlx = mlx_init(1920, 1080, "CUB", false);
		map->img = mlx_new_image(map->mlx, 1920, 1080);
		mlx_image_to_window(map->mlx, map->img, 0, 0);
		mlx_loop_hook(map->mlx, &key_handle, map);
		mlx_loop(map->mlx);
		mlx_terminate(map->mlx);
	}
}
