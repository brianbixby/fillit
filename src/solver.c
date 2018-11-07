/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 01:13:39 by bbixby            #+#    #+#             */
/*   Updated: 2018/11/03 01:13:41 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#define ABS(i)	((i < 0) ? (-i) : (i))

t_queue		*g_tail;

void	ft_createpieceshelper(t_piece **arr, int i, int minmaxwh[4])
{
	minmaxwh[0] = ft_min(arr[i]->pt[0] % 10, arr[i]->pt[1] % 10,
							arr[i]->pt[2] % 10, arr[i]->pt[3] % 10);
	minmaxwh[1] = ft_max(arr[i]->pt[0] % 10, arr[i]->pt[1] % 10,
							arr[i]->pt[2] % 10, arr[i]->pt[3] % 10);
	minmaxwh[2] = ft_min(arr[i]->pt[0] / 10, arr[i]->pt[1] / 10,
							arr[i]->pt[2] / 10, arr[i]->pt[3] / 10);
	minmaxwh[3] = ft_max(arr[i]->pt[0] / 10, arr[i]->pt[1] / 10,
							arr[i]->pt[2] / 10, arr[i]->pt[3] / 10);
	arr[i]->w = ABS((minmaxwh[1] - minmaxwh[0])) + 1;
	arr[i]->h = ABS((minmaxwh[3] - minmaxwh[2])) + 1;
	while (arr[i]->pt[0] >= 10)
	{
		arr[i]->pt[0] -= 10;
		arr[i]->pt[1] -= 10;
		arr[i]->pt[2] -= 10;
		arr[i]->pt[3] -= 10;
	}
	while (arr[i]->pt[0] % 10 != 0 && arr[i]->pt[1] % 10 != 0 &&
		arr[i]->pt[2] % 10 != 0 && arr[i]->pt[3] % 10 != 0)
	{
		arr[i]->pt[0] -= 1;
		arr[i]->pt[1] -= 1;
		arr[i]->pt[2] -= 1;
		arr[i]->pt[3] -= 1;
	}
}

void	ft_createpieces(char **pieces, int count, t_piece **arr, int i)
{
	int j;
	int hashcnt;
	int temp;
	int	minmaxwh[4];

	while (++i < count)
	{
		j = -1;
		hashcnt = 0;
		while (++j < 20)
		{
			if (pieces[i][j] == '#')
			{
				if (j < 9)
					temp = (j < 4 ? (10 + j) : (20 + j - 5));
				else
					temp = (j < 14 ? (30 + j - 10) : (40 + j - 15));
				arr[i]->pt[hashcnt] = temp;
				hashcnt++;
			}
		}
		ft_createpieceshelper(arr, i, minmaxwh);
	}
	ft_freepieces(pieces, count);
}

/*
** initializes board or increases board size,
** newsize = 0 initializes a new board
** else pass this function the size you want it to be in new size
*/

int		newboard(char ***board, int count, int newsize, int i)
{
	int	h[2];

	h[0] = -1;
	count *= 4;
	if (newsize == 0)
		while (i * i < count)
			i += 1;
	else
	{
		i = newsize;
		ft_freeboard(board, newsize - 1);
	}
	if (!((*board) = (char **)malloc(sizeof(char *) * (i))))
		return (0);
	while (++h[0] < i)
		if (!((*board)[h[0]] = (char *)malloc(sizeof(char) * i)))
			return (0);
	h[0] = -1;
	while (++h[0] < i)
	{
		h[1] = -1;
		while (++h[1] < i)
			(*board)[h[0]][h[1]] = '.';
	}
	return (i);
}

void	ft_solvehandler(char **board, t_piece **piecearr, t_queue *q)
{
	t_queue	*temp;
	int		count;

	temp = NULL;
	count = 0;
	if (q)
	{
		while (q)
		{
			if (q->isnbc[2])
			{
				newboard(&board, q->isnbc[4], q->isnbc[3], 2);
				count = 0;
			}
			ft_startsolving(board, piecearr, q->isnbc, count);
			temp = q;
			q = q->next;
			free(temp);
			count++;
		}
	}
}

/*
** TO DO: free pieces below after piecearr created
*/

int		ft_solver(char **pieces, int count)
{
	char	**board;
	t_piece	**piecearr;
	t_queue	*queue;
	int		isnbc[5];

	isnbc[0] = 0;
	isnbc[1] = 0;
	isnbc[2] = 0;
	isnbc[3] = newboard(&board, count, 0, 2);
	isnbc[4] = count;
	count = -1;
	if (!(piecearr = (t_piece **)malloc(sizeof(t_piece *) * isnbc[4])))
		return (0);
	while (++count < isnbc[4])
		if (!((piecearr)[count] = (t_piece *)malloc(sizeof(t_piece))))
			return (0);
	queue = NULL;
	g_tail = queue;
	ft_createpieces(pieces, isnbc[4], piecearr, -1);
	ft_queue_push_back(&queue, isnbc);
	ft_solvehandler(board, piecearr, queue);
	ft_freepieces2(piecearr, isnbc[4]);
	return (0);
}
