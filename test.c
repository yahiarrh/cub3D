                                   #include <stdio.h>
#include "include/cub.h"


#define WIDTH 1024
#define HEIGHT 512

typedef struct coordi_s
{
	int x;
	int y;
} coordi_t;

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	twodim(mlx_t *mlx_p, mlx_image_t *img_p, t_map *map)
{
	coordi_t c = {c.x = 0, c.y = 0};
	int i = 0;
	int j = 0;
	while ()
	{
		
	}

}

int	main(int ac, char **av)
{
	mlx_t	*mlx_p;
	mlx_image_t *img_p;
	t_map	*map;
	int	i = 0;

	map = malloc(sizeof(t_map));
	ft_memset(map, 0, sizeof(map));
	if (ac == 2)
	{
		if (!ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
			ft_putstr_fd("File must be .cub\n", 2);
		check_file(av[1], map);
		mlx_p = mlx_init(WIDTH, HEIGHT, "CUB3D", 1);
		if (!mlx_p)
			return write(2, "###", 3);
		img_p = mlx_new_image(mlx_p, WIDTH, HEIGHT);
		twodim(mlx_p, img_p, map);
			mlx_image_to_window(mlx_p, img_p, 0, 0);
		mlx_loop(mlx_p);
	}
	return mlx_terminate(mlx_p), 0;
}