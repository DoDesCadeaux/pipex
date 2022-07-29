/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_protection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <dduraku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:20:41 by dduraku           #+#    #+#             */
/*   Updated: 2022/07/29 17:02:52 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_nb_of_arguments(int argc)
{
	if (argc != 5)
	{
		printf("You must have 5 arguments\n");
		exit(EXIT_FAILURE);
	}	
}





int		ft_infile_exists(const char *filename)
{
	return (access(filename, F_OK) == 0);
}





int		ft_command_exists(const char *path_to_command)
{
	return (access(path_to_command, F_OK));
}

char  *ft_path_to_command(char *path_before_cmd, char *command) //verifier si les commandes passées en parametre existent
{
	int i;
	int j;
	int	k;
	char *cmd_path;
	
	i = 0;
	j = 0;
	k = 0;
	while (path_before_cmd[i])
	{
		if (path_before_cmd[i] == ':')
		{
			// printf("%s\n", path_before_cmd);
			cmd_path = malloc(sizeof(char) * ft_strlen(path_before_cmd) + 1); //RESIZE LE MALLOC !!!!
			if (!cmd_path)
				return NULL;
			j = 0;
			while (path_before_cmd[k] != ':' && path_before_cmd[k])
			{
				cmd_path[j] = path_before_cmd[k];
				j++;
				k++;
			}
			k++;
			cmd_path[j] = '\0';
			cmd_path = ft_strjoin(cmd_path, "/");
			cmd_path = ft_strjoin(cmd_path, command);
			if (ft_command_exists(cmd_path) != 0)
				free(cmd_path);	
			else
				return (cmd_path);	
		}
		i++;
	}
	cmd_path = *ft_split(cmd_path, ' ');
	return (cmd_path);
}




void	ft_arguments_protection(int argc, char **argv, char *first_cmd_path, char *snd_cmd_path)
{
	ft_nb_of_arguments(argc);
	if (!ft_infile_exists(argv[1]))
	{
		printf("Infile does not exists\n");
		exit(EXIT_FAILURE);
	}
	if (ft_command_exists(first_cmd_path) != 0)
	{
		printf("Command : %s not found\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	else if (ft_command_exists(snd_cmd_path) != 0)
	{
		printf("Command : %s not found\n", argv[3]);
		exit(EXIT_FAILURE);
	}
}