/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:26:16 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/11/12 00:39:49 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include "libft/libft.h"

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
	char		*roof;
	char		*floor;
	char		*body;
}t_map;

int		check_num(char *f);
bool	num_val(char *f);
bool	valid_f(char *s);
bool	if_elements(t_elements **el, char *f, t_v **v);
bool	valid_el(t_v *v);
#endif