/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:05:21 by thong-bi          #+#    #+#             */
/*   Updated: 2023/09/07 16:08:15 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(char **tab)
{
	char	**tmp;

	if (tab == NULL)
		return ;
	tmp = tab;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(tmp);
}

void	free_elem(t_list *elem)
{
	t_env	*env;

	env = (t_env *)elem->content;
	free(env->name);
	free(env->value);
	free(env);
	free(elem);
}
