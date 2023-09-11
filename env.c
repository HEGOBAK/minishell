/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:04:16 by thong-bi          #+#    #+#             */
/*   Updated: 2023/09/11 14:44:05 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **args, t_list **lst)
{
	t_list	*cpy;
	t_env	*env;

	(void)args;
	cpy = *lst;
	while (cpy)
	{
		env = (t_env *)cpy->content;
		printf("%s=%s\n", env->name, env->value);
		cpy = cpy->next;
	}
}

static int	check_args(char **args, t_list **lst)
{
	if (ft_strtablen(args) > 2)
	{
		printf("setenv: Too many arguments.\n");
		return (-1);
	}
	if (*args == NULL)
	{
		ft_env(args, lst);
		return (-1);
	}
	if (ft_isalpha(**args) == 0)
	{
		printf("setenv: Variable name must begin with a letter.\n");
		return (-1);
	}
	else if (ft_isalnum(*args) == 0)
	{
		printf("setenv: Variable name must contain alphanumeric characters.\n");
		return (-1);
	}
	return (1);
}

void	ft_setenv(char **args, t_list **lst)
{
	t_list	*cpy;
	t_env	*env;

	if (check_args(args, lst) == -1)
		return ;
	cpy = *lst;
	while (cpy)
	{
		env = (t_env *)cpy->content;
		if (ft_strcmp(env->name, *args) == 0)
		{
			free(env->value);
			env->value = ft_strdup(args[1]);
			return ;
		}
		cpy = cpy->next;
	}
	store_ev(lst, args[0], args[1], 1);
}

void	ft_unsetenv(char **args, t_list **lst)
{
	t_list	*cpy;
	t_list	*old;
	int		i;

	i = -1;
	while (args[++i] != NULL)
	{
		cpy = *lst;
		old = NULL;
		while (cpy != NULL)
		{
			if (ft_strcmp(((t_env *)cpy->content)->name, args[i]) == 0)
			{
				if (old == NULL)
					*lst = cpy->next;
				else
					old->next = cpy->next;
				free_elem(cpy);
				break ;
			}
			old = cpy;
			old = old->next;
		}
	}
}
