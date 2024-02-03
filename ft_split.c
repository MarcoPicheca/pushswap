/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapichec <mapichec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:24:41 by mapichec          #+#    #+#             */
/*   Updated: 2024/02/02 12:35:36 by mapichec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	boolean;

	i = 0;
	boolean = 0;
	while (*s)
	{
		if (*s != c && boolean == 0)
		{
			boolean = 1;
			i++;
		}
		else if (*s == c)
			boolean = 0;
		s++;
	}
	return (i);
}

static char	*duplica(const char *s, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		indice;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !(split))
		return (NULL);
	i = 0;
	j = 0;
	indice = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && indice < 0)
			indice = i;
		else if ((s[i] == c || i == ft_strlen(s)) && indice >= 0)
		{
			split[j++] = duplica(s, indice, i);
			indice = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
