/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 02:35:14 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/19 02:50:59 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int word_len(char *input, int i)
{
	int cnt;
	int double_quote = 0;
	int single_quote = 0;

	cnt = 0;
	while (input[i] && (double_quote || single_quote || input[i] != ' '))
	{
		if (input[i] == '\"')
			double_quote = !double_quote;
		else if (input[i] == '\'')
			single_quote = !single_quote;
		cnt++;
		i++;
	}
	return (cnt);
}

int word_cnt(char *input)
{
	int i;
	int cnt;
	int double_quote = 0;
	int single_quote = 0;

	cnt = 0;
	i = -1;
	while (input[++i])
	{
		if (input[i] == '\"')
			double_quote = !double_quote;
		else if (input[i] == '\'')
			single_quote = !single_quote;
		if ((input[i] == ' ' || input[i + 1] == '\0') && !double_quote && !single_quote)
			cnt++;
	}
	return (cnt);
}

char **shell_split(char *input)
{
	char **word;
	int i;
	int j;
	int k;
	int double_quote = 0;
	int single_quote = 0;

	word = (char **)malloc(sizeof(char *) * (word_cnt(input) + 1));
	i = -1;
	k = 0;
	while (++i < word_cnt(input))
	{
		word[i] = (char *)malloc(sizeof(char) * (word_len(input, k) + 1));
		if (!word[i])
			return (NULL);
		j = -1;
		while (input[k] != '\0' && (double_quote || single_quote || input[k] != ' '))
		{
			if (input[k] == '\"')
				double_quote = !double_quote;
			else if (input[k] == '\'')
				single_quote = !single_quote;
			word[i][++j] = input[k];
			k++;
		}
		word[i][j + 1] = '\0';
		while (input[k] == ' ')
			k++;
	}
	word[i] = NULL;
	return (word);
}

int main(void)
{
	char *input;
	char **word;
	int i;

	input = "ls -a -l >> a < b > c | grep \"\" | cat << x > y | cat 'a' 'b' \"abc\" | export HELLLO=\"beautiful world\"";
	word = shell_split(input);
	for (i = 0; word[i] != NULL; i++)
		printf("%s\n", word[i]);
	return (0);
}
