/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <dduraku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:58:43 by dduraku           #+#    #+#             */
/*   Updated: 2022/07/28 19:58:10 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// ============ALLOWED FUNCTIONS============
// External functions allowed :
// open, close, read, write, malloc, free, perror
// strerror, access, dup, dup2, execve, exit, fork,
// pipe, unlink, wait, waitpid


//===============TO DO LIST=================
// LEGENDE : [√] = Done, [X] = TODO, [-] = Almost
// Commencer par gerer les arguments															[X]
// Utiliser la fonction access() pour voir si le infile existe									[√]
// ENVP PARSING : garder la string "PATH=" 														[√]
// ENVP PARSING : split les commandes 															[√]
// ENVP PARSING : split les differents path au niveau du ":" pour chaque commande				[X]
// ENVP PARSING : Join le PATH avec les commandes												[X]
// ENVP PARSING : CHECK avec acces()															[X]
// ENVP PARSING : chercher si les commandes (grep, ls, ...) existent [/!\]						[-]


#include "pipex.h"

char	*ft_get_path(char **envp)
{
	int	i;
	char *path;

	i = 0;
	while (envp[i])
	{
		if ((path = ft_strnstr(envp[i], "PATH=", 5)))
			return (path + 5);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	char *path;
	char *cmd_path;
	
	path = ft_get_path(envp);
	cmd_path = ft_path_to_command(path, argv);
	ft_arguments_protection(argc, argv, cmd_path);
	return (0);
}