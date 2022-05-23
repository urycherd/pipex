/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:14:58 by urycherd          #+#    #+#             */
/*   Updated: 2022/03/15 21:33:14 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

static void	child1(t_ppx *lol)
{
	dup2(lol->fd[1], 1);
	close(lol->fd[0]);
	dup2(lol->file1, 0);
	lol->cmd_args = ft_split(lol->argv[2], ' ');
	lol->cmd = make_cmd(lol->cmd_paths, lol->cmd_args[0]);
	if (!lol->cmd)
	{
		child_free(lol);
		ft_error("Error: cmd mistake");
	}
	execve(lol->cmd, lol->cmd_args, lol->envp);
	ft_error("Error: execve mistake");
	exit(1);
}

static void	child2(t_ppx *lol)
{
	dup2(lol->fd[0], 0);
	close(lol->fd[1]);
	dup2(lol->file2, 1);
	lol->cmd_args = ft_split(lol->argv[3], ' ');
	lol->cmd = make_cmd(lol->cmd_paths, lol->cmd_args[0]);
	if (!lol->cmd)
	{
		child_free(lol);
		ft_error("Error: cmd mistake");
		exit(1);
	}
	execve(lol->cmd, lol->cmd_args, lol->envp);
	ft_error("Error: execve mistake");
	exit(1);
}

static void	make_your_way(t_ppx *lol)
{
	if (pipe(lol->fd) == -1)
		ft_error("Error: pipe problems");
	lol->pid1 = fork();
	if (lol->pid1 == -1)
		ft_error("Error: fork mistake");
	if (lol->pid1 == 0)
		child1(lol);
	lol->pid2 = fork();
	if (lol->pid2 == -1)
		ft_error("Error: fork mistake");
	if (lol->pid2 == 0)
		child2(lol);
	close (lol->fd[0]);
	close (lol->fd[1]);
	// close (lol->file1);
	// close (lol->file2);
	waitpid(lol->pid1, NULL, 0);
	waitpid(lol->pid2, NULL, 0);
	// parent_free(lol);
}

int	main(int argc, char	**argv, char *envp[])
{	
	t_ppx	*lol;

	lol = (t_ppx *)malloc(sizeof(t_ppx));
	if (!lol)
		return (0);
	if (argc != 5)
		ft_error("Error: wrong number of input parameters");
	if (!lol)
		ft_error("Error: malloc error create struct");
	lol->argv = argv;
	pipex_parsing(lol, envp);
	make_your_way(lol);
	return (0);
}
