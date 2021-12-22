/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:32:15 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/11 17:03:46 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;
	int		i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (start + len + 1 > s_len)
		return (0);
	rtn = malloc((len + 1) * sizeof(char));
	if (!rtn)
		return (0);
	len += start;
	while (start < len)
	{
		rtn[i] = s[start];
		i++;
		start++;
	}
	rtn[i] = '\0';
	return (rtn);
}