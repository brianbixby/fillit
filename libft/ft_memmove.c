/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:49:02 by bbixby            #+#    #+#             */
/*   Updated: 2018/09/16 23:28:04 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dptr;
	unsigned char	*sptr;

	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	if (dptr < sptr)
		while (len--)
			*(dptr++) = *(sptr++);
	else
		while (len--)
			*(dptr + len) = *(sptr + len);
	return (dst);
}
