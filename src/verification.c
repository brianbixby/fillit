/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:46:57 by bbixby            #+#    #+#             */
/*   Updated: 2018/11/01 14:46:59 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

int			ft_error(char **pieces, int count, char *str)
{
	ft_freepieces(pieces, count);
	free(str);
	ft_putstr("error\n");
	return (0);
}

void		ft_mallocpieces(char ***pieces, int count)
{
	int		i;

	i = -1;
	if (!((*pieces) = (char **)malloc(sizeof(char *) * (count + 1))))
		return ;
	while (++i < count)
		if (!((*pieces)[i] = (char *)malloc(sizeof(char) * (21))))
			return ;
	(*pieces)[i] = NULL;
}

/*
** helper function for ft_verify checks to make all tetriminos are touching
** needs at least 6 sides touching
*/

int			tetriminocheck(char *piece)
{
	int	i;
	int	touching;

	i = -1;
	touching = 0;
	while (piece[++i])
	{
		if (piece[i] == '#')
		{
			if ((i - 1 >= 0 ? (piece[i - 1] == '#') : (0)))
				touching++;
			if (piece[i + 1] == '#')
				touching++;
			if (i - 5 >= 0 ? (piece[i - 5] == '#') : (0))
				touching++;
			if (i + 5 <= 20 ? (piece[i + 5] == '#') : (0))
				touching++;
		}
	}
	return (touching >= 6 ? (1) : (0));
}

/*
** arr: arr[0] total number of tetris pieces, goes up to 26
** arr: arr[1] represents position in tetris piece, goes up to 21
** arr: arr[2] represents current position in str param, goes up to 544
** arr: arr[3] represents '#' count in current tetris piece
** arr: arr[4] reps single tetis piece, goes up to number of tetris pieces
*/

int			ft_verify(char *str, int *arr, char ***pieces)
{
	while (++arr[4] < arr[0])
	{
		arr[1] = -1;
		arr[3] = 0;
		while (++arr[1] < 20 && str[arr[2]] != '\0')
		{
			if (!(((arr[1] + 1) % 5 != 0 && (str[arr[2]] == '#' || str[arr[2]]
				== '.')) || ((arr[1] + 1) % 5 == 0 && str[arr[2]] == '\n')))
				return (ft_error((*pieces), arr[0], str));
			if (str[arr[2]] == '#')
				arr[3]++;
			(*pieces)[arr[4]][arr[1]] = str[arr[2]];
			arr[2]++;
		}
		if (!str[arr[2]])
			(*pieces)[arr[4]][19] = '\n';
		(*pieces)[arr[4]][20] = '\0';
		if ((str[arr[2]] != '\0' && str[arr[2]] != '\n') || arr[3] != 4
			|| !tetriminocheck((*pieces)[arr[4]]))
			return (ft_error((*pieces), arr[0], str));
		arr[2]++;
	}
	free(str);
	return (1);
}
