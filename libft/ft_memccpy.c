/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:46:51 by bbixby            #+#    #+#             */
/*   Updated: 2018/09/16 23:25:51 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dptr;
	unsigned char	*sptr;
	int				i;

	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	i = 0;
	while (n--)
	{
		*(dptr + i) = *(sptr + i);
		if (*(dptr + i) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
