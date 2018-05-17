/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:31:17 by jcaille           #+#    #+#             */
/*   Updated: 2017/11/13 17:59:06 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		i2;
	int		occ;

	i = -1;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[++i])
	{
		occ = ft_strlen(needle);
		i2 = -1;
		while (needle[++i2] && haystack[i + i2] && occ)
			if (haystack[i + i2] == needle[i2])
				occ--;
		if (!occ)
			return (&((char *)haystack)[i]);
	}
	return (NULL);
}
