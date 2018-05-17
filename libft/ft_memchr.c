/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:25:25 by jcaille           #+#    #+#             */
/*   Updated: 2017/11/13 14:32:39 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;

	i = -1;
	while (++i < (int)n)
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&((void *)s)[i]);
	return (NULL);
}
