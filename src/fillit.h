/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:08:36 by bbixby            #+#    #+#             */
/*   Updated: 2018/11/01 14:08:37 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_piece
{
	int				w;
	int				h;
	int				pt[4];
}					t_piece;

typedef struct		s_queue
{
	struct s_queue	*next;
	int				*isnbc;
}					t_queue;

/*
** fillit.c
*/
int					*ft_setarr(int *arr);
char				*ft_readfile(char *file, int *arr, char *str);
int					ft_readandverify(char *argv, char ***pieces, int *arr);

/*
** verification.c
*/
int					ft_error(char **pieces, int count, char *str);
void				ft_mallocpieces(char ***pieces, int count);
int					tetriminocheck(char *piece);
int					ft_verify(char *str, int *arr, char ***pieces);

/*
** solver.c
*/
void				ft_createpieceshelper(t_piece **arr, int i,
									int minmaxwh[4]);
void				ft_createpieces(char **pieces, int count, t_piece **arr,
									int i);
int					newboard(char ***board, int count, int newsize, int i);
void				ft_solvehandler(char **board, t_piece **piecearr,
									t_queue *q);
int					ft_solver(char **pieces, int count);

/*
** solver2.c
*/
int					ft_printresults(char **board, int boardsize);
int					removepiece(char **board, int idx, int boardsize,
									int count);
int					playpiecehelper(char **board, t_piece **piecearr,
									int *isnbc, int rc[2]);
int					playpiece(char **board, t_piece **piecearr, int *isnbc,
									int flag);
int					ft_startsolving(char **board, t_piece **piecearr,
									int *isnbc, int count);

/*
** queue.c
*/
t_queue				*ft_create_elem(int *isnbc);
void				ft_queue_push_back(t_queue **begin_queue, int *isnbc);

/*
** helpers.c
*/
int					ft_min(int a, int b, int c, int d);
int					ft_max(int a, int b, int c, int d);
int					*ft_setintarr(int *arr, int num, int count);

/*
** free.c
*/
void				ft_freepieces(char **pieces, int count);
void				ft_freeboard(char ***board, int boardsize);
void				ft_freepieces2(t_piece	**piecearr, int count);

#endif
