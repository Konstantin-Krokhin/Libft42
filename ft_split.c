/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Konstantin Krokhin <kokrokhi@students.42wo +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:31:22 by Konstantin Krokh  #+#    #+#             */
/*   Updated: 2021/12/14 00:14:54 by Konstantin Krokh ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countReturnArraySize(char const *s, char c,
									int i, int delimiterCount)
{
	int	enterFlag;

	enterFlag = 0;
	while (s[i])
	{
		if (s[i] != c && enterFlag == 0)
		{
			enterFlag = 1;
			delimiterCount++;
		}
		else if (s[i] == c)
			enterFlag = 0;
		i++;
	}
	return (delimiterCount);
}

static char	*extractWord(char *word, char *wordStart, int *wordSize)
{
	int	count;
	int	wordStartCnt;

	count = 0;
	wordStartCnt = 0;
	word = malloc(sizeof(char) * (*wordSize + 1));
	if (!word)
		return (0);
	while (count != *wordSize)
		word[count++] = wordStart[wordStartCnt++];
	word[count] = '\0';
	*wordSize = 0;
	return (word);
}

static char	**fillReturnArray(char **rtn, char const *s, char c, int i)
{
	char	*wordStart;
	char	*word;
	int		wordSize;
	int		cnt;
	int		enterFlag;

	enterFlag = 0;
	wordStart = 0;
	wordSize = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c && enterFlag == 0)
		{
			enterFlag = 1;
			wordStart = (char *)&s[i];
			wordSize++;
		}
		else if (s[i] == c)
			enterFlag = 0;
		else
			wordSize++;
		if (enterFlag == 0 && wordSize > 0)
		{
			word = extractWord(word, wordStart, &wordSize);
			rtn[cnt++] = word;
		}
		i++;
	}
	if (enterFlag == 1 && wordSize > 0)
	{
		word = extractWord(word, wordStart, &wordSize);
		rtn[cnt++] = word;
	}
	rtn[cnt] = 0;
	return (rtn);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn;
	int		delimiterCount;
	int		i;

	i = 0;
	delimiterCount = 0;
	delimiterCount = countReturnArraySize(s, c, i, delimiterCount);
	rtn = malloc(sizeof(char *) * (delimiterCount + 1));
	if (!rtn)
		return (0);
	i = 0;
	rtn = fillReturnArray(rtn, s, c, i);
	return (rtn);
}
