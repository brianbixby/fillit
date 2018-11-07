/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:53:37 by bbixby            #+#    #+#             */
/*   Updated: 2018/09/10 14:38:04 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*dptr;
	const char	*sptr;
	size_t		dlen;

	dptr = dst;
	sptr = src;
	while (*dptr && dstsize)
	{
		dptr++;
		dstsize--;
	}
	dlen = dptr - dst;
	if (!dstsize)
		return (ft_strlen(src) + dlen);
	while (*sptr && dstsize-- > 1)
		*dptr++ = *sptr++;
	while (*sptr)
		sptr++;
	*dptr = '\0';
	return (dlen + (sptr - src));
}
