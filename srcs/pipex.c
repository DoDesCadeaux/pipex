/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:18:15 by dduraku           #+#    #+#             */
/*   Updated: 2022/09/29 19:18:16 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_pipe(int fd[2])
{
	close(fd[1]);
	close(fd[0]);
}

static int	fork_safe(void)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	return (pid);
}

static void	write_pipe(char **first, int fd[2], int in, char **envp)
{
	dup2(in, STDIN_FILENO);
	close(in);
	dup2(fd[WRITE], STDOUT_FILENO);
	close_pipe(fd);
	execve(first[0], first, envp);
	exit(0);
}

static void	read_pipe(char **second, int fd[2], int out, char **envp)
{
	dup2(out, STDOUT_FILENO);
	close(out);
	dup2(fd[READ], STDIN_FILENO);
	close_pipe(fd);
	execve(second[0], second, envp);
	exit(0);
}

void	ft_pipex(char **argv, char **envp, char **first, char **snd)
{
	int	infile;
	int	outfile;
	int	fd[2];
	int	pid;

	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (infile < 0 || outfile < 0)
		exit(EXIT_FAILURE);
	pipe(fd);
	pid = fork_safe();
	if (pid == 0)
		write_pipe(first, fd, infile, envp);
	pid = fork_safe();
	if (pid == 0)
		read_pipe(snd, fd, outfile, envp);
	close_pipe(fd);
	close(infile);
	close(outfile);
	wait(NULL);
	wait(NULL);
}
