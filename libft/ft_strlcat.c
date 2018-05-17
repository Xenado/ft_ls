/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:53:10 by jcaille           #+#    #+#             */
/*   Updated: 2017/11/13 16:50:39 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (i < (int)size && dst[i])
		i++;
	len = i;
	i--;
	while (++i < (int)size - 1 && src[i - len])
		dst[i] = src[i - len];
	if (i != (int)size)
		dst[i] = '\0';
	return (len + ft_strlen(src));
}
