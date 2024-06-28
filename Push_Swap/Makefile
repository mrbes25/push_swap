# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bschmid <bschmid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 08:47:11 by bschmid           #+#    #+#              #
#    Updated: 2024/06/26 19:13:46 by bschmid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME				= push_swap

# Directories
LIBFT				= my_lib/my_lib.a
SRC_DIR				= srcs/
OBJ_DIR				= obj/
INC                 = -I $(SRC_DIR)

# Compiler and CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra
RM					= rm -f

# Source Files
SRCS				=	main.c \
					push.c \
					reverse_rotate.c \
					rotate.c \
					swaps.c \
					algo_atob.c \
					algo_btoa.c \
					check_utils.c \
					dll_functions.c \
					error_handling.c \
					find_utils.c \
					general_utils.c \
					tiny_algo.c \
					turk_algo.c \

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
$(LIBFT):
	@make -C my_lib/

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
			@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
			@$(RM) -rf $(OBJ_DIR)
			@make clean -C ./my_lib

fclean: 			clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re
