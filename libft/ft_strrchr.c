/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:03:43 by jcaille           #+#    #+#             */
/*   Updated: 2017/11/13 17:27:35 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		occ;

	i = -1;
	occ = -1;
	while (s[++i])
		if (s[i] == (char)c)
			occ = i;
	if (!c)
		occ = i;
	return ((occ > -1) ? &((char *)s)[occ] : NULL);
}
