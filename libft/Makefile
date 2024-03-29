# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 17:29:46 by junyojeo          #+#    #+#              #
#    Updated: 2023/04/14 16:14:05 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g2

SRC			=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c \
				ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
				ft_calloc.c ft_strdup.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS_SRC	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BUILD_DIR	=	build

OBJ			=	$(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))
BONUS_OBJ	=	$(patsubst %.c, $(BUILD_DIR)/%.o, $(BONUS_SRC))

all :
	@$(MAKE) -j $(NAME)

$(NAME) : $(OBJ) ; @ar rc $(NAME) $(OBJ) ;
	@echo "$(GREEN)Libft has been compiled!$(END)"

$(BUILD_DIR)/%.o: %.c | mkdir ; @$(CC) $(CFLAGS) -c $< -o $@;

mkdir:
	@mkdir -p $(BUILD_DIR)

bonus : $(BONUS_OBJ) ; @ar rc $(NAME) $(BONUS_OBJ) ;
	@echo "$(GREEN)Libft Bonus has been compiled!$(END)"

clean : ; @rm -f $(OBJ) $(BONUS_OBJ)

fclean : clean ; @rm -f $(NAME)
	@echo "$(YELLOW)> Cleaning of the Libft has been done.❌$(END)"

re:	fclean all

END		=	$'\x1b[0m
GREEN	=	$'\x1b[32m
YELLOW	=	$'\x1b[33m

.PHONY : all clean fclean re bonus
