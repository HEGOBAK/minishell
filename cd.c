/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:22:03 by thong-bi          #+#    #+#             */
/*   Updated: 2023/09/08 17:31:53 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*home_dir(t_list *lst)
{
	t_env	*ev;

	while (lst)
	{
		ev = (t_env *)lst->content;
		if (ft_strcmp(ev->name, "HOME") == 0)
			return (ev->value);
		lst = lst->next;
	}
	return (NULL);
}

static void	chg_pwd(char *pwd, t_list **lst)
{
	t_list	*cpy;
	t_env	*ev;
	char	*new;

	cpy = *lst;
	while (cpy)
	{
		ev = (t_env *)cpy->content;
		if (ft_strcmp(ev->name, pwd) == 0)
		{
			free(ev->value);
			ev->value = NULL;
			ev->value = getcwd(ev->value, 0);
			return ;
		}
		cpy = cpy->next;
	}
	new = NULL;
	store_ev(lst, pwd, getcwd(new, 0), 1);
	free(new);
}

static int	check_dir(char *home)
{
	struct stat	info;
	int			ret;

	ret = -1;
	if (home == NULL)
		ret = printf("$HOME variable not found (check env).\n");
	else if (stat(home, &info) != 0)
		ret = printf("%s: No such file or directory.\n", home);
	else if (home != NULL && access(home, F_OK) != 0)
		ret = printf("%s: No such file or directory.\n", home);
	else if (home != NULL && (info.st_mode & S_IFMT) != S_IFDIR)
		ret = printf("%s: Not a directory.\n", home);
	else if (home != NULL && access(home, X_OK) != 0)
		ret = printf("%s: Permission denied.\n", home);
	if (ret != -1)
		return (-1);
	else
		return (1);
}

void	ft_cd(char **args, t_list **ev)
{
	char	*home;
	char	*new;

	new = NULL;
	if (*args == NULL)
		home = home_dir(*ev);
	else
		home = *args;
	if (home != NULL && ft_strcmp(home, "~") == 0)
		home = get_ev("HOME", *ev);
	else if (home != NULL && home[0] == '~' && home[1] == '/')
		new = ft_strjoin(get_ev("HOME", *ev), home + 1);
	else if (home != NULL && ft_strcmp(home, "-") == 0)
		new = ft_strdup(get_ev("OLDPWD", *ev));
	if (new != NULL)
		home = new;
	if (check_dir(home) == 1)
	{
		chg_pwd("OLDPWD", ev);
		chdir(home);
		chg_pwd("PWD", ev);
	}
	if (new != NULL)
		free(new);
}
