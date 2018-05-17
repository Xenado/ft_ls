# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaille <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 14:22:43 by jcaille           #+#    #+#              #
#    Updated: 2018/03/12 15:00:20 by jcaille          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_ls

SRC_NAME	=	ft_ls.c				\
				ft_check_opts.c		\
				ft_list.c			\
				ft_rd_dir.c			\
				ft_sort_files.c		\
				ft_display.c		\
				ft_rev_files.c		\
				ft_size_nbr.c		\
				ft_opt_l.c			\
				get_size.c			\
				ft_display_ls.c
OBJ_NAME	=	$(SRC:.c=.o)
SRC_PATH	=	.
OBJ_PATH	=	objs
SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra
CPPFLAGS	=	-I.

LDLIBS		=	-lft
LDFLAGS		=	-Llibft

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) -o $@ -c $<

clean:
	@$(MAKE) clean -C libft
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) fclean -C libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean, fclean, re, all
