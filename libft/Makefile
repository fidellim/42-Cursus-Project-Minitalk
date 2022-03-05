# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flim <flim@student.42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 15:56:08 by flim              #+#    #+#              #
#    Updated: 2022/03/05 17:55:23 by flim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar -rcs
RM = rm -rf

INCLUDE = includes
SOURCE = sources

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c
OBJS = $(SRCS:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
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

.c.o:
	@printf $(BRIGHT_MAGENTA)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
	@$(RM) $(OBJS)
	@echo $(BRIGHT_RED)"DELETED FILE/S: $(OBJS)\n"$(RESET)

clean_bonus: clean
	@$(RM) $(BONUS_OBJS)
	@echo $(BRIGHT_RED)"DELETED FILE: $(BONUS_OBJS)\n"$(RESET)

fclean: clean
	@$(RM) $(NAME)
	@echo $(BRIGHT_RED)"DELETED FILE: $(NAME)\n"$(RESET)

fclean_bonus: clean_bonus
	$(RM) $(NAME)
	@echo $(BRIGHT_RED)"DELETED FILE: $(NAME)\n"$(RESET)

re: fclean $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	@$(LIB) $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo $(BRIGHT_GREEN)"$(NAME) has been created!"$(RESET)

rebonus: fclean_bonus bonus

norm:
	@echo $(BRIGHT_MAGENTA)"LIBFT .c file/s"$(RESET)
	@norminette -R CheckForbiddenSourceHeader $(SOURCE)/*.c
	@echo $(BRIGHT_MAGENTA)"LIBFT .h file/s"$(RESET)
	@norminette -R CheckDefine $(INCLUDE)/*.h

.PHONY = all bonus clean clean_bonus fclean fclean_bonus re rebonus norm
