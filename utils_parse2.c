/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:14:12 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/11/16 15:55:48 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	cha_v(char c)
{
	if (c != ' ' && c != '\t' && c != '1' && c != '0'
		&& c != 'N' && c != 'S' && c != 'W' && c != 'E' && c != '\n')
		return (false);
	return (true);
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

int	ft_start(char *f)
{
	int	i;

	i = 0;
	while (f[i] && (f[i] == ' ' || f[i] == '\t'))
		i++;
	i += 2;
	return (i);
}
