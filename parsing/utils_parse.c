/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:15:04 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/12/03 19:47:49 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	v_map(t_map **map)
{
	int	i;
	int	l;

	i = 0;
	l = count_word((*map)->map);
	(*map)->col = l;
	l--;
	while ((*map)->map[0][i] && (*map)->map[0][i] != '\n')
	{
		if ((*map)->map[0][i] != '1' && (*map)->map[0][i] != ' ' && (*map)->map[0][i] != '\t')
			ft_putstr_fd("Probleme in walls\n", 2);
		i++;
	}
	v_walls((*map)->map);
	v_body(map);
	i = 0;
	while ((*map)->map[l][i])
	{
		if ((*map)->map[l][i] != '1' && (*map)->map[l][i] != ' ' && (*map)->map[l][i] != '\t')
			ft_putstr_fd("Probleme in walls\n", 2);
		i++;
	}
}

bool	num_val(char *f)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (f[i] && f[i] != '\n')
	{
		if (f[i] == ',')
			flag++;
		else if (f[i] != ' ' && f[i] != '\t' && !ft_isdigit(f[i]))
			ft_putstr_fd("Error in elements\n", 2);
		i++;
	}
	if (flag != 2)
		ft_putstr_fd("It must be N,N,N\n", 2);
	return (1);
}

int	check_num(char *f)
{
	int	*r;
	int	i;
	int	j;

	r = malloc(sizeof(int) * 3);
	i = 0;
	j = 0;
	while (!ft_isdigit(f[i]))
		i++;
	while (f[i] && f[i] != '\n' && j < 3)
	{
		if (f[i] == ',')
			i++;
		r[j] = ft_atoi(f + i);
		if (r[j] > 255)
			ft_putstr_fd("Numbers must in 0 & 255 range\n", 2);
		j++;
		while (f[i] && f[i] != '\n' && (ft_isdigit(f[i])
				|| f[i] == ' ' || f[i] == '\t'))
			i++;
	}
	return (r[0] << 16 | r[1] << 8 | r[2]);
}

bool	if_elements(t_elements **el, char *f, t_v *v)
{
	if (!ft_strncmp("NO", f, 2) && el_v(f + 2) && !v->n++)
		(*el)->n = ft_substr(f, ft_start(f + 2, 0), 
				ft_strchr(f, '\n') - ft_start(f + 2, 0));
	else if (!ft_strncmp("SO", f, 2) && el_v(f + 2) && !v->s++)
		(*el)->s = ft_substr(f, ft_start(f + 2, 0),
				ft_strchr(f, '\n') - ft_start(f + 2, 0));
	else if (!ft_strncmp("WE", f, 2) && el_v(f + 2) && !v->w++)
		(*el)->w = ft_substr(f, ft_start(f + 2, 0),
				ft_strchr(f, '\n') - ft_start(f + 2, 0));
	else if (!ft_strncmp("EA", f, 2) && el_v(f + 2) && !v->e++)
		(*el)->e = ft_substr(f, ft_start(f + 2, 0),
				ft_strchr(f, '\n') - ft_start(f + 2, 0));
	else if (!ft_strncmp("F", f, 1) && num_val(f + 1) && !v->f++)
		(*el)->f = check_num(f);
	else if (!ft_strncmp("C", f, 1) && num_val(f + 1) && !v->c++)
		(*el)->c = check_num(f);
	else
		return (false);
	return (true);
}

void	valid_el(t_v v)
{
	if (v.n != 1)
		ft_putstr_fd("Error in elements\n", 2);
	else if (v.s != 1)
		ft_putstr_fd("Error in elements\n", 2);
	else if (v.w != 1)
		ft_putstr_fd("Error in elements\n", 2);
	else if (v.e != 1)
		ft_putstr_fd("Error in elements\n", 2);
	else if (v.f != 1)
		ft_putstr_fd("Error in elements\n", 2);
	else if (v.c != 1)
		ft_putstr_fd("Error in elements\n", 2);
}