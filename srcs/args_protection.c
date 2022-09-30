/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_protection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <dduraku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:20:41 by dduraku           #+#    #+#             */
/*   Updated: 2022/08/05 15:59:32 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_infile_exists(const char *filename)
{
	return (access(filename, F_OK) == 0);
}

int	ft_command_exists(const char *path_to_command)
{
	return (access(path_to_command, F_OK));
}

static void	command_error(char *command)
{
	write(2, command, sizeof(command));
	write(2, " : command not found\n", 21);
}

char	**get_command(char *command, char *path)
{
	t_struct	va;

	va.full_cmd = ft_split(command, ' ');
	va.path_before_cmd = ft_split(path, ':');
	va.i = 0;
	while (va.path_before_cmd[va.i])
	{
		va.cmddup = ft_strdup(va.path_before_cmd[va.i]);
		va.cmdjoin = ft_strjoin(va.cmddup, "/");
		va.cmdjoin = ft_strjoin(va.cmdjoin, va.full_cmd[0]);
		if (ft_command_exists(va.cmdjoin) == 0)
		{
			free(va.full_cmd[0]);
			va.full_cmd[0] = ft_strdup(va.cmdjoin);
			free_tab(va.path_before_cmd);
			free(va.cmdjoin);
			return (va.full_cmd);
		}
		free(va.cmdjoin);
		va.i++;
	}
	free_tab(va.path_before_cmd);
	free_tab(va.full_cmd);
	command_error(command);
	exit(2);
}

void	ft_arguments_protection(char **argv, char *first_cmd, char *snd_cmd)
{
	if (!ft_infile_exists(argv[1]))
	{
		printf("Infile does not exists\n");
		exit(EXIT_FAILURE);
	}
	if (ft_command_exists(first_cmd) != 0)
	{
		printf("Command : %s not found\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	else if (ft_command_exists(snd_cmd) != 0)
	{
		printf("Command : %s not found\n", argv[3]);
		exit(EXIT_FAILURE);
	}
}
