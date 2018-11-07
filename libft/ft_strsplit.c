/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbixby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:13:53 by bbixby            #+#    #+#             */
/*   Updated: 2018/09/16 23:38:31 by bbixby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static char		*ft_substrdup(const char *s1, char c)
{
	char		*ptr;
	size_t		j;
	size_t		i;

	j = 0;
	while (s1[j] && s1[j] != c)
		j++;
	if (!(ptr = (char *)malloc(sizeof(*ptr) * (j + 1))))
		return (NULL);
	i = 0;
	while (j--)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int		ft_substrcount(char const *s, char c)
{
	int			i;
	int			flag;

	i = 0;
	flag = 1;
	if (!s)
		return (0);
	while (*s)
	{
		if (flag && *s != c)
		{
			flag = 0;
			i += 1;
		}
		else if (!flag && *s == c)
			flag = 1;
		s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int			substrings;
	char		**arr;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	substrings = ft_substrcount(s, c);
	if (!(arr = (char **)malloc(sizeof(*arr) * (substrings + 1))))
		return (NULL);
	while (i < substrings)
	{
		while (s[j] == c && s[j])
			j++;
		arr[i] = ft_substrdup((s + j), c);
		i++;
		while (s[j] != c && s[j])
			j++;
	}
	arr[i] = NULL;
	return (arr);
}
