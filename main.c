/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:07:15 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/13 19:55:32 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Include necessary headers and define data structures

int	is_exit_command(char *input)
{
	// Check if the input is an exit command
	if (ft_strcmp(input, "exit") == 0)
		return (1);
	return (0);
}

char	*read_input(void)
{
	// Read input from stdin
	char	*str;
	str = readline(str);
	addhistory(str);
	free(str);
	return (str);
}

void	init_signal_handling()//시그널 핸들러->ctrl + c, ctrl + d, ctrl + \(SIG_IGN)
{
	// Initialize signal handling

}

void init_env(t_env *env)
{
	// Initialize environment variables
	env->key = NULL;
	env->value = NULL;
}

int main(void)
{
	t_token	tokens;
	t_node	ast;
	t_env	env;
	char	*input;
	// Initialization
	init_env(&env);
	init_signal_handling();//시그널 핸들러 초기화

	// Main loop
	while (1)
	{
		// Read input
		input = read_input();//입력받은 명령어

		// Exit condition
		if (is_exit_command(input))//exit 명령어 입력시
		{
			break;
		}

		// Tokenize input
		tokens = tokenize_input(input);

		// Parse input
		ast = parse_tokens(&tokens);

		// Execute commands
		execute_ast(&ast);

		// Clean up
		free_tokens(&tokens);
		free_ast(&ast);
	}

	// Cleanup
	cleanup_environment();
	return (0);
}
