/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:41:12 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/12/11 16:24:00 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"
#include "include/MLX42.h"

double	rad_switch(double deg)
{
	return (deg * M_PI / 180);
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
				mlx_put_pixel(info->img, x, y, info->e->c);
			else
				mlx_put_pixel(info->img, x, y, info->e->f);
			x++;
		}
		y++;
	}
}

void	render_3d(t_map *info)
{
	floor_ceiling(info);
	cast_rays(info);
}

void	key_handle(void	*param)
{
	t_map	*info;

	info = param;
	if (mlx_is_key_down(info->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(info->mlx);
	if (mlx_is_key_down(info->mlx, MLX_KEY_F))
		info->player->speed = 7;
	if (mlx_is_key_down(info->mlx, MLX_KEY_G))
		info->player->speed = 3.5;
	if (mlx_is_key_down(info->mlx, MLX_KEY_LEFT))
		info->player->angle -= rad_switch(2);
	if (mlx_is_key_down(info->mlx, MLX_KEY_RIGHT))
		info->player->angle += rad_switch(2);
	move(info);
	move2(info);
	if (!info->mo)
		mouse_fnc(info);
	mlx_delete_image(info->mlx, info->img);
	info->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(info->mlx, info->img, 0, 0);
	mlx_set_instance_depth(info->img->instances, 0);
	render_3d(info);
}

int	main(int ac, char **av)
{
	t_map	*map;
	int		i;

	i = 0;
	map = get_ptr(sizeof(t_map), 1);
	ft_memset(map, 0, sizeof(t_map));
	p_init(&map);
	if (ac == 2)
	{
		if (!ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
			ft_putstr_fd("File must be .cub\n", 2);
		check_file(av[1], map);
		init_txt(map);
		map->mlx = mlx_init(WIDTH, HEIGHT, "CUB", 0);
		map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
		mlx_image_to_window(map->mlx, map->img, 0, 0);
		mlx_set_cursor_mode(map->mlx, MLX_MOUSE_HIDDEN);
		mlx_key_hook(map->mlx, &key_change, map);
		mlx_loop_hook(map->mlx, &key_handle, map);
		mlx_loop(map->mlx);
		mlx_terminate(map->mlx);
		destroy_txt(map);
		get_ptr(0, 0);
	}
}
