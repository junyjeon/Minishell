/*
    main함수에 main_loop()함수를 만들어서 그 안에 read_line() 를 쓰면 어떨까  . . .
*/
#include <readline/readline.h>
#include <readline/history.h>
# define PROMPT "\033[0;31mminishell>\033[0m "

static void main_loop(void)
{
    char *input;

    while (1)
    {
        input = readline(PROMPT);
        if (input == NULL)
        {
            ft_putendl_fd("\x1b[1A\033[12Cexit", STDOUT_FILENO);
            break;
        }
        if (ft_strcmp(input, "") == 0)
        {
            free(input);
            continue;
        }
        add_history(input);
        /*
            t_node ast = 파싱
            execute(ast)    // 실행
            clear_node() & free(input) 등등
        */
    }
}

int main()
{
    /*
    init_env(&env);//환경 변수 초기화
	init_signal_handling();//시그널 핸들러 초기화
    */
    main_loop();    // 

}


