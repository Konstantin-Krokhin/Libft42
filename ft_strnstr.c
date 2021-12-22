/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:32:02 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/09 19:26:27 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_loop(char *ndl, char *hay, size_t ndl_size, size_t len)
{
	size_t	flag;

	flag = 0;
	while (*ndl != '\0' && *hay != '\0' && len > 0)
	{
		if (*ndl == *hay)
		{
			flag++;
			if (flag == ndl_size)
				break ;
			ndl++;
		}
		else
			flag = 0;
		len--;
		hay++;
	}
	if (flag == ndl_size)
		return (hay - flag + 1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*hay;
	char		*ndl;
	size_t		ndl_size;

	hay = (char *)haystack;
	ndl = (char *)needle;
	ndl_size = ft_strlen(ndl);
	if (ndl_size == 0)
		return ((char *)hay);
	if (ft_strlen(hay) < ndl_size)
		return (0);
	return (ft_loop(ndl, hay, ndl_size, len));
}
