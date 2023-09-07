/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:26:32 by thong-bi          #+#    #+#             */
/*   Updated: 2023/09/07 15:45:54 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	store_ev(t_list **lst, char *name, char *value, int end)
{
	t_env	*elem;

	elem = (t_env *)malloc(sizeof(t_env));
	elem->name = ft_strdup(name);
	elem->value = ft_strdup(value);
	if (end == 0)
		ft_lstadd_front(lst, ft_lstnew(elem));
	else
		ft_lstadd_back(lst, ft_lstnew(elem));
}

void	init_ev(t_list **lst, char **ev)
{
	char	**cpy;
	char	**tmp;

	cpy = ev;
	while (*cpy)
	{
		tmp = ft_split(*cpy, '=');
		store_ev(lst, tmp[0], tmp[1], 0);
		ft_free(tmp);
		cpy++;
	}
}
