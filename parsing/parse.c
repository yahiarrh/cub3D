/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:21:40 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/11/21 22:37:17 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	body_len(char *f)
{
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 0;
	j = 0;
	while (f[i])
	{
		if (f[i++] == '\n')
			n++;
	}
	i = 0;
	while (j < n)
	{
		if (f[i++] == '\n')
			j++;
	}
	return (i);
}

void	fill_map(t_map **map, char *f)
{
	int	i;

	i = 0;
	while (f[i] && (f[i] == '\n' || f[i] == ' ' || f[i] ==  '\t'))
		i++;
	if (!f[i])
		ft_putstr_fd("No map\n", 2);
	if (f[i] != '1')
		ft_putstr_fd("Element externe\n", 2);
	(*map)->map = ft_split(f + i, '\n');
	v_map((*map)->map);
}

t_elements	*check_el(char *f, t_map *map)
{
	t_elements	*el;
	t_v			v;
	int			i;

	i = 0;
	el = malloc(sizeof(t_elements));
	ft_memset(el, 0, sizeof(el));
	ft_memset(&v, 0, sizeof(t_v));
	while (f[i])
	{
		while (f[i] == '\n')
			i++;
		while (f[i] == ' ' || f[i] == '\t')
			i++;
		if (!if_elements(&el, f + i, &v))
			break ;
		while (f[i] && f[i] != '\n')
			i++;
	}
	valid_el(v);
	fill_map(&map, f + i);
	trim_spc(&map);
	return (el);
}

void	check_file(const char *file_name, t_map *map)
{
	t_file	f;

	f.fd = open(file_name, O_RDONLY);
	f.n = 1;
	if (f.fd < 0)
		ft_putstr_fd("File not found\n", 2);
	f.s = NULL;
	while (f.n > 0)
	{
		f.buff = malloc(10);
		ft_memset(f.buff, 0, 10);
		f.n = read(f.fd, f.buff, 10);
		if (f.n < 0)
			exit (1);
		f.tmp = f.s;
		f.s = ft_strjoin(f.s, f.buff);
		free(f.tmp);
		free(f.buff);
	}
	map->e = check_el(f.s, map);
}
