# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 09:33:14 by toroman           #+#    #+#              #
#    Updated: 2025/04/03 11:41:37 by toroman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH = ./Libft

LIBFT_SRC = ${addprefix ${LIBFT_PATH}/, ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c \
			ft_memset.c ft_strlen.c ft_strlcpy.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
			ft_strlcat.c ft_strnstr.c ft_strdup.c ft_calloc.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strjoin.c ft_substr.c \
			ft_strtrim.c ft_itoa.c ft_striteri.c ft_strmapi.c ft_split.c}
PRINTF_PATH = ./Printf

PRINTF_SRC = ${addprefix ${PRINTF_PATH}/, ft_printf.c ft_putchar.c ft_putstr.c ft_putptr.c ft_putnbr.c ft_uputnbr.c ft_base16_lowercase.c ft_base16_ptr.c ft_base16_uppercase.c}

GNL_PATH = ./Gnl

GNL_SRC = ${addprefix ${GNL_PATH}/, get_next_line.c get_next_line_utils.c}

SRCS = ${LIBFT_SRC} ${PRINTF_SRC}

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

INCLUDE = ./inc

%.o:%.c ${INCLUDE}
	@${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o ${<:.c=.o}

NAME = utils.a

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}
	@echo "COMPILED ${NAME}"

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
