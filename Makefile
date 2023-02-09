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


# COLORS

RED					=	\033[0;31m
RED_BOLD			=	\033[1;31m
GREEN				=	\033[0;32m
GREEN_BOLD			=	\033[1;32m
YELLOW				=	\033[0;33m
YELLOW_BOLD			=	\033[1;33m
CYAN				=	\033[0;36m
CYAN_BOLD			=	\033[1;36m
EOC					=	\033[0m
BOLD				=	\033[1m


# COMMANDS

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror
RM					=	rm -rf


# PROJECT

NAME				=	push_swap
BONUS				=	checker

SRCS_DIR			=	./src
OBJS_DIR			=	./obj

SRCS_COMMON_FILES	=	\
						int/ps_imin.c\
						\
						utils/ps_init.c\
						utils/ps_free.c\
						utils/ps_error_exit.c\
						\
						input/ps_check_duplicates.c\
						input/ps_set_keys.c\
						input/ps_get_inputs.c\
						\
						print/ps_print_ab.c\
						\
						cmd/ps_swap.c\
						cmd/ps_push.c\
						cmd/ps_rotate.c\
						cmd/ps_reverse_rotate.c\
						cmd/ps_cmd.c\
						cmd/ps_cmd_rots.c\
						\
						list/ps_key.c\
						list/ps_is_list_sorted.c\
						list/ps_is_list_sorted_with_offset.c\
						list/ps_find_index.c\
						list/ps_find_index_in_range.c\
						list/ps_min.c\
						list/ps_max.c\
						list/ps_closest_below.c\
						list/ps_closest_above.c\
						\
						sort/ps_rotate_to_top.c\
						sort/ps_sort_2.c\
						sort/ps_sort_3.c\
						sort/ps_sort_3_more.c\
						sort/ps_sort_radix.c\
						sort/ps_sort_by_chunk.c\
						sort/ps_sort_counting.c\
						sort/ps_sort.c\

SRCS_FILES			=	$(SRCS_COMMON_FILES) push_swap.c
SRCS				=	$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS_FILES			=	$(SRCS_FILES:.c=.o)
OBJS				=	$(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

SRCS_BONUS_FILES	=	$(SRCS_COMMON_FILES) checker_bonus.c
SRCS_BONUS			=	$(addprefix $(SRCS_DIR)/, $(SRCS_BONUS_FILES))
OBJS_BONUS_FILES	=	$(SRCS_BONUS_FILES:.c=.o)
OBJS_BONUS			=	$(addprefix $(OBJS_DIR)/, $(OBJS_BONUS_FILES))

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
					echo "$(GREEN_BOLD)create %.o ➞$(EOC) $@ $(RED)"
					$(CC) $(CFLAGS) $(HEADER_INC) $(FT_INC) -c $< -o $@
					echo -n "$(EOC)"

$(NAME):			$(OBJS) $(FT)
					echo "$(GREEN_BOLD)create exe ➞$(EOC) $@ $(RED)"
					$(CC) $(CFLAGS) $(OBJS) $(FT_FLAGS) -o $(NAME)
					echo -n "$(EOC)"

$(BONUS):			$(OBJS_BONUS) $(FT)
					echo "$(GREEN_BOLD)create exe ➞$(EOC) $@ $(RED)"
					$(CC) $(CFLAGS) $(OBJS_BONUS) $(FT_FLAGS) -o $(BONUS)
					echo -n "$(EOC)"

.PHONY: bonus		
bonus:				$(BONUS)

$(FT):
					echo "$(GREEN_BOLD)create lib ➞$(EOC) $@"
					$(MAKE) -C $(FT_DIR)
					echo -n "$(EOC)"

.PHONY: clean
clean:
					echo "$(RED_BOLD)delete %.o ➞$(EOC) $(OBJS_DIR) $(RED)"
					$(RM) $(OBJS_DIR)
					echo -n "$(EOC)"
					echo "$(RED_BOLD)delete %.o ➞$(EOC) $(FT_DIR) $(RED)"
					$(MAKE) -C $(FT_DIR) clean
					echo -n "$(EOC)"

.PHONY: fclean
fclean:				clean
					echo "$(RED_BOLD)delete lib ➞$(EOC) $(FT) $(RED)"
					$(MAKE) -C $(FT_DIR) fclean
					echo -n "$(EOC)"
					echo "$(RED_BOLD)delete exe ➞$(EOC) $(NAME) $(RED)"
					$(RM) $(NAME)
					echo -n "$(EOC)"
					echo "$(RED_BOLD)delete exe ➞$(EOC) $(BONUS) $(RED)"
					$(RM) $(BONUS)
					echo -n "$(EOC)"

.PHONY: re
re:					fclean
					$(MAKE) all

.SILENT:
