/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 04:51:05 by bbixby            #+#    #+#             */
/*   Updated: 2018/11/06 04:51:07 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

void		ft_freepieces(char **pieces, int count)
{
	int		i;

	i = -1;
	while (++i < count)
		free(pieces[i]);
	free(pieces);
}

void		ft_freepieces2(t_piece **piecearr, int count)
{
	int		i;

	i = -1;
	while (++i < count)
		free(piecearr[i]);
	free(piecearr);
}

void		ft_freeboard(char ***board, int boardsize)
{
	int		i;

	i = -1;
	while (++i < boardsize)
		free((*board)[i]);
	free((*board));
}
