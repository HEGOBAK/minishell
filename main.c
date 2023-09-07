/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:20:40 by thong-bi          #+#    #+#             */
/*   Updated: 2023/09/07 16:11:41 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_list	*ev;
	t_list	*lst;

	(void)ac;
	(void)av;
	ev = NULL;
	lst = NULL;
	init_ev(&ev, ev);
}
