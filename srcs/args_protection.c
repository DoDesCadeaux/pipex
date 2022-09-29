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

char	**get_command(char *command, char *path)
{
	int		i;
	char	**full_cmd;
	char	**path_before_cmd;

	full_cmd = ft_split(command, ' ');
	path_before_cmd = ft_split(path, ':');
	i = 0;
	while (path_before_cmd[i])
	{
		path_before_cmd[i] = ft_strjoin(path_before_cmd[i], "/");
		path_before_cmd[i] = ft_strjoin(path_before_cmd[i], full_cmd[0]);
		if (ft_command_exists(path_before_cmd[i]) == 0)
		{
			full_cmd[0] = ft_strdup(path_before_cmd[i]);
			return (full_cmd);
		}
		else
			free(path_before_cmd[i]);
		i++;
	}
	return (NULL);
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
