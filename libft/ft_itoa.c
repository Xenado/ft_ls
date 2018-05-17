/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:51:05 by jcaille           #+#    #+#             */
/*   Updated: 2017/11/15 14:49:28 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		size_nbr(const int n, int *nega)
{
	long int	nbr;
	int			size;

	size = 0;
	nbr = (long int)n;
	if (nbr < 0)
	{
		*nega = 1;
		nbr = -nbr;
	}
	while (nbr)
	{
		size++;
		nbr /= 10;
	}
	if (n == 0)
		size = 1;
	return (size + (*nega));
}

char			*ft_itoa(int n)
{
	char		*str;
	long int	nbr;
	int			nega;
	int			i;

	nega = 0;
	i = size_nbr(n, &nega);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	nbr = (long int)n;
	if (nega)
		nbr = -nbr;
	str[i] = '\0';
	while (nbr)
	{
		str[i-- - 1] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (!n)
		str[0] = '0';
	if (nega)
		str[0] = '-';
	return (str);
}
