/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:24:06 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/11/24 00:31:52 by yrrhaibi         ###   ########.fr       */
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
# define RED (254 << 24 | 0 << 16 | 0 << 8 | 254)
# define WHITE (254 << 24 | 254 << 16 | 254 << 8 | 254)
# define BLACK (0 << 24 | 0 << 16 | 0 << 8 | 254)
# define BLUE (0 << 24 | 0 << 16 | 254 << 8 | 254)
# define GREEN (0 << 24 | 254 << 16 | 0 << 8 | 254)

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

typedef struct s_player
{
	int	x;
	int	y;
	int r; // radius
	double dirction; // -1 left, 1 right;
	int walk; // -1 backward, 1 forward;
	int angle; //rotation angle;
	double speed;	//walking speed
	int rotspeed; //rotation speed
}t_player;

typedef struct s_map
{
	mlx_t   *mlx;
	mlx_image_t   *img;
	t_elements	*e;
	t_player	*player;
	char		**map;
}t_map;

void		check_file(const char *file_name, t_map *map);
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
int			body_len(char *f);
void		trim_spc(t_map **map);
void		p_info(t_map **map, int x, int y, char c);
void		draw_player(mlx_image_t *img, t_map *coor);
void		v_body_help(char **map, int i, int j);
#endif