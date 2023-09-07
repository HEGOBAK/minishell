/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:20:27 by jchu              #+#    #+#             */
/*   Updated: 2023/01/12 16:25:32 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	src_idx;
	size_t	value;

	if (dstsize == 0)
		return (ft_strlen(src));
	else if (dstsize < ft_strlen(dst))
		value = ft_strlen(src) + dstsize;
	else
		value = ft_strlen(src) + ft_strlen(dst);
	src_idx = 0;
	idx = 0;
	while (dst[idx] != '\0')
		idx++;
	while (src[src_idx] && dstsize > idx + 1)
	{
		dst[idx] = src[src_idx];
		idx++;
		src_idx++;
	}
	dst[idx] = '\0';
	return (value);
}
