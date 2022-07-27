/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_intro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <dduraku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:58:43 by dduraku           #+#    #+#             */
/*   Updated: 2022/07/26 15:43:10 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

// External functions allowed :
// open, close, read, write, malloc, free, perror
// strerror, access, dup, dup2, execve, exit, fork,
// pipe, unlink, wait, waitpid

int	main(void)
{
	int	fd[2];
	int	id;
	int	x;
	int	y;

	if (pipe(fd) == -1)
	{
		printf("Error while opening a pipe\n");
		return (1);
	}
	id = fork();
	if (id == 0)
	{
		printf("Input a number : ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("Got from child process : [%d]\n", y);
	}
	return (0);
}
