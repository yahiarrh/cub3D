/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:14:12 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/12/09 22:21:17 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

bool	cha_v(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E')
		return (true);
	return (false);
}

bool	el_v(char *f)
{
	while (*f && (*f == ' ' || *f == '\t') && *f != '\n')
		f++;
	if (!*f || *f == '\n')
		ft_putstr_fd("Error in elements\n", 2);
	while (*f && *f != ' ' && *f != '\t' && *f != '\n')
		f++;
	while (*f && (*f == ' ' || *f == '\t'))
		f++;
	if (*f != '\n')
		ft_putstr_fd("Error in elements\n", 2);
	return (true);
}

int	ft_start(char *f, int flag)
{
	int	i;

	i = 0;
	if (!flag)
	{
		while (f[i] && (f[i] == ' ' || f[i] == '\t'))
			i++;
	}
	else
	{
		i = ft_strchr(f, '\n');
		if (i)
			i--;
		while (i && (f[i] == ' ' || f[i] == '\t'))
			i--;
	}
	return (i);
}
int	count_word(char **f)
{
	int	i;

	i = 0;
	while (f[i])
		i++;
	return (i);
}

void	v_body(t_map **map)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	f = 0;
	while ((*map)->map[i])
	{
		j = 0;

		while ((*map)->map[i][j] && ft_strchr1("NSEW01\t ", (*map)->map[i][j]))
		{
			v_body_help((*map)->map, i, j);
			if (cha_v2((*map)->map[i][j]) && (*map)->map[i][j] != '0')
			{
				p_info(map, j, i, (*map)->map[i][j]);
				f++;
			}
			j++;
		}
		i++;
	}
	if (f != 1)
		ft_putstr_fd("Probleme in player\n", 2);
}
