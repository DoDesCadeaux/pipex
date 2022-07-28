/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <dduraku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:09:06 by dduraku           #+#    #+#             */
/*   Updated: 2022/07/28 16:06:17 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_nb_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_free(char **matrice)
{
	int	i;

	i = 0;
	while (matrice[i])
	{
		free(matrice[i]);
		i++;
	}
	free(matrice);
}

static int	ft_fill_matrice(char *matrice, char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] && s[i] != c)
	{
		matrice[j] = s[i];
		i++;
		j++;
	}
	matrice[j] = '\0';
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	char	**matrice;

	if (!s)
		return (NULL);
	matrice = malloc(sizeof(char **) * (ft_nb_words(s, c) + 1));
	if (!matrice)
		return (NULL);
	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			matrice[word] = malloc(sizeof(char) * (ft_word_len(s + i, c) + 1));
			if (!matrice[word])
				ft_free(matrice);
			i = ft_fill_matrice(matrice[word++], s, c, i);
		}
		else
			i++;
	}
	matrice[word] = 0;
	return (matrice);
}
