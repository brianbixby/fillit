/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:58:12 by bbixby            #+#    #+#             */
/*   Updated: 2018/09/16 23:31:16 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;
	int		j;

	ch = (char)c;
	i = 0;
	j = -1;
	while (s[i])
	{
		if (s[i] == ch)
			j = i;
		i++;
	}
	if (s[i] == ch)
		return ((char *)(s + i));
	return (j < 0 ? (NULL) : ((char *)(s + j)));
}
