/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:07:15 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/12 19:12:26 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	readinput()
{
	
}

int	tokenize(char **input)
{
	int	i;

	i = 0;
	while (*input[++i])
	{
		input =
	}
	if (input)
	return (1);
}

int parsecommand(input_string)
{
	t_token	tokens;
	t_token	processed_tokens;

	tokens = tokenize(input_string);
	if (!syntaxvalidation(tokens))
		ft_error("Syntax error\n"); return ;
	processed_tokens = QuoteHandling(&tokens);
	processed_tokens = VariableExpansion(processed_tokens);
	processed_tokens = CommandSubstitution(processed_tokens);
	processed_tokens = WhitespaceHandling(processed_tokens);
	processed_tokens = OperatorHandling(processed_tokens);
	command_groups = CommandGrouping(processed_tokens);

	return (command_groups);
}

int main(int ac, char **ar)
{
	int	input;
	initshell();

	while (1)
	{
		promptuser();// 사용자의 명령을 반복적으로 읽고 실행
		input = ReadInput(); // readline
		if (!input)
			continue ;
		if (ft_strncmp(input,"exit", 4) != 0)
			break ;
		command_groups = parsecommand(input)
		executecommands(command_groups) // 커맨드 그룹
	}
	cleanupshell();
}
