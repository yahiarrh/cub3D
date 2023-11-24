/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:41:12 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/11/24 02:36:57 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"
#include "include/MLX42.h"

void	key_handle(void	*param)
{
	t_map	*map = param;
	int x;
	int y;

	x = (map->player->x + 1) / 64;
	y = (map->player->y + 1) / 64;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (map->map[y][x] != '1')
	{
		mlx_delete_image(map->mlx, map->img);
		if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
			map->player->y -= map->player->speed;
		mlx_delete_image(map->mlx, map->img);
		if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
			map->player->y += map->player->speed;
		mlx_delete_image(map->mlx, map->img);
		if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
			map->player->x -= map->player->speed;
		mlx_delete_image(map->mlx, map->img);
		if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
			map->player->x += map->player->speed;
	}
	map->img = mlx_new_image(map->mlx, 1920, 1080);
	mlx_image_to_window(map->mlx, map->img, 0, 0);
	draw(map->img, map->map);
	draw_player(map->img, map);
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
		map->mlx = mlx_init(1920, 1080, "CUB", false);
		map->img = mlx_new_image(map->mlx, 1920, 1080);
		mlx_image_to_window(map->mlx, map->img, 0, 0);
		mlx_loop_hook(map->mlx, &key_handle, map);
		mlx_loop(map->mlx);
		mlx_terminate(map->mlx);
	}
}
