# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 13:30:28 by dapereir          #+#    #+#              #
#    Updated: 2023/01/30 13:42:31 by dapereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	push_swap

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror
RM					=	rm -rf

SRCS_FILES			=	\
						utils/ps_init.c\
						utils/ps_free.c\
						utils/ps_error_exit.c\
						\
						input/ps_check_duplicates.c\
						input/ps_set_indexes.c\
						input/ps_get_inputs.c\
						\
						cmd/ps_swap.c\
						cmd/ps_push.c\
						cmd/ps_rotate.c\
						cmd/ps_reverse_rotate.c\
						\
						push_swap.c\

SRCS_DIR			=	./src
SRCS				=	$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS_FILES			=	$(SRCS_FILES:.c=.o)
OBJS_DIR			=	./obj
OBJS				=	$(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

HEADER_DIR			=	./include
HEADER				=	$(HEADER_DIR)/push_swap.h
HEADER_INC			=	-I $(HEADER_DIR)

FT_DIR				=	./libft
FT					=	$(FT_DIR)/libft.a
FT_INC				=	-I $(FT_DIR)/include
FT_FLAGS			=	-L $(FT_DIR) -l ft

.PHONY: all
all:				$(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c Makefile $(FT) $(HEADER)
					mkdir -p $(@D)
					$(CC) $(CFLAGS) $(HEADER_INC) $(FT_INC) -c $< -o $@

$(NAME):			$(OBJS) $(FT)
					$(CC) $(CFLAGS) $(OBJS) $(FT_FLAGS) -o $(NAME)

$(FT):
					$(MAKE) -C $(FT_DIR)

.PHONY: clean
clean:
					$(RM) $(OBJS_DIR)
					$(MAKE) -C $(FT_DIR) clean

.PHONY: fclean
fclean:				clean
					$(RM) $(NAME)
					$(MAKE) -C $(FT_DIR) fclean

.PHONY: re
re:					fclean
					$(MAKE) all
