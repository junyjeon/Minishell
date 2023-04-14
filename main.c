/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:07:15 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/14 16:08:19 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//exit 명령어 입력시
int is_exit_command(char *input)
{
	// Check if the input is an exit command
	if (ft_strncmp(input, "exit", 4) == 0)
		return (1);
	return (0);
}
//입력받은 명령어
char	*read_input(void)
{
	char	*str;
	str = readline("minishell$ ");
	if (!str)
		return (NULL);
	rl_on_new_line();//readline 함수를 사용할 때마다 새로운 줄을 만들어주는 함수
	rl_replace_line("", 0);
	rl_redisplay();
	add_history(str);
	return (str);
}
//시그널 핸들러
void	init_signal_handling()
{
	// Initialize signal handling
	signal(SIGINT, SIG_IGN);//ctrl + c
	signal(SIGTERM, SIG_IGN);//ctrl + d
	signal(SIGQUIT, SIG_IGN);//ctrl + '\'
}
//환경 변수 초기화
void init_env(t_env *env)
{
	// Initialize environment variables
	env->key = NULL;
	env->value = NULL;
	env->next = NULL;
}

int main(void)
{
	// t_token	tokens;
	// t_node	ast;
	t_env	env;
	char	*input;
	init_env(&env);//환경 변수 초기화
	init_signal_handling();//시그널 핸들러 초기화

	while (1)
	{
		// Read input
		input = read_input();//입력받은 명령어
		free(input);
		// Exit condition
		if (is_exit_command(input))//exit 명령어 입력시
			break;

		// // Tokenize input
		// tokens = tokenize_input(input);

		// // Parse input
		// ast = parse_tokens(&tokens);

		// // Execute commands
		// execute_ast(&ast);

		// // Clean up
		// free_tokens(&tokens);
		// free_ast(&ast);
	}

	// Cleanup
	// cleanup_environment();
	return (0);
}
