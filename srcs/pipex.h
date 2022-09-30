/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduraku <dduraku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:21:19 by dduraku           #+#    #+#             */
/*   Updated: 2022/07/29 17:00:12 by dduraku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define WRITE 1
# define READ 0
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_truct
{
	int		i;
	char	**full_cmd;
	char	**path_before_cmd;
	char	*cmdjoin;
	char	*cmddup;
}				t_struct;

//====================PIPEX=======================
void	ft_arguments_protection(char **argv, char *first, char *snd);
int		ft_command_exists(const char *command);
int		ft_infile_exists(const char *filename);
char	*ft_path_to_command(char *path_before_cmd, char *command);
void	ft_pipex(char **argv, char **envp, char **s, char **c);
void	free_tab(char **tab);
char	**get_command(char *command, char *path_before_command);

//====================LIBFT=======================
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s1);

#endif