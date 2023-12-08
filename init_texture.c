/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:35:50 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/12/08 17:02:28 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

void	init_txt(t_map *info)
{
	info->t = malloc(sizeof(t_txt));
	ft_memset(info->t, 0, sizeof(t_txt));
	info->t->no = mlx_load_png(info->e->n);
	if (!info->t->no)
		ft_putstr_fd("", 2);
	info->t->so = mlx_load_png(info->e->s);
	if (!info->t->so)
		ft_putstr_fd("", 2);
	info->t->we = mlx_load_png(info->e->w);
	if (!info->t->we)
		ft_putstr_fd("", 2);
	info->t->ea = mlx_load_png(info->e->e);
	if (!info->t->ea)
		ft_putstr_fd("", 2);
}
