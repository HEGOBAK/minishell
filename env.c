/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:04:16 by thong-bi          #+#    #+#             */
/*   Updated: 2023/09/11 14:09:08 by thong-bi         ###   ########.fr       */
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
