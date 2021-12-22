/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:30:40 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/09 12:17:47 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*rtn;
	unsigned char	*r;
	size_t			i;

	rtn = malloc(size * count);
	if (!rtn)
		return (NULL);
	r = rtn;
	i = 0;
	while (r && i < count)
	{
		r[i] = '\0';
		i++;
	}
	return (rtn);
}
