/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:15:04 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/11/12 00:48:19 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_num(char *f)
{
	int	*r;
	int	i;
	int	j;

	r = malloc(sizeof(int) * 3);
	i = 0;
	j = 0;
	while (f[i])
	{
		while (ft_isdigit(f[i]))
			i++;
		r[j] = ft_atoi(f + i);
		j++;
		while (!ft_isdigit(f[i]))
			i++;
	}
	return (r[0] << 16 | r[1] << 8 | r[2]);
}

bool	num_val(char *f)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (f[i])
	{
		if (f[i] == ',')
			flag++;
		i++;
	}
	if (flag != 2)
		return (0);
	i = 0;
	while (f[i])
	{
		while (ft_isdigit(f[i]))
			i++;
		if (ft_atoi(f + i) > 255)
			return (0);
		while (!ft_isdigit(f[i]))
			i++;
	}
	return (1);
}

bool	valid_f(char *s)
{
	int i;

	i = 0;
	printf("%s\n", s);
	while (s[i] == ' ')
		i++;
	if(s[i] != '.' || s[i + 1] != '/')
	{
		ft_putstr_fd("Error in elements\n", 2);
		exit(1);
	}
	while (s[i])
	{
		if (!ft_isalpha(s[i]) || s[i] != '.' || s[i] != '/' || s[i] != '\n')
		{
			ft_putstr_fd("Error in elements\n", 2);
			exit(1);
		}
		i++;
	}
	return (true);
}

bool	if_elements(t_elements **el, char *f, t_v **v)
{
	if (!ft_strncmp("NO", f, 2) && valid_f(f + 2) && (*v)->n++)
		(*el)->n = ft_substr(f, 0, ft_strchr(f, '\n'));
	else if (!ft_strncmp("SO", f, 2) && valid_f(f + 2) && (*v)->s++)
		(*el)->s = ft_substr(f, 0, ft_strchr(f, '\n'));
	else if (!ft_strncmp("WE", f, 2) && valid_f(f + 2) && (*v)->w++)
		(*el)->w = ft_substr(f, 0, ft_strchr(f, '\n'));
	else if (!ft_strncmp("EA", f, 2) && valid_f(f + 2) && (*v)->e++)
		(*el)->e = ft_substr(f, 0, ft_strchr(f, '\n'));
	else if (!ft_strncmp("F", f, 1) && num_val(f) && (*v)->f++)
		(*el)->f = check_num(f);
	else if (!ft_strncmp("C", f, 1) && num_val(f) && (*v)->c++)
		(*el)->c = check_num(f);
	else
		return (false);
	return (true);	
}

bool	valid_el(t_v *v)
{
	if (v->n != 1)
		ft_putstr_fd("Error in elements\n", 2);
	else if (v->s != 1)
		ft_putstr_fd("Error in elements\n", 2);
	else if (v->w != 1)
		ft_putstr_fd("Error in elements\n", 2);
	else if (v->e != 1)
		ft_putstr_fd("Error in elements\n", 2);
	else if (v->f != 1)
		ft_putstr_fd("Error in elements\n", 2);
	else if (v->c != 1)
		ft_putstr_fd("Error in elements\n", 2);
	else
		return (true);
	return (false);
}