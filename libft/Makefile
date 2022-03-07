# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 15:56:08 by flim              #+#    #+#              #
#    Updated: 2022/03/07 15:14:20 by flim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar -rcs
RM = rm -rf

INCLUDE = includes
SOURCE = sources

SRCS = $(SOURCE)/ft_isalpha.c $(SOURCE)/ft_isdigit.c $(SOURCE)/ft_isalnum.c $(SOURCE)/ft_isascii.c $(SOURCE)/ft_isprint.c \
	$(SOURCE)/ft_strlen.c $(SOURCE)/ft_memset.c $(SOURCE)/ft_bzero.c $(SOURCE)/ft_memcpy.c $(SOURCE)/ft_memmove.c \
	$(SOURCE)/ft_strlcpy.c $(SOURCE)/ft_strlcat.c $(SOURCE)/ft_toupper.c $(SOURCE)/ft_tolower.c $(SOURCE)/ft_strchr.c \
	$(SOURCE)/ft_strrchr.c $(SOURCE)/ft_strncmp.c $(SOURCE)/ft_memchr.c $(SOURCE)/ft_memcmp.c $(SOURCE)/ft_strnstr.c \
	$(SOURCE)/ft_atoi.c $(SOURCE)/ft_calloc.c $(SOURCE)/ft_strdup.c \
	$(SOURCE)/ft_substr.c $(SOURCE)/ft_strjoin.c $(SOURCE)/ft_strtrim.c $(SOURCE)/ft_split.c $(SOURCE)/ft_itoa.c \
	$(SOURCE)/ft_strmapi.c $(SOURCE)/ft_striteri.c $(SOURCE)/ft_putchar_fd.c $(SOURCE)/ft_putstr_fd.c $(SOURCE)/ft_putendl_fd.c \
	$(SOURCE)/ft_putnbr_fd.c
OBJS = $(SRCS:.c=.o)

BONUS = $(SOURCE)/ft_lstnew.c $(SOURCE)/ft_lstadd_front.c $(SOURCE)/ft_lstsize.c $(SOURCE)/ft_lstlast.c $(SOURCE)/ft_lstadd_back.c \
		$(SOURCE)/ft_lstdelone.c $(SOURCE)/ft_lstclear.c $(SOURCE)/ft_lstiter.c $(SOURCE)/ft_lstmap.c
BONUS_OBJS = $(BONUS:.c=.o)

# Text Colors
RESET =  "\033[0m"
BRIGHT_RED = "\033[31;1m"
BRIGHT_CYAN = "\033[36;1m"
BRIGHT_GREEN = "\033[32;1m"
BRIGHT_MAGENTA = "\033[35;1m"

all: $(NAME)

$(NAME): $(OBJS)
	@$(LIB) $(NAME) $(OBJS)
	@echo $(BRIGHT_GREEN)"$(NAME) has been created!"$(RESET)
	@make -C $(FT_PRINTF_DIR)
	@cp $(FT_PRINTF_DIR)/$(FT_PRINTF) $(NAME)
	@if [ -f $(NAME) ]; \
	then \
		echo $(BRIGHT_GREEN)"$(FT_PRINTF) has been copied to $(NAME)!"$(RESET); \
	fi

.c.o:
	@printf $(BRIGHT_MAGENTA)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJS)
	@echo $(BRIGHT_RED)"DELETED FILE/S: $(OBJS)\n"$(RESET)
	@make clean -C $(FT_PRINTF_DIR)

clean_bonus: clean
	@$(RM) $(BONUS_OBJS)
	@echo $(BRIGHT_RED)"DELETED FILE: $(BONUS_OBJS)\n"$(RESET)

fclean: clean
	@$(RM) $(NAME)
	@echo $(BRIGHT_RED)"DELETED FILE: $(NAME)\n"$(RESET)
	@$(RM) $(FT_PRINTF_DIR)/$(FT_PRINTF)
	@echo $(BRIGHT_RED)"DELETED FILE: $(FT_PRINTF)\n"$(RESET)

fclean_bonus: clean_bonus
	$(RM) $(NAME)
	@echo $(BRIGHT_RED)"DELETED FILE: $(NAME)\n"$(RESET)

re: fclean $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	@$(LIB) $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo $(BRIGHT_GREEN)"$(NAME) has been created!"$(RESET)

rebonus: fclean_bonus bonus

norm:
	@make norm -C $(FT_PRINTF_DIR)
	@echo $(BRIGHT_MAGENTA)"LIBFT .c file/s"$(RESET)
	@norminette -R CheckForbiddenSourceHeader $(SOURCE)/*.c
	@echo $(BRIGHT_MAGENTA)"LIBFT .h file/s"$(RESET)
	@norminette -R CheckDefine $(INCLUDE)/*.h

.PHONY = all bonus clean clean_bonus fclean fclean_bonus re rebonus norm
