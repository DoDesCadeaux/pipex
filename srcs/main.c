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

static void	ft_nb_of_arguments_envp(int argc, char **envp)
{
	int	i;

	i = 0;
	if (!envp[i])
	{
		write(2, "We need Envp for this project\n", 30);
		exit(EXIT_FAILURE);
	}
	if (argc != 5)
	{
		write(2, "Must have 5 arguments\n", 22);
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

static void	protect_empy_cmd(char **argv)
{
	if (argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		write(2, "command line empty\n", 19);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char		*path;
	char		**first_cmd;
	char		**snd_cmd;

	protect_empy_cmd(argv);
	ft_nb_of_arguments_envp(argc, envp);
	path = ft_get_path(envp);
	if (!path)
	{
		write(2, "Path is unset\n", 14);
		exit(EXIT_FAILURE);
	}
	first_cmd = get_command(argv[2], path);
	snd_cmd = get_command(argv[3], path);
	ft_arguments_protection(argv, first_cmd[0], snd_cmd[0]);
	ft_pipex(argv, envp, first_cmd, snd_cmd);
	free_tab(first_cmd);
	free_tab(snd_cmd);
	return (0);
}
