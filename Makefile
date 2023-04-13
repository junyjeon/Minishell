NAME		=	minishell

CC			=	cc -g3
# CFLAGS		=	-Wall -Wextra -Werror
#CFLAGS		+=	-fsanitize=address

CPPFLAGS	=	-I$(LIBFT_DIR) -I$(RDLINE_DIR)/include
LDFLAGS		=	-L$(RDLINE_DIR) -lreadline -L$(LIBFT_DIR) -lft

LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a

BUILD_DIR	=	bulid
RDLINE_DIR	=	$(shell brew --prefix readline)

SRC		=	$(addprefix ./, main.c)
OBJ		=	$(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))

all:	$(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)
	@echo "$(GREEN)SUCCESS!$(END)"

$(BUILD_DIR)/%.o: %.c | mkdir
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus

mkdir:
	@mkdir -p $(BUILD_DIR)

clean:
	@$(RM) -r $(BUILD_DIR)
	@echo "${YELLOW}> All objects files of the Minishell have been deleted.❌${END}"

fclean: clean
	@$(RM) -r $(NAME) $(LIBFT)
	@echo "${YELLOW}> Cleaning of the Minishell has been done.❌${END}"

re: fclean
	@$(MAKE)
	@echo "$(GREEN)Cleaned and rebuilt everything for Minishell!${END}"

GREEN	=	$'\x1b[32m
YELLOW	=	$'\x1b[33m

.PHONY: all clean fclean re mkdir
