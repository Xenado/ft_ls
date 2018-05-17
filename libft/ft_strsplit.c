/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:49:56 by jcaille           #+#    #+#             */
/*   Updated: 2017/11/16 16:59:07 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cwd(char const *s, char c)
{
	int		words;
	int		i;
	int		i2;

	words = 0;
	i = -1;
	while (s[++i])
	{
		i2 = 0;
		while (s[i + i2] != c && s[i + i2])
			i2++;
		if (i2)
		{
			words++;
			i += i2 - 1;
		}
	}
	return (words);
}

static int	*ft_lwd(char const *s, char c, int words)
{
	int		i;
	int		i2;
	int		word;
	int		*tab_len;

	tab_len = NULL;
	if (!(tab_len = (int *)malloc(sizeof(int) * words)))
		return (0);
	i = -1;
	word = 0;
	while (s[++i])
	{
		i2 = 0;
		while (s[i + i2] != c && s[i + i2])
			i2++;
		if (i2)
		{
			tab_len[word++] = i2;
			i += i2 - 1;
		}
	}
	return (tab_len);
}

static char	**ft_splitalloc(int nb_words, int *tab_len)
{
	int		wd;
	char	**words;

	wd = -1;
	words = NULL;
	if (!(words = (char **)malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	words[nb_words] = NULL;
	while (++wd < nb_words)
		if (!(words[wd] = (char *)malloc(sizeof(char) * (tab_len[wd] + 1))))
			return (NULL);
	free(tab_len);
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	int		word;
	int		i;
	int		i2;
	char	**words;

	words = NULL;
	if (s)
	{
		if (!(words = ft_splitalloc(ft_cwd(s, c), ft_lwd(s, c, ft_cwd(s, c)))))
			return (NULL);
		word = 0;
		i = -1;
		while (s[++i])
		{
			i2 = -1;
			while (s[++i2 + i] && s[i2 + i] != c)
				words[word][i2] = s[i2 + i];
			i2 ? words[word][i2] = '\0' : 0;
			i2 ? word++ : 0;
			i2 ? i += i2 - 1 : 0;
		}
	}
	return (words);
}
