/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:27:40 by jcaille           #+#    #+#             */
/*   Updated: 2017/11/15 18:49:07 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = -1;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (s)
	{
		while (++i < (int)len)
			str[i] = s[start + i];
		str[i] = '\0';
	}
	return (str);
}
