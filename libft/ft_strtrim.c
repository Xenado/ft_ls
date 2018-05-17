/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:47:28 by jcaille           #+#    #+#             */
/*   Updated: 2017/11/16 15:59:06 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	size;
	int		i;
	int		start;

	i = -1;
	start = -1;
	str = NULL;
	if (s)
	{
		size = ft_strlen(s);
		while (s[size - 1] == ' ' || s[size - 1] == '\n' || s[size - 1]
				== '\t')
			size--;
		while ((s[++start] == ' ' || s[start] == '\n' || s[start] == '\t')
				&& size > 0)
			size--;
		if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		while (++i < (int)size)
			str[i] = s[start + i];
		str[i] = '\0';
	}
	return (str);
}
