/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_worked.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:18:24 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/20 05:13:38 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//exit 명령어 입력시
int	is_exit_command(char *input)
{
	// Check if the input is an exit command
	if (ft_strncmp(input, "exit", 4) == 0)
		return (1);
	return (0);
}
//입력받은 명령어
char	*read_input(void)//아직 안되는 함수
{
	char	*str;
	str = readline("minishell$ ");
	if (!str)
		return (NULL);
	// rl_on_new_line();//readline 함수를 사용할 때마다 새로운 줄을 만들어주는 함수
	// rl_replace_line(str, 0);//입력한 명령어를 readline에 출력
	// rl_redisplay();//
	add_history(str);//입력한 명령어를 history에 저장
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
