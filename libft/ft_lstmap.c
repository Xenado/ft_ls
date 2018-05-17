/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaille <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:07:46 by jcaille           #+#    #+#             */
/*   Updated: 2017/11/15 18:01:38 by jcaille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*begin;

	if (lst)
	{
		newlst = f(lst);
		begin = newlst;
	}
	else
		return (NULL);
	while (lst->next)
	{
		newlst->next = f(lst->next);
		newlst = newlst->next;
		lst = lst->next;
	}
	newlst->next = NULL;
	return (begin);
}
