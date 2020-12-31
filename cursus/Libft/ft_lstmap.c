/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbaek <jimbaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:06:02 by jimbaek           #+#    #+#             */
/*   Updated: 2021/01/01 00:49:53 by jimbaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*orilst;
	t_list	*newlst;
	t_list	*new;
	void	*succ;

	orilst = lst;
	newlst = NULL;
	while (orilst)
	{
		if ((succ = f(orilst->content)))
		{
			if ((new = ft_lstnew(succ)))
			{
				ft_lstadd_back(&newlst, new);
			}
			else
			{
				ft_lstclear(&orilst, del);
				return (NULL);
			}
		}
		orilst = orilst->next;
	}
	return newlst;
}
