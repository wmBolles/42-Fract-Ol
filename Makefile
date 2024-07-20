# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wabolles <wabolles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 08:59:54 by wabolles          #+#    #+#              #
#    Updated: 2024/07/18 19:54:04 by wabolles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Assets
CC 		=	cc
CFLAGS	=	-Wall -Wextra -Werror -c -I./inc
OPENGL	=	-framework OpenGL
APPKIT	=	-framework AppKit
FAST	=	-O3
LINK	=	-lmlx
HEADER	=	./inc/headers.h
NAME	=	fractol

# PRINTF FILES
PRINTF_FILES = ft_printf/fmt/print_addr.c 	\
		       ft_printf/fmt/print_base.c 	\
			   ft_printf/fmt/print_cs.c   	\
			   ft_printf/fmt/print_nbrs.c 	\
		       ft_printf/fmt/which_format.c \
		       ft_printf/ft_printf.c

# FRACTOL_FILES
TOOLS = tools/tools.c tools/usage_display.c tools/tools2.c \
		tools/events.c
FRACTALS = fractals/mandelbrot.c fractals/julia.c
FILES = fract-ol.c $(PRINTF_FILES) $(TOOLS) $(FRACTALS)
OBJ = $(FILES:.c=.o)

#Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LINK) $(OBJ) $(APPKIT) $(OPENGL) -o $(NAME)

./%.o: ./%.c $(HEADER)
	$(CC) $(FAST) $(CFLAGS) $< -o $@
	
clean:
	rm -rf $(OBJ)

fclean: clean
	rm $(NAME)
	
re:	fclean all

.PHONY: clean