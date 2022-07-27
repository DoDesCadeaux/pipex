/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <dduraku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:58:43 by dduraku           #+#    #+#             */
/*   Updated: 2022/07/27 17:02:55 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// ============ALLOWED FUNCTIONS============
// External functions allowed :
// open, close, read, write, malloc, free, perror
// strerror, access, dup, dup2, execve, exit, fork,
// pipe, unlink, wait, waitpid


//===============TO DO LIST=================
// Commencer par gerer les arguments															[X]
// Utiliser la fonction access() pour voir si le infile existe									[√]
// ENVP PARSING : garder la string "PATH=" 														[X]
// ENVP PARSING : split les commandes 															[X]
// ENVP PARSING : split les differents path au niveau du ":" pour chaque commande				[X]
// ENVP PARSING : Join le PATH avec les commandes												[X]
// ENVP PARSING : CHECK avec acces()															[X]
// ENVP PARSING : chercher si les commandes (grep, ls, ...) existent [/!\]						[X]


#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	x;
	
	x = 0;
	while (envp[x])
	{
		printf("%s\n", envp[x]);
		x++;
	}
	ft_arguments_protection(argc, argv);
	 return (0);
}
