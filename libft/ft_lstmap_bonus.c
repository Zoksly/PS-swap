/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblanco- <vblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 23:47:32 by vblanco-          #+#    #+#             */
/*   Updated: 2025/11/21 17:20:30 by vblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*newdest;
	void	*new;

	if (lst == NULL || f == NULL)
		return (NULL);
	dest = NULL;
	newdest = NULL;
	while (lst != NULL)
	{
		new = f(lst -> content);
		newdest = ft_lstnew(new);
		if (newdest == NULL)
		{
			del(newdest);
			ft_lstclear(&dest, del);
			return (NULL);
		}
		ft_lstadd_back(&dest, newdest);
		lst = lst -> next;
	}
	return (dest);
}
