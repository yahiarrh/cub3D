/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrrhaibi <yrrhaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:53:22 by yrrhaibi          #+#    #+#             */
/*   Updated: 2023/12/10 18:30:55 by yrrhaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**dealc(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	s = NULL;
	return (s);
}

static	int	c_w(char const *s, char c)
{
	int	j;
	int	num;
	int	m;

	m = 0;
	j = 0;
	num = 0;
	while (s[j])
	{
		if (s[j] != c)
		{
			m++;
			while (s[j] && s[j] != c)
				j++;
		}
		j++;
	}
	if (num == 0 && m != 0)
		num++;
	return (m);
}

static	char	*give_word(char const *s, char c)
{
	char	*ret;
	int		f;

	f = 0;
	while (s[f] && s[f] != c)
		f++;
	ret = (char *)get_ptr(f + 2, 1);
	if (!ret)
		return (NULL);
	f = 0;
	while (s[f] != c && s[f])
	{
		ret[f] = s[f];
		f++;
	}
	ret[f] = '\0';
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**word;
	size_t	count;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	count = c_w(s, c);
	word = get_ptr((sizeof(char *) * (count + 1)), 1);
	if (!word)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			word[i++] = give_word(s, c);
			if (!*word)
				return (dealc(word, i));
			while (*s && *s != c)
				s++;
		}
	}
	return (word[i] = NULL, word);
}
