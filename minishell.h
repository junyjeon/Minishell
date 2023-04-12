/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:24:08 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/12 17:03:52 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>

typedef enum
{
	COMMAND,
	ARGUMENT,
	PIPE,
	REDIRECT_IN,
	REDIRECT_OUT,
	REDIRECT_APPEND,
	BACKGROUND
}	TokenType;

typedef struct s_token//명령, 인수, 파이프, 리다이렉션 타입과 문자열 나누고 연결리스트로 만든 것
{
	TokenType		type;
	char			*content;
	struct s_token	*next;
}		t_token;

typedef struct s_command//pwd, export, unset, env, exit 명령어
{
	void	*command;//명령 이름
	char	*args;//명령과 관련된 인수(문자열)에 대한 목록
	char	*input;//입력 리다이렉션('<') 파일 이름
	char	*output;//출력 리다이렉션('>') 파일 이름
	int		append;//출력을 파일에 추가할지(true)/ 덮어쓸지(false)를 나타내는 부울
	int		background;//백그라운드(true) / 포그라운드(false) 어디서 실행될지
}		t_command;




#endif
