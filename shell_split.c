/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 02:35:14 by junyojeo          #+#    #+#             */
/*   Updated: 2023/05/03 16:09:40 by junyojeo         ###   ########.fr       */
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

int	word_cnt(char *input, int double_quote, int single_quote)
{
	int i;
	int cnt;

	cnt = 0;
	i = -1;
	while (input[++i])
	{
		if (input[i] == '\"')//더블따옴표 열기 -> double_quote = 1;
			double_quote = !double_quote;
		else if (input[i] == '\'')//작은 따옴표 열기
			single_quote = !single_quote;
		if ((input[i] == ' ' || input[i + 1] == '\0') && !double_quote && !single_quote)//공백이거나 문자열의 끝이고 따옴표가 닫혀있다면 단어개수 세기
			cnt++;
	}
	// if (single_quote || double_quote)//따옴표가 안닫힌 경우
	// 	print_error("Error: The quotation marks are not closed.\n");
	return (cnt);
}

// char	*env_search(char *input, char *word, int j, int *k)
// {
// 	char	*value;
	
// 	while (input[*k] != '\0' || input[*k] != ' ' || input[*k] != '\"' || input[*k] != '\'')//괄호는 아직 안함
// 		word[j] = input[*k + j];		
// 	value = find_value_by_key(key);
// 	word[j]의 word_len의 값을 value의 ft_strlen(value);
// 	return (value);
// }

char	**shell_split(char *input)
{
	char **word;
	int i;//단어 인덱스
	int j;//단어의 문자 인덱스
	int k;//input(전체 문자열)의 인덱스
	int double_quote;//큰 따옴표 플래그
	int single_quote;//작은 따옴표 플래그
	
	double_quote = 0;
	single_quote = 0;
	word = (char **)malloc(sizeof(char *) * (word_cnt(input, double_quote, single_quote) + 1));
	i = -1; 
	k = 0;
	while (++i < word_cnt(input, double_quote, single_quote))
	{
		word[i] = (char *)malloc(sizeof(char) * (word_len(input, k) + 1));
		if (!word[i])
			return (NULL);
		j = -1;
		while (input[k] != '\0' && (input[k] != ' ' || double_quote || single_quote))//따옴표 안에서
		{
			if (input[k] == '\"')//큰 따옴표 닫기
				double_quote = !double_quote;
			else if (input[k] == '\'')//작은 따옴표 닫기
				single_quote = !single_quote;
			if (input[k] == '$' && !single_quote)//환경변수라면( ' 빼고)
				env_search(input, word[i], j, &k);
			else
			{
				word[i][++j] = input[k];
				k++;
			}
		}
		word[i][j + 1] = '\0';
		while (input[k] == ' ')//단어 뒤 공백이 있을 때(단어의 끝) 
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

	input = "echo -n \"123 456 $env 789\" > test.c | echo < test.c | ls >> test_ls.c | echo << test.c test_ls | cd | pwd | export | unset | env | exit";
	word = shell_split(input);
	for (i = 0; word[i] != NULL; i++)
		printf("%s\n", word[i]);
	return (0);
}
