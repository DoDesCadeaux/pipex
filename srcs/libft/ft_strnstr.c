/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <dduraku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:57:05 by dduraju           #+#    #+#             */
/*   Updated: 2022/07/27 18:13:35 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		len_needle;
	char	*s;

	len_needle = ft_strlen(needle);
	s = (char *)haystack;
	i = 0;
	if (needle[0] == 0)
		return (s);
	while (s[i] && (i + (size_t) len_needle) <= len)
	{
		j = 0;
		while (s[i + j] == needle[j])
		{
			if (needle[j + 1] == 0)
				return (s + i);
			j++;
		}
		i++;
	}
	return (0);
}
