# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 15:56:08 by flim              #+#    #+#              #
#    Updated: 2022/02/27 11:10:21 by flim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar -rcs
RM = rm -rf

INCLUDE = includes
SOURCE = sources

SRCS = $(SOURCE)/ft_printf.c $(SOURCE)/decimal_funcs.c \
	$(SOURCE)/hex_funcs.c $(SOURCE)/char_string_funcs.c
OBJS = $(SRCS:.c=.o)

TEST = tests/main.c

# Text Colors
RESET =  "\033[0m"
BRIGHT_RED = "\033[31;1m"
BRIGHT_CYAN = "\033[36;1m"
BRIGHT_GREEN = "\033[32;1m"
BRIGHT_MAGENTA = "\033[35;1m"

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(LIB) $(NAME) $(OBJS)
	@echo $(BRIGHT_GREEN)"$(NAME) has been created!"$(RESET)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) $(NAME)

.c.o:
	@printf $(BRIGHT_MAGENTA)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS)
	@echo $(BRIGHT_RED)"DELETED FILE/S: $(OBJS)\n"$(RESET)

fclean: clean
	@$(RM) $(LIBFT_DIR)/$(LIBFT)
	@echo $(BRIGHT_RED)"DELETED FILE: $(LIBFT)\n"$(RESET)
	@$(RM) $(NAME)
	@echo $(BRIGHT_RED)"DELETED FILE: $(NAME)\n"$(RESET)

re: fclean $(NAME)

norm:
	@make norm -C $(LIBFT_DIR)
	@echo $(BRIGHT_MAGENTA)"FT_PRINTF .c file/s"$(RESET)
	@norminette -R CheckForbiddenSourceHeader $(SOURCE)/*.c
	@echo $(BRIGHT_MAGENTA)"FT_PRINTF .h file/s"$(RESET)
	@norminette -R CheckDefine $(INCLUDE)/*.h

test:
	@echo $(BRIGHT_CYAN)
	@$(CC) $(CFLAGS) $(TEST) -L. -lftprintf && ./a.out
	@$(RM) a.out
	@printf $(RESET)

.PHONY = all clean fclean re test
