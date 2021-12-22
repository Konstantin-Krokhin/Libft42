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

static void	substractions(char **ndl, char **hay, size_t *flag, size_t *len)
{
	*ndl -= *flag;
	*hay = *hay - *flag + 1;
	*len -= *flag;
	*flag = 0;
}

static char	*ft_loop(char *ndl, char *hay, size_t ndl_size, size_t len)
{
	size_t	flag;

	flag = 0;
	while (len > 0)
	{
		if (*hay == '\0' || *ndl == '\0')
			break ;
		if (*ndl == *hay)
		{
			flag++;
			if (flag == ndl_size)
				break ;
			ndl++;
		}
		else if (ft_strlen(ndl) != ndl_size && flag > 0)
		{
			substractions(&ndl, &hay, &flag, &len);
			continue ;
		}
		len--;
		hay++;
	}
	if (flag == ndl_size && flag != 0)
		return (hay - flag + 1);
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*hay;
	char		*ndl;
	size_t		ndl_size;
	size_t		hay_size;

	hay = (char *)haystack;
	ndl = (char *)needle;
	ndl_size = ft_strlen(ndl);
	hay_size = ft_strlen(hay);
	if (ndl_size == 0 || haystack == needle)
		return ((char *)hay);
	if (hay_size < ndl_size || ndl_size > len)
		return (NULL);
	return (ft_loop(ndl, hay, ndl_size, len));
}
