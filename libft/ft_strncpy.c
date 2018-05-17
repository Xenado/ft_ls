/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:03:40 by jcaille           #+#    #+#             */
/*   Updated: 2017/11/15 15:49:48 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int		i;

	i = -1;
	while (++i < (int)len && src[i])
		dst[i] = src[i];
	i--;
	while (++i < (int)len)
		dst[i] = '\0';
	return (dst);
}
