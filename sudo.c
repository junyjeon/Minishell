/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:21:21 by junyojeo          #+#    #+#             */
/*   Updated: 2023/04/14 16:05:09 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minishell"

function ParseCommand(input_string) {
    tokens = Tokenization(input_string)
    
    if !SyntaxValidation(tokens) {
        Print("Syntax error")
        return
    }
    
    processed_tokens = QuoteHandling(tokens)
    processed_tokens = VariableExpansion(processed_tokens)
    processed_tokens = CommandSubstitution(processed_tokens)
    processed_tokens = WhitespaceHandling(processed_tokens)
    processed_tokens = OperatorHandling(processed_tokens)
    command_groups = CommandGrouping(processed_tokens)
    
    return command_groups
}

function Tokenization(input_string) {
    // ... implementation to tokenize the input string ...
}

function SyntaxValidation(tokens) {
    // ... implementation to validate the syntax of tokens ...
}

function QuoteHandling(tokens) {
    // ... implementation to handle quotes within tokens ...
}

function VariableExpansion(tokens) {
    // ... implementation to expand environment variables in tokens ...
}

function CommandSubstitution(tokens) {
    // ... implementation to handle command substitution in tokens ...
}

function WhitespaceHandling(tokens) {
    // ... implementation to remove unnecessary whitespace in tokens ...
}

function OperatorHandling(tokens) {
    // ... implementation to handle operators in tokens ...
}

function CommandGrouping(tokens) {
    // ... implementation to group commands enclosed in braces or parentheses ...
}

//int main()
//{
//	InitializeShell() // init_minishell
	
//		while (true)
//	{
//		PromptUser()			// prompt생성
//			input = ReadInput() // readline

//			if (input is empty)
//		{ // 예외
//			continue
//		}

//		if (input is "exit")
//		{ // 나가기
//			break
//		}

//		command_groups = ParseCommand(input)
//			ExecuteCommands(command_groups) // 커맨드 그룹
//	}

//	CleanupShell() // free
//}
//사용자 입력 읽기 및 구문 분석
//command()명령어 실행
//내장 명령 처리
//I/O 리디렉션 및 파이프 관리
//프로세스 제어 관리(예: 백그라운드 프로세스, 작업 제어)
