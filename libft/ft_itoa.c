/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:14:26 by bbixby            #+#    #+#             */
/*   Updated: 2018/09/12 07:19:20 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static size_t	ft_int_len(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	temp;

	len = ft_int_len(n);
	temp = n;
	if (n < 0)
	{
		temp = -n;
		len += 1;
	}
	if (!(str = ft_strnew(len)))
		return (0);
	str[--len] = temp % 10 + '0';
	while (temp /= 10)
		str[--len] = temp % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
