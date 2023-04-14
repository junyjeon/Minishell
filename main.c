/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:07:15 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/14 19:49:06 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//터미널 세팅
void init_env(t_env *env)
{
	env->key = NULL;
	env->value = NULL;
	env->next = NULL;
}

int	token_type(char *input)
{
	if (ft_strcmp(input, "echo") == 0 || ft_strcmp(input, "cd") == 0 || \
	ft_strcmp(input, "pwd") == 0 || ft_strcmp(input, "export") == 0 || \
	ft_strcmp(input, "unset") == 0 || ft_strcmp(input, "env") == 0 || \
	ft_strcmp(input, "exit") == 0)
		return (COMMAND);
	//else if ()//인수는 나중에 판단한다는데?
	//	return (ARGUMENT);
	else if (ft_strcmp(input, "|") == 0)//파이프
		return (PIPE);
	else if (ft_strcmp(input, "<") == 0)//입력 리다이렉션
		return (REDIRECT_IN);
	else if (ft_strcmp(input, ">") == 0)//출력 리다이렉션
		return (REDIRECT_OUT);
	else if (ft_strcmp(input, "<<") == 0 || ft_strcmp(input, ">>") == 0)//입출력 리다이렉션 추가
		return (REDIRECT_APPEND);
	return (0);
}

t_token	*tokenize(char *input)
{
	t_token *token;
	
	token = (t_token *)malloc(sizeof(t_token));
	token->type = token_type(input);
	return (token);
}


t_token	*tokenize_input(char *input)
{
	t_token	*tokens;
	char	**word;
	int		i;

	// Tokenize input
	word = shell_split(input);
	i = -1;
	while (word[++i])
		tokens = tokenize(word[i]);
	return (tokens);
}

void	main_loop(t_env *env)
{
	t_token	*tokens;
	t_node	ast;
	char	*input;

	while (1)
	{
		input = read_input();//입력받은 명령어
		
		//if (is_exit_command(input))//exit 명령어 입력시
		//	break;
		
		//tokens = tokenize_input(input);//입력받은 명령어를 토큰화
		//free(input);
		
		//ast = parse_tokens(&tokens);//토큰화된 명령어를 추상 구문 트리로 변환

		//exsecute_ast(&ast);//명령어 실행

		//free_tokens(&tokens);
		//free_ast(&ast);
	}
}

int main(void)
{
	t_env	env;

	//init_env(&env);//환경 변수 초기화
	init_signal_handling();//시그널 핸들러 초기화
	
	main_loop(&env);//메인 루프 시작(쉘 실행

	//cleanup_env();//환경 변수 초기화
	return (0);
}
