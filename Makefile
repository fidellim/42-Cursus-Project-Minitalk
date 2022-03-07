# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 12:01:57 by flim              #+#    #+#              #
#    Updated: 2022/03/07 15:56:32 by flim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = libft.a
FT_PRINTF_DIR = libft/ft_printf
FT_PRINTF = ft_printf.a

TEST_DIR = tests
DEFAULT_EXE = ./a.out

MAIN_LIBFT = main_libft.c
MAIN_FT_PRINTF = main_ft_printf.c

all: 
	@make -C $(LIBFT_DIR)

.c.o:
	@printf $(BRIGHT_MAGENTA)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
	@make clean -C $(LIBFT_DIR)

fclean:
	@make fclean -C $(LIBFT_DIR)

re:
	@make re -C $(LIBFT_DIR)

norm:
	@make norm -C $(LIBFT_DIR)

test_libft:
	$(CC) $(CFLAGS) $(TEST_DIR)/$(MAIN_LIBFT) -L$(LIBFT_DIR) -lft && $(DEFAULT_EXE)

test_ft_printf:
	$(CC) $(CFLAGS) $(TEST_DIR)/$(MAIN_FT_PRINTF) -L$(FT_PRINTF_DIR) -lftprintf && $(DEFAULT_EXE)

.PHONY = all clean fclean re norm test_libft test_ft_printf
