/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:33:54 by urycherd          #+#    #+#             */
/*   Updated: 2022/03/15 16:59:26 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_ppx
{
	int		argc;
	char	**argv;
	char	**envp;
	int		file1;
	int		file2;
	char	*cmd;
	char	**cmd_paths;
}				t_ppx;

char	**ft_split(char const *s, char c);

#endif