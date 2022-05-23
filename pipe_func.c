/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:17:21 by urycherd          #+#    #+#             */
/*   Updated: 2022/03/16 13:59:04 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*define_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	if (*envp == 0)
		return (NULL);
	return (*envp + 5);
}

void	pipex_parsing(t_ppx *lol, char **envp)
{
	char	*path;

	lol->file1 = open(lol->argv[1], O_RDONLY);
	if (lol->file1 < 0)
		ft_error("Error: can't open file1");
	lol->file2 = open(lol->argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (lol->file2 < 0)
		ft_error("Error: some problems with file 2");
	path = define_path(envp);
	lol->cmd_paths = ft_split(path, ':');
	lol->envp = envp;
}

char	*make_cmd(char **paths, char *incmd)
{
	char	*tmp;
	char	*cmd;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		cmd = ft_strjoin(tmp, incmd);
		free(tmp);
		if (access(cmd, 0) == 0)
			return (cmd);
		free(cmd);
		paths++;
	}
	return (NULL);
}
