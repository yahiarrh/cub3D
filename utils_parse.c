/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:15:04 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/11/13 21:29:48 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	v_map(char *f)
{
	int	i;

	i = 0;
	while (f[i] && f[i] != '\n')
	{
		if (f[i++] != '1')
			ft_putstr_fd("Probleme in wall\n", 2);
	}
	while (f[i] && i < body_len(f))
	{
		if (f[i - 1] == '\n' && f[i] != '1')
			ft_putstr_fd("Probleme in wall\n", 2);
		if (f[i] == '\n' && f[i] && f[i + 1] != '1')
			ft_putstr_fd("Probleme in wall\n", 2);
		if (f[i] != '1' && f[i] != '0' && f[i] != 'N' && f[i] != 'S'
			&& f[i] != 'W' && f[i] != 'E' && f[i] != '\n')
			ft_putstr_fd("Probleme in wall\n", 2);
		i++;
	}
	while (f[i] && f[i] != '\n')
	{
		if (f[i++] != '1')
			ft_putstr_fd("Probleme in wall\n", 2);
	}
}

int	check_num(char *f)
{
	int	*r;
	int	i;
	int	j;

	r = malloc(sizeof(int) * 3);
	i = 0;
	j = 0;
	while (f[i] && f[i] != '\n')
	{
		while (!ft_isdigit(f[i]))
			i++;
		r[j] = ft_atoi(f + i);
		j++;
		while (f[i] && f[i] != '\n' && ft_isdigit(f[i]))
			i++;
	}
	return (r[0] << 16 | r[1] << 8 | r[2]);
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
		i++;
	}
	if (flag != 2)
		return (0);
	i = 0;
	while (f[i] && f[i] != '\n')
	{
		while (!ft_isdigit(f[i]))
			i++;
		if (ft_atoi(f + i) > 255)
			return (0);
		while (ft_isdigit(f[i]))
			i++;
	}
	return (1);
}

bool	if_elements(t_elements **el, char *f, t_v *v)
{
	if (!ft_strncmp("NO", f, 2) && !v->n++)
		(*el)->n = ft_substr(f, 0, ft_strchr(f, '\n'));
	else if (!ft_strncmp("SO", f, 2) && !v->s++)
		(*el)->s = ft_substr(f, 0, ft_strchr(f, '\n'));
	else if (!ft_strncmp("WE", f, 2) && !v->w++)
		(*el)->w = ft_substr(f, 0, ft_strchr(f, '\n'));
	else if (!ft_strncmp("EA", f, 2) && !v->e++)
		(*el)->e = ft_substr(f, 0, ft_strchr(f, '\n'));
	else if (!ft_strncmp("F", f, 1) && num_val(f) && !v->f++)
		(*el)->f = check_num(f);
	else if (!ft_strncmp("C", f, 1) && num_val(f) && !v->c++)
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
