/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:21:40 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/11/13 20:44:18 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	while (f[i] && f[i] != '1')
		i++;
	if (f[i] != '1')
		ft_putstr_fd("No map\n", 2);
	v_map(f + i);
	(*map)->map = ft_substr(f, i, ft_strlen(f));
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
		while (f[i] == ' ')
			i++;
		if (!if_elements(&el, f + i, &v))
			break;
		while (f[i] && f[i] != '\n')
			i++;
	}
	valid_el(v);
	fill_map(&map, f + i);
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
int	main(int ac, char **av)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	ft_memset(map, 0, sizeof(map));
	if (ac == 2)
	{
		if (!ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
			ft_putstr_fd("File must be .cub\n", 2);
		check_file(av[1], map);
	}
}