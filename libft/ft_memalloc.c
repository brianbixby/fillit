/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:05:17 by bbixby            #+#    #+#             */
/*   Updated: 2018/09/19 12:03:53 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void		*ft_memalloc(size_t size)
{
	void			*vptr;
	unsigned char	*chptr;

	if (!(vptr = (void *)malloc(sizeof(*vptr) * size)))
		return (NULL);
	chptr = (unsigned char *)vptr;
	while (size--)
		*chptr++ = (unsigned char)0;
	return (vptr);
}
