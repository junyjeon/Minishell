/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:21:32 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/14 19:46:52 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	word_len(char *input, char c, int i)
{
	int	cnt;

	cnt = 0;
	while (input[i] != c)
	{
		if (!input[i])
			break ;
		cnt++;
		i++;
	}
	return (cnt);
}

int	word_cnt(char *input)
{
	int	i;
	int	cnt;

	i = -1;
	while (input[++i])
	{
		if (input[i] == ' ' || i != 0 && \
		(input[i] == '\0' && input[i - 1] != ' '))
			cnt++;
		else if (input[i] == '\'')
		{
			while (input[++i] != '\'')
				;
		}
		else if (input[i] == '\"')
		{
			while (input[++i] != '\"')
				;
		}
	}
	return (cnt);
}

char	**shell_split(char *input)
{
	char	**word;
	int		i;

	word = (char **)malloc(sizeof(char *) * (word_cnt(input) + 1));
	i = -1;
	while (i < word_cnt)
	{
		word[i] = (char *)malloc(sizeof(char) * (word_len(input, ' ', i) + 1));
		if (!word[i])
			return (NULL);
		i++;
	}
	return (word);	
}
