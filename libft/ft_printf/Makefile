# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 15:56:08 by flim              #+#    #+#              #
#    Updated: 2022/03/07 15:09:57 by flim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = ..
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
	@if [ -f $(NAME) ]; \
	then \
		echo $(BRIGHT_GREEN)"$(NAME) has been created!"$(RESET); \
	fi

$(LIBFT):
	@if [ -f $(LIBFT_DIR)/$(LIBFT) ]; \
	then \
		cp $(LIBFT_DIR)/$(LIBFT) $(NAME); \
		echo $(BRIGHT_GREEN)"$(LIBFT) has been copied to $(NAME)!"$(RESET); \
	fi

.c.o:
	@printf $(BRIGHT_MAGENTA)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJS)
	@echo $(BRIGHT_RED)"DELETED FILE/S: $(OBJS)\n"$(RESET)

fclean: clean
	@$(RM) $(NAME)
	@echo $(BRIGHT_RED)"DELETED FILE: $(NAME)\n"$(RESET)

re: fclean $(NAME)

norm:
	@echo $(BRIGHT_MAGENTA)"FT_PRINTF .c file/s"$(RESET)
	@norminette -R CheckForbiddenSourceHeader $(SOURCE)/*.c
	@echo $(BRIGHT_MAGENTA)"FT_PRINTF .h file/s"$(RESET)
	@norminette -R CheckDefine $(INCLUDE)/*.h

.PHONY = all clean fclean re norm
