/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 05:29:22 by bbixby            #+#    #+#             */
/*   Updated: 2018/11/04 05:29:24 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

extern t_queue	*g_tail;

t_queue			*ft_create_elem(int *isnbc)
{
	t_queue		*tmp;

	tmp = NULL;
	tmp = malloc(sizeof(t_queue));
	if (tmp)
	{
		tmp->isnbc = isnbc;
		tmp->next = NULL;
	}
	return (tmp);
}

/*
** int *isnbc is an array to limit params, isnbc[0] is index, i
** snbc[1] is start index and
** isnbc[2] is newboard isnbc[3] is board size isnbc[4] is count
*/

void			ft_queue_push_back(t_queue **begin_queue, int *isnbc)
{
	t_queue		*queue;

	queue = *begin_queue;
	if (queue)
	{
		g_tail->next = ft_create_elem(isnbc);
		g_tail = g_tail->next;
	}
	else
	{
		*begin_queue = ft_create_elem(isnbc);
		g_tail = *begin_queue;
	}
}
