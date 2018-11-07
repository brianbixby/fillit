/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 22:23:25 by bbixby            #+#    #+#             */
/*   Updated: 2018/11/03 22:24:20 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

int			ft_min(int a, int b, int c, int d)
{
	int		min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	if (d < min)
		min = d;
	return (min);
}

int			ft_max(int a, int b, int c, int d)
{
	int		max;

	max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	if (d > max)
		max = d;
	return (max);
}

int			*ft_setintarr(int *arr, int num, int count)
{
	int		i;

	i = -1;
	while (++i < count)
		arr[i] = num;
	return (arr);
}

int			ft_alllong(char **board, int boardsize)
{
	int	i;
	int	j;

	i = -1;
	while (++i < boardsize)
	{
		j = -1;
		while (++j < boardsize)
		{
			if (board[i][j] == '.')
				return (2);
		}
	}
	return (-1);
}
