/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:26:16 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/11/09 11:58:56 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

#include <fcntl.h>
#include <stdbool.h>
#include "libft/libft.h"

typedef struct s_file
{
	char	*buff;
	char	*s;
	char	*tmp;
	int		fd;
	int		n;
}t_file;

typedef struct s_elements
{
	char	*n;
	char	*s;
	char	*e;
	char	*w;
	int		f;
	int		c;
}t_elements;


#endif