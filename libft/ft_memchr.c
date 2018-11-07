/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:47:30 by bbixby            #+#    #+#             */
/*   Updated: 2018/09/10 23:10:10 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sptr;
	int				i;
	unsigned char	ch;

	sptr = (unsigned char *)s;
	i = 0;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*(sptr + i) == ch)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
