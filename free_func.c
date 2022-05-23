/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:19:43 by urycherd          #+#    #+#             */
/*   Updated: 2022/03/15 20:58:31 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_after_split(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
}

void	parent_free(t_ppx *lol)
{
	int	i;

	i = 0;
	// close(lol->file1);
	// close(lol->file2);
	while (lol->cmd_paths[i])
	{
		free(lol->cmd_paths[i]);
		i++;
	}
	free(lol->cmd_paths);
}

void	child_free(t_ppx *lol)
{
	int	i;

	i = 0;
	while (lol->cmd_args[i])
	{
		free(lol->cmd_args[i]);
		i++;
	}
	free(lol->cmd_args);
	free(lol->cmd);
}
