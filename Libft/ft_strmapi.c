/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:20:33 by jchu              #+#    #+#             */
/*   Updated: 2023/01/12 16:22:21 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	idx;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (!s || !f || !temp)
		return (NULL);
	idx = 0;
	while (idx < ft_strlen((char *)s))
	{
		temp[idx] = f(idx, s[idx]);
		idx++;
	}
	temp[idx] = '\0';
	return (temp);
}
