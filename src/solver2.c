/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 14:06:24 by bbixby            #+#    #+#             */
/*   Updated: 2018/11/04 14:06:25 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

extern t_queue	*g_tail;

int		ft_printresults(char **board, int boardsize)
{
	int		i;
	int		j;

	i = -1;
	while (++i < boardsize)
	{
		j = -1;
		while (++j < boardsize)
			write(1, &board[i][j], 1);
		write(1, "\n", 1);
	}
	ft_freeboard(&board, boardsize);
	return (0);
}

int		removepiece(char **board, int idx, int boardsize, int count)
{
	int	row;
	int	col;
	int startidxrc[2];

	row = -1;
	while (++row < boardsize && count < 4)
	{
		col = -1;
		while (++col < boardsize && count < 4)
		{
			if (board[row][col] == 'A' + idx)
			{
				if (count == 0)
				{
					startidxrc[0] = row;
					startidxrc[1] = col;
				}
				if (col < startidxrc[1])
					startidxrc[1] = col;
				board[row][col] = '.';
				count++;
			}
		}
	}
	return (startidxrc[0] * boardsize + startidxrc[1] + 1);
}

int		playpiecehelper(char **board, t_piece **piecearr, int *isnbc, int rc[2])
{
	board[rc[0] + piecearr[isnbc[0]]->pt[0] / 10][rc[1] +
		piecearr[isnbc[0]]->pt[0] % 10] = 'A' + isnbc[0];
	board[rc[0] + piecearr[isnbc[0]]->pt[1] / 10][rc[1] +
		piecearr[isnbc[0]]->pt[1] % 10] = 'A' + isnbc[0];
	board[rc[0] + piecearr[isnbc[0]]->pt[2] / 10][rc[1] +
		piecearr[isnbc[0]]->pt[2] % 10] = 'A' + isnbc[0];
	board[rc[0] + piecearr[isnbc[0]]->pt[3] / 10][rc[1] +
		piecearr[isnbc[0]]->pt[3] % 10] = 'A' + isnbc[0];
	return (1);
}

int		playpiece(char **board, t_piece **piecearr, int *isnbc, int flag)
{
	int	rc[2];

	rc[0] = isnbc[1] / isnbc[3] - 1;
	while (++rc[0] < isnbc[3])
	{
		rc[1] = (!flag ? (isnbc[1] % isnbc[3] - 1) : (-1));
		while (++rc[1] < isnbc[3])
		{
			if (rc[1] + piecearr[isnbc[0]]->w <= isnbc[3] && rc[0] +
				piecearr[isnbc[0]]->h <= isnbc[3] &&
				(board[rc[0] + piecearr[isnbc[0]]->pt[0] / 10][rc[1] +
				piecearr[isnbc[0]]->pt[0] % 10] == '.') &&
				(board[rc[0] + piecearr[isnbc[0]]->pt[1] / 10][rc[1] +
				piecearr[isnbc[0]]->pt[1] % 10] == '.') &&
				(board[rc[0] + piecearr[isnbc[0]]->pt[2] / 10][rc[1] +
				piecearr[isnbc[0]]->pt[2] % 10] == '.') &&
				(board[rc[0] + piecearr[isnbc[0]]->pt[3] / 10][rc[1] +
				piecearr[isnbc[0]]->pt[3] % 10] == '.'))
				return (playpiecehelper(board, piecearr, isnbc, rc));
		}
		flag = 1;
	}
	return (0);
}

/*
** TO DO: free each cell in board, free board
*/

int		ft_startsolving(char **board, t_piece **piecearr, int *isnbc, int count)
{
	if (playpiece(board, piecearr, isnbc, 0))
	{
		isnbc[1] = 0;
		isnbc[0]++;
	}
	else
	{
		isnbc[0]--;
		if (isnbc[0] >= 0)
			isnbc[1] = removepiece(board, isnbc[0], isnbc[3], 0);
	}
	if (isnbc[0] < 0 || count > 1000000)
	{
		isnbc[3] += 1;
		isnbc[0] = 0;
		isnbc[1] = 0;
		isnbc[2] = 1;
	}
	else if (isnbc[0] >= 0 && isnbc[0] < isnbc[4])
		isnbc[2] = 0;
	else
		return (ft_printresults(board, isnbc[3]));
	g_tail->next = ft_create_elem(isnbc);
	g_tail = g_tail->next;
	return (0);
}
