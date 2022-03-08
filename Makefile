# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 12:01:57 by flim              #+#    #+#              #
#    Updated: 2022/03/08 22:36:22 by flim             ###   ########.fr        #
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
SRC_SERVER	=	$(SOURCE)/server.c
OBJ_SERVER	=	$(SRC_SERVER:.c=.o)

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

$(LIBFT):
	@make -C $(LIBFT_DIR) 

$(SERVER): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(SOURCE)/server.c -L$(LIBFT_DIR) -lft -o $(SERVER)
	@echo $(BRIGHT_GREEN)"$(SERVER) has been created!"$(RESET)
	
$(CLIENT): $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(SOURCE)/client.c -L$(LIBFT_DIR) -lft -o $(CLIENT)
	@echo $(BRIGHT_GREEN)"$(CLIENT) has been created!"$(RESET)
	
.c.o:
	@printf $(BRIGHT_MAGENTA)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
	@echo $(BRIGHT_RED)"DELETED FILEs:$(OBJ_CLIENT) $(OBJ_SERVER)\n"$(RESET)

fclean: 
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
	@echo $(BRIGHT_RED)"DELETED FILES:$(OBJ_CLIENT) $(OBJ_SERVER)\n"$(RESET)
	@$(RM) $(SERVER) $(CLIENT)
	@echo $(BRIGHT_RED)"DELETED FILES: $(SERVER) $(CLIENT)\n"$(RESET)

re: fclean all

norm:
	@make norm -C $(LIBFT_DIR)
	@echo $(BRIGHT_MAGENTA)"MINITALK .c file/s"$(RESET)
	@norminette -R CheckForbiddenSourceHeader $(SOURCE)/*.c
	@echo $(BRIGHT_MAGENTA)"MINITALK .h file/s"$(RESET)
	@norminette -R CheckDefine $(INCLUDE)/*.h

test_libft:
	$(CC) $(CFLAGS) $(TEST_DIR)/$(MAIN_LIBFT) -L$(LIBFT_DIR) -lft && $(DEFAULT_EXE)

test_ft_printf:
	$(CC) $(CFLAGS) $(TEST_DIR)/$(MAIN_FT_PRINTF) -L$(FT_PRINTF_DIR) -lftprintf && $(DEFAULT_EXE)

.PHONY = all clean fclean re norm test_libft test_ft_printf
