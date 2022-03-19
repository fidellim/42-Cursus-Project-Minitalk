# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 12:01:57 by flim              #+#    #+#              #
#    Updated: 2022/03/19 13:17:51 by flim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_DIR = libft
LIBFT = libft.a
FT_PRINTF_DIR = libft/ft_printf
FT_PRINTF = ft_printf.a

SOURCE = sources
INCLUDE = includes
CLIENT = client
SERVER = server

SRC_CLIENT	=	$(SOURCE)/client.c
OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)
SRC_CLIENT_BONUS	=	$(SOURCE)/client_bonus.c
OBJ_CLIENT_BONUS	=	$(SRC_CLIENT_BONUS:.c=.o)
SRC_SERVER	=	$(SOURCE)/server.c
OBJ_SERVER	=	$(SRC_SERVER:.c=.o)
SRC_SERVER_BONUS	=	$(SOURCE)/server_bonus.c
OBJ_SERVER_BONUS	=	$(SRC_SERVER_BONUS:.c=.o)

TEST_DIR = tests
DEFAULT_EXE = ./a.out

MAIN_LIBFT = main_libft.c
MAIN_FT_PRINTF = main_ft_printf.c

# Text Colors
RESET =  "\033[0m"
BRIGHT_RED = "\033[31;1m"
BRIGHT_CYAN = "\033[36;1m"
BRIGHT_GREEN = "\033[32;1m"
BRIGHT_MAGENTA = "\033[35;1m"

all: $(LIBFT) $(SERVER) $(CLIENT)

bonus: $(LIBFT) server_bonus client_bonus

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(SERVER): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(SRC_SERVER) -L$(LIBFT_DIR) -lft -o $(SERVER)
	@echo $(BRIGHT_GREEN)"$(SERVER) has been created!"$(RESET)

$(CLIENT): $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(SRC_CLIENT) -L$(LIBFT_DIR) -lft -o $(CLIENT)
	@echo $(BRIGHT_GREEN)"$(CLIENT) has been created!"$(RESET)

server_bonus: $(OBJ_SERVER_BONUS)
	@$(CC) $(CFLAGS) $(SRC_SERVER_BONUS) -L$(LIBFT_DIR) -lft -o $(SERVER)
	@echo $(BRIGHT_GREEN)"$(SERVER) has been created!"$(RESET)

client_bonus: $(OBJ_CLIENT_BONUS)
	@$(CC) $(CFLAGS) $(SRC_CLIENT_BONUS) -L$(LIBFT_DIR) -lft -o $(CLIENT)
	@echo $(BRIGHT_GREEN)"$(CLIENT) has been created!"$(RESET)

.c.o:
	@printf $(BRIGHT_MAGENTA)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
	@echo $(BRIGHT_RED)"DELETED FILEs:$(OBJ_CLIENT) $(OBJ_SERVER)\n"$(RESET)

clean_bonus:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)
	@echo $(BRIGHT_RED)"DELETED FILEs:$(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)\n"$(RESET)

fclean:
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
	@echo $(BRIGHT_RED)"DELETED FILES:$(OBJ_CLIENT) $(OBJ_SERVER)\n"$(RESET)
	@$(RM) $(SERVER) $(CLIENT)
	@echo $(BRIGHT_RED)"DELETED FILES: $(SERVER) $(CLIENT)\n"$(RESET)

fclean_bonus:
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)
	@echo $(BRIGHT_RED)"DELETED FILES:$(OBJ_CLIENT_BONUS) $(OBJ_SERVER_BONUS)\n"$(RESET)
	@$(RM) $(SERVER) $(CLIENT)
	@echo $(BRIGHT_RED)"DELETED FILES: $(SERVER) $(CLIENT)\n"$(RESET)

re: fclean all

re_bonus: fclean_bonus bonus

norm:
	@echo $(BRIGHT_MAGENTA)"MINITALK .c file/s"$(RESET)
	@norminette -R CheckForbiddenSourceHeader $(SOURCE)/*.c
	@echo $(BRIGHT_MAGENTA)"MINITALK .h file/s"$(RESET)
	@norminette -R CheckDefine $(INCLUDE)/*.h
	@make norm -C $(LIBFT_DIR)

test_libft:
	$(CC) $(CFLAGS) $(TEST_DIR)/$(MAIN_LIBFT) -L$(LIBFT_DIR) -lft && $(DEFAULT_EXE)

test_ft_printf:
	$(CC) $(CFLAGS) $(TEST_DIR)/$(MAIN_FT_PRINTF) -L$(FT_PRINTF_DIR) -lftprintf && $(DEFAULT_EXE)

.PHONY = all clean clean_bonus fclean fclean_bonus re re_bonus norm test_libft test_ft_printf
