/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:59:29 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/11/02 20:36:33 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list **stash, t_list *new)
{
	t_list	*p;

	if (!(*stash))
		(*stash) = new;
	else
	{
		p = (*stash);
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*p;

	p = lst;
	if (!lst)
		return (NULL);
	while (p->next != NULL)
		p = p->next;
	return (p);
}
/**
** check for a newline character in the given linked list.
**/
int	found_new_line(t_list *stow)
{
	t_list	*last;
	int		i;

	i = 0;
	if (!stow)
		return (0);
	last = ft_lstlast(stow);
	while (last->stash[i])
	{
		if (last->stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
/**
** this func acess at the list for found the lenght of line
**/
int	get_lenght(t_list *stow)
{
	int	lenght;
	int	i;

	lenght = 0;
	i = 0;
	while (stow)
	{
		i = 0;
		while (stow->stash[i])
		{
			if (stow->stash[i] == '\n')
			{
				lenght++;
				return (lenght);
			}
			lenght++;
			i++;
		}
		stow = stow->next;
	}
	return (lenght);
}

void	ft_lstclear(t_list *stow)
{
	t_list	*save;

	while (stow)
	{
		save = stow;
		stow = stow->next;
		free(save->stash);
		free(save);
	}
	stow = NULL;
}
