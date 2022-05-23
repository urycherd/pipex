/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:33:54 by urycherd          #+#    #+#             */
/*   Updated: 2022/03/15 12:10:54 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_ppx
{
	char	**argv;
	char	**envp;
	int		fd[2];
	int		file1;
	int		file2;
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd;
	char	**cmd_paths;
	char	**cmd_args;
}				t_ppx;

void	pipex_parsing(t_ppx *lol, char **env);
void	ft_error(char *str);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_after_split(char **argv);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*make_cmd(char **paths, char *cmd);
void	child_free(t_ppx *pipex);
void	parent_free(t_ppx *lol);

#endif