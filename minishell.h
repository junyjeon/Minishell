/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:24:08 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/13 19:02:47 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>

/* 토큰 타입 */
typedef enum
{
	COMMAND,
	ARGUMENT,
	PIPE,
	REDIRECT_IN,
	REDIRECT_OUT,
	REDIRECT_APPEND,
	BACKGROUND
}	tokentype;

/* 명령, 인수, 연산자(파이프, 리다이렉션)를 개별 토큰으로, 연결리스트로 만든 것 */
typedef struct s_token
{
	tokentype		type;//명령, 인수, 파이프, 리다이렉션 타입
	void			*data;
	struct s_token	*next;//다음 토큰
}		t_token;

/* 추상 구문 트리(ATS)노드 (구문(void *data)이 추상적이어서 추상 구조 트리) */
typedef struct s_node //추상 구문 트리구조 (구문(void *data)이 추상적이어서 추상 구조 트리)
{
	tokentype		type;//명령, 인수, 파이프, 리다이렉션 타입
	char			*data;
	struct s_node	*left;//왼쪽 자식 노드
	struct s_node	*right;//오른쪽 자식 노드
}		t_node;

//추상 구문 트리(AST)
/*
          [PIPE]
      left/    \right
   [COMMAND]  [COMMAND]
   /       \  /       \
 [ls]    [-l][grep] [.txt]
*/asd

/* 환경 변수 */
typedef struct s_env
{
	char			*key;//환경 변수 이름
	char			*value;//환경 변수 값
	struct s_env	*next;//다음 환경 변수
}		t_env;

/* echo -n, cd, pwd, export, unset, env, exit 명령어 */
typedef struct s_command
{
	void	*command;//명령 이름
	char	*args;//명령과 관련된 인수(문자열)에 대한 목록
	char	*input;//입력 리다이렉션('<') 파일 이름
	char	*output;//출력 리다이렉션('>') 파일 이름
	int		append;//출력을 파일에 추가할지(true)/ 덮어쓸지(false)를 나타내는 부울
	int		background;//백그라운드(true) / 포그라운드(false) 어디서 실행될지
}		t_command;

typedef struct s_pipe
{
	void	*commands;//파이프라인의 명령(문자열)에 대한 목록
	int		*num_commands;//파이프라인의 명령 개수
}		t_pipe;

typedef struct s_shell//환경 변수
{
		*variables;//환경 변수
		*history;//명령어 히스토리
		*aliases;//명령어의 별칭
	char	*current_directory;//현재 디렉토리
	int		exit_status;//종료 상태
}		t_shell;
}

#endif
