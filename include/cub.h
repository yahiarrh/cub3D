/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:24:06 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/11/19 16:44:09 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "MLX42.h"


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

typedef struct s_map
{
	t_elements	*e;
	char		**map;
}t_map;

int		check_num(char *f);
bool	num_val(char *f);
bool	if_elements(t_elements **el, char *f, t_v *v);
void	valid_el(t_v v);
void	v_map(char **f);
int		body_len(char *f);
bool	el_v(char *f);
bool	cha_v(char c);
bool	cha_v2(char c);
int		count_word(char **f);
int		ft_start(char *f, int flag);
void	v_walls(char **f);
void	v_body(char **f);
#endif