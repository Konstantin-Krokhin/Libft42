/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:31:39 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/11 18:13:41 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char	*loop(char *str, size_t i, char *ss1, char *ss2)
// {
// 	size_t	s1_len;
// 	size_t	s2_len;

// 	s1_len = ft_strlen(ss1);
// 	s2_len = ft_strlen(ss2);
// 	while (i < s1_len)
// 	{
// 		*str++ = *ss1++;
// 		i++;
// 	}
// 	i = 0;
// 	while (i < s2_len)
// 	{
// 		*str++ = *ss2++;
// 		i++;
// 	}
// 	return (str);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;

	i = 0;
	if ((!s1 && !s2) || (ft_strncmp(s1, s2, ft_strlen(s1)) == 0 && s2 == ""))
		return (ft_strdup(""));
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memmove(str, s1, ft_strlen(s1));
	ft_memmove(str + ft_strlen(s1), s2, ft_strlen(s2));
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (str);
}
// str = loop(str, i, ss1, ss2);
// if (*s1 == '\0' && *s2 == '\0')
// 		return (ft_strdup(""));
// 	if (*s2 == '\0')
// 		return (str - ft_strlen(s1));
// 	if (*s1 == '\0')
// 		return (str - ft_strlen(s2));
// if (s1 && !s2)
// 	return (ft_strdup(s1));
// if (!s1 && s2)
// 	return (ft_strdup(s2));