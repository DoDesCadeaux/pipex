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

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

//====================PIPEX=======================
void	ft_arguments_protection(int argc, char **argv, char *first_cmd_path, char *snd_cmd_path);
int		ft_command_exists(const char *command);
int		ft_infile_exists(const char *filename);
char    *ft_path_to_command(char *path_before_cmd, char *command);

//====================LIBFT=======================
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
