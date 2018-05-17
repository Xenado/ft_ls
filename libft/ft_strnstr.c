/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:03:59 by jcaille           #+#    #+#             */
/*   Updated: 2017/11/13 18:28:27 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		i2;
	size_t	occ;

	i = -1;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[++i] && i < (int)len)
	{
		i2 = -1;
		occ = ft_strlen(needle);
		while (needle[++i2] && haystack[i + i2] && i + i2 < (int)len)
			if (needle[i2] == haystack[i + i2])
				occ--;
		if (!occ)
			return (&((char *)haystack)[i]);
	}
	return (NULL);
}
