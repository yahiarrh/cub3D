/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:21:40 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/11/09 15:34:33 by yrrhaibi         ###   ########.fr       */
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
		if (ft_atoi(f + i) > 255);
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
	while (s[i] == ' ')
		i++;
	if(s[i] )

}

void	if_elements(t_elements **el, char *f)
{
	while (*f)
	{
		if (!ft_strncmp("NO", f, 2) && valid_f(f + 2))
			(*el)->n = ft_substr(f, 0, ft_strchr(f, '\n'));
		else if (!ft_strncmp("SO", f, 2))
			(*el)->s = ft_substr(f, 0, ft_strchr(f, '\n'));
		else if (!ft_strncmp("WE", f, 2))
			(*el)->w = ft_substr(f, 0, ft_strchr(f, '\n'));
		else if (!ft_strncmp("EA", f, 2))
			(*el)->e = ft_substr(f, 0, ft_strchr(f, '\n'));
		else if (!ft_strncmp("F", f, 1) && num_val(f))
			(*el)->f = check_num(f);
		else if (!ft_strncmp("C", f, 1))
			(*el)->c = check_num(f);
		f++;
	}
}

t_elements	*map(char *f)
{
	t_elements	*el;
	int			i;

	i = 0;
	el = malloc(sizeof(t_elements));
	ft_memset(el, 0, sizeof(el));
	while (f[i])
	{
		while (f[i] != '\n')
			i++;
		while (f[i] == ' ')
			i++;
		if_elements(&el, f + i);
		i++;
	}
	return (el);
}

int	check_file(const char *file_name)
{
	t_file		f;
	t_elements	*e;

	f.fd = open(file_name, O_RDONLY);
	f.n = 1;
	if (f.fd < 0)
		return(0);
	f.s = NULL;
	while (f.n > 0)
	{
		f.buff = malloc(10);
		ft_memset(f.buff, 0, 10);
		f.n = read(f.fd, f.buff, 10);
		if (f.n < 0)
			return(free(f.buff), -1);
		f.tmp = f.s;
		f.s = ft_strjoin(f.s, f.buff);
		free(f.tmp);
		free(f.buff);
	}
	e = map(f.s);
}
