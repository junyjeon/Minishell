NAME		=	minishell

CC			=	cc -g3
# CFLAGS	=	-Wall -Wextra -Werror
#CFLAGS		+=	-fsanitize=address

CPPFLAGS	=	-I$(LIBFT_DIR) -I$(RDLINE_DIR)/include
LDFLAGS		=	-L$(RDLINE_DIR) -lreadline -L$(LIBFT_DIR) -lft

LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a

BUILD_DIR	=	bulid
RDLINE_DIR	=	$(shell brew --prefix readline)

SRC		=	$(addprefix ./, main.c utils.c)
SRC		+=	$(addprefix is_worked/, is_worked.c)
OBJ		=	$(patsubst ./%.c, $(BUILD_DIR)/%.o, $(SRC))

all:	
	@$(MAKE) -j $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o $@
	@echo "${GREEN}Minishell has been compiled!${END}"

$(BUILD_DIR)/%.o: %.c | mkdir
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo "${YELLOW}Compiling $<${END}"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

mkdir:
	@mkdir -p $(BUILD_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(RM) -r $(BUILD_DIR)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@echo "${YELLOW}> Cleaning of the Minishell has been done.❌${END}"

re: fclean all

END		=	$'\x1b[0m
GREEN	=	$'\x1b[32m
YELLOW	=	$'\x1b[33m

.PHONY: all clean fclean re
