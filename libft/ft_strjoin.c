/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:39:49 by jcaille           #+#    #+#             */
/*   Updated: 2017/11/16 15:54:53 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = -1;
	str = NULL;
	if (s1 && s2)
	{
		if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
							ft_strlen(s2) + 1))))
			return (NULL);
		str[0] = '\0';
		str = ft_strcat(str, s1);
		str = ft_strcat(str, s2);
	}
	return (str);
}
