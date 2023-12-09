/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:24:06 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/12/09 14:21:10 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "MLX42.h"
# include <math.h>

# define RED 0xFF0000FF
# define WHITE 0xFFFFFFFF
# define BLACK 0xFF
# define BLUE 0x00000FFFF
# define GREEN 0x00FF00FF
# define GRAY 0xC3C3C3FF
# define KHRA 0x43551DFF
# define TILE 64
# define HEIGHT 1080
# define WIDTH 1920

typedef struct s_file
{
	char	*buff;
	char	*s;
	char	*tmp;
	int		fd;
	int		n;
}t_file;

typedef struct s_elements
{
	char	*n;
	char	*s;
	char	*e;
	char	*w;
	int		f;
	int		c;
}t_elements;

typedef struct s_v
{
	int	n;
	int	s;
	int	e;
	int	w;
	int	f;
	int	c;
}t_v;

typedef	struct s_point
{
	double	x;
	double	y;
}t_point;

typedef struct s_player
{
	t_point *p;
	int 	r;
	double angle; 
	double speed;
	double in_p;
}t_player;


typedef struct s_txt
{
	mlx_texture_t *no;
	mlx_texture_t *so;
	mlx_texture_t *ea;
	mlx_texture_t *we;
}t_txt;

typedef struct s_map
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_txt		*t;
	t_elements	*e;
	t_player	*player;
	char		**map;
	int			col;
	double		ray_ang;
	double		dist_towall;
	bool		is_ver;
	double		wsh;
}t_map;

typedef struct s_color{
	int r;
	int b;
	int g;
}t_color;

void		check_file(const char *file_name, t_map *map);
void		fill_color(t_color *c, int f, int color);
t_elements	*check_el(char *f, t_map *map);
void    	draw(mlx_image_t *img, char **map);
int			check_num(char *f);
bool		num_val(char *f);
bool		if_elements(t_elements **el, char *f, t_v *v);
void		valid_el(t_v v);
void		v_map(t_map **f);
int			body_len(char *f);
bool		el_v(char *f);
bool		cha_v(char c);
bool		cha_v2(char c);
void		p_init(t_map **map);
int			count_word(char **f);
int			ft_start(char *f, int flag);
void		v_walls(char **f);
void		v_body(t_map **f);
void		fill_map(t_map **map, char *f);
void		trim_spc(t_map **map);
void		p_info(t_map **map, int x, int y, char c);
void		draw_player(mlx_image_t *img, t_map *coor);
void		v_body_help(char **map, int i, int j);
void		cast_rays(t_map *info);
void		dda_line(t_point *a, t_point *b, t_map	*map);
double		rad_switch(double deg);
int			g(double a);
void		init_txt(t_map *t);

#endif
