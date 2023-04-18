/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:24:08 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/18 23:04:57 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <libft.h>

/* 환경 변수 */
typedef struct s_env
{
	char			*key;//환경 변수 이름
	char			*value;//환경 변수 값
	struct s_env	*next;//다음 환경 변수
}		t_env;

/* 토큰 타입 */
typedef enum
{
	COMMAND,//명령어 echo, cd, pwd, export, unset, env, exit
	ARGUMENT,//인수 "" ''
	PIPE,//파이프 |
	REDIRECT_IN,//입력 리다이렉션 <
	REDIRECT_OUT,//출력 리다이렉션 >
	REDIRECT_APPEND,//입출력 리다이렉션 << >>
}		tokentype;

/* 명령, 인수, 연산자(파이프, 리다이렉션)를 개별 토큰으로, 연결리스트로 만든 것 */
typedef struct s_token
{
	tokentype		type;
	char			*data;
	struct s_token	*next;
}					t_token;

/* 추상 구문 트리(ATS)노드 (구문(void *data)이 추상적이어서 추상 구조 트리) */
typedef struct s_ast
{
	t_token			*contents;
	struct s_node	*left;
	struct s_node	*right;
	struct s_node	*parents;
}					t_ast;

//추상 구문 트리(AST)
/*
          [PIPE]
      left/    \right
   [COMMAND]  [COMMAND]
   /       \  /       \
 [ls]    [-l][grep] [.txt]
*/

// /* echo -n, cd, pwd, export, unset, env, exit 명령어 */
// typedef struct s_command
// {
// 	void	*command;//명령 이름
// 	char	*args;//명령과 관련된 인수(문자열)에 대한 목록
// 	char	*input;//입력 리다이렉션('<') 파일 이름
// 	char	*output;//출력 리다이렉션('>') 파일 이름
// 	int		append;//출력을 파일에 추가할지(true)/ 덮어쓸지(false)를 나타내는 부울
// 	int		background;//백그라운드(true) / 포그라운드(false) 어디서 실행될지
// }		t_command;

// typedef struct s_pipe
// {
// 	void	*commands;//명령어 목록
// 	int		*num_commands;//파이프 개수
// }		t_pipe;

void	init_signal_handling();
char	*read_input(void);
int		is_exit_command(char *input);

/* utils */
int		ft_strcmp(const char *s1, const char *s2);
char	**shell_split(char *input);


#endif
