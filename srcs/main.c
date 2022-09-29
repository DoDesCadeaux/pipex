/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <dduraku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:58:43 by dduraku           #+#    #+#             */
/*   Updated: 2022/08/05 17:44:39 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		path = ft_strnstr(envp[i], "PATH=", 5);
		if (path != 0)
			return (path + 5);
		i++;
	}
	return (NULL);
}

void	ft_nb_of_arguments(int argc)
{
	if (argc != 5)
	{
		printf("You must have 5 arguments\n");
		exit(EXIT_FAILURE);
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;
	char	**first_cmd;
	char	**snd_cmd;

	ft_nb_of_arguments(argc);
	path = ft_get_path(envp);
	first_cmd = get_command(argv[2], path);
	snd_cmd = get_command(argv[3], path);
	ft_arguments_protection(argv, first_cmd[0], snd_cmd[0]);
	ft_pipex(argv, envp, first_cmd, snd_cmd);
	return (0);
}
