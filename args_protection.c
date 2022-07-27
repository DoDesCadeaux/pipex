/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_protection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <dduraku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:20:41 by dduraku           #+#    #+#             */
/*   Updated: 2022/07/27 16:57:39 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_nb_of_arguments(int argc)
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

// int		ft_command_exists(const char *command_name)
// {
	
// }

void	ft_arguments_protection(int argc, char **argv)
{
	ft_nb_of_arguments(argc);
	if (ft_infile_exists(argv[1]))
		return ;
	else
	{
		printf("Infile does not exists\n");
		exit(EXIT_FAILURE);
	}
}