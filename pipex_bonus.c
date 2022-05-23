/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:10:31 by urycherd          #+#    #+#             */
/*   Updated: 2022/03/16 13:59:22 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*define_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	if (*envp == 0)
		return (NULL);
	return (*envp + 5);
}

void	ft_parsing(t_ppx *lol, int argc, char *argv[], char **envp)
{
	char	*path;

	lol->argc = argc;
	lol->argv = argv;
	lol->envp = envp;
	lol->file1 = open(argv[1], O_RDONLY);
	if (lol->file1 < 0)
		ft_error("Error: can't open file1");
	lol->file2 = open(lol->argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0755);
	if (lol->file2 < 0)
		ft_error("Error: some problems with file 2");
	path = define_path(envp);
	lol->cmd_paths = ft_split(path, ':');
}

int	main(int argc, char *argv[], char **envp)
{
	t_ppx	lol;

	ft_parsing(&lol, argc, argv, envp);
	
	return (0);
}
