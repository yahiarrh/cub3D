/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:41:12 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/11/21 22:37:03 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"
#include "include/MLX42.h"

int	main(int ac, char **av)
{
	t_map	*map;
	mlx_t   *mlx;
	mlx_image_t   *img;
	int	i;

	i = 0;
	map = malloc(sizeof(t_map));
	ft_memset(map, 0, sizeof(map));
	if (ac == 2)
	{
		if (!ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
			ft_putstr_fd("File must be .cub\n", 2);
		check_file(av[1], map);
		mlx = mlx_init(1024, 512, "CUB", false);
		img = mlx_new_image(mlx, 1024, 512);
		mlx_image_to_window(mlx, img, 0, 0);
		draw(img, map->map);
		mlx_loop(mlx);
		mlx_terminate(mlx);
	}
}
