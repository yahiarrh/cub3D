/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:41:12 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/11/22 17:09:12 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"
#include "include/MLX42.h"

void	p_init(t_map **map)
{
	(*map)->player  = malloc(sizeof(t_player));
	ft_memset((*map)->player, 0, sizeof(t_player));
	(*map)->player->r = 5;
	(*map)->player->speed = 2.5;
	(*map)->player->rotspeed = 1;
}

int	main(int ac, char **av)
{
	t_map	*map;
	mlx_t   *mlx;
	mlx_image_t   *img;
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
		mlx = mlx_init(1024, 512, "CUB", false);
		img = mlx_new_image(mlx, 1024, 512);
		mlx_image_to_window(mlx, img, 0, 0);
		draw(img, map->map);
		printf("x: %d|y: %d|dir: %f\n", map->player->x,map->player->y, map->player->dirction);
		printf("x: %d|y: %d|dir: %f\n", map->player->angle,map->player->walk, map->player->speed);
		mlx_loop(mlx);
		mlx_terminate(mlx);
	}
}
