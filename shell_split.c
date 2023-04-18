/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:21:32 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/18 21:48:51 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	word_len(char *input, int i)
{
	int	cnt;

	cnt = 0;
	while (input[i] != ' ')
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

	cnt = 0;
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
	int		j;
	int		k;

	word = (char **)malloc(sizeof(char *) * (word_cnt(input) + 1));
	i = -1;
	k = 0;
	while (++i < word_cnt(input))
	{
		word[i] = (char *)malloc(sizeof(char) * (word_len(input, k) + 1));
		if (!word[i])
			return (NULL);
		j = -1;
		while (++j < word_len(input, k))
			word[i][j] = input[k + j];
		word[i][j] = '\0';
		k += j + 1;
	}
	word[i] = NULL;
	return (word);	
}

int	main(void)
{
	char	*input;
	char	**word;
	int		i;

	input = "ls -a -l >> a < b > c | grep "" | cat << x > y";
	word = shell_split(input);
	for (i = 0; word[i] != NULL; i++)
		printf("%s\n", word[i]);
	return (0);
}