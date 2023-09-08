/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:10:46 by thong-bi          #+#    #+#             */
/*   Updated: 2023/09/08 17:30:02 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <dirent.h>
# include <sys/stat.h>
# include <stdio.h>
# include "Libft/libft.h"

typedef struct s_env
{
	char	*name;
	char	*value;
}	t_env;

typedef struct s_built
{
	char	*cmd;
	void	(*f)();
}	t_built;

void	ft_free(char **tab);
void	init_ev(t_list **lst, char **ev);
void	ft_echo(char **args, t_list **ev);
char	*get_ev(char *name, t_list *lst);
void	store_ev(t_list **lst, char *name, char *value, int end);
void	ft_cd(char **args, t_list **ev);

