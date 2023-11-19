/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:14:12 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/11/19 14:57:34 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

bool	cha_v(char c)
{
	if (!c)
		return (false);
	if (c == '1' || c == '0' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E' || c == '\n')
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

void	v_body(char **f)
{
	int	i;
	int	j;

	i = 1;
	while (f[i])
	{
		j = 0;
		while (f[i][j] && j < ft_start(f[i], 1))
		{
			if (!cha_v(f[i][j]))
				ft_putstr_fd("Probleme in map\n", 2);
			if (!j && cha_v2(f[i][j]) && (!cha_v(f[i - 1][j]) || !cha_v(f[i + 1][j])
				|| !cha_v(f[i][j + 1])))
				ft_putstr_fd("Probleme in map\n", 2);
			else if (j && cha_v2(f[i][j]) && (!cha_v(f[i - 1][j]) || !cha_v(f[i + 1][j])
				|| !cha_v(f[i][j + 1]) || !cha_v(f[i][j - 1])))
				ft_putstr_fd("Probleme in map\n", 2);
			j++;
		}
		i++;
	}
}
