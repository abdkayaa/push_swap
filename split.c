/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaymazo@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:30:28 by okaymazo          #+#    #+#             */
/*   Updated: 2026/09/14 16:49:23 by okaymazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	w_count;
	int		inword;
	int		i;

	w_count = 0;
	inword = 0;
	i = 0;
	while (s[i])
	{
		if (!inword && s[i] != c)
		{
			inword = 1;
			w_count++;
		}
		else if (s[i] == c)
			inword = 0;
		i++;
	}
	return (w_count);
}

static char	**ft_free_tab(char **tab, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
	return (NULL);
}

static char	*ft_strdup_mine(const char *s, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

static char	**ft_extract_words(char **strs, char const *s, char c)
{
	size_t	start;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < ft_count_words(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		start = j;
		while (s[j] && s[j] != c)
			j++;
		strs[i] = ft_strdup_mine(s, start, j - start);
		if (!strs[i])
			return (ft_free_tab(strs, i));
		i++;
	}
	strs[i] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!strs)
		return (NULL);
	return (ft_extract_words(strs, s, c));
}
