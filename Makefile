NAME = push_swap
NAME_BONUS = checker
OBJS = $(patsubst srcs/%.c,objs/%.o,$(SRCS))
B_OBJS = $(patsubst srcs/%.c,objs/%.o,$(BONUS))
CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror
RM = rm -vf
LINKERFLAGS = -Llibft -Lft_printf -lft -lftprintf

DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
BLUE = \033[0;94m

SRCS =  srcs/check_arg.c \
		srcs/push_swap.c \
		srcs/parsing.c \
		srcs/char_to_int.c \
		srcs/free_all.c \
		srcs/fill_stack.c \
		srcs/utils_math.c \
		srcs/utils_math_2.c \
		srcs/swap.c \
		srcs/push.c \
		srcs/rotate.c \
		srcs/reverse_rotate.c \
		srcs/which_sort.c \
		srcs/big_sort.c \
		srcs/get_cost.c \

BONUS = srcs/checker.c \
		srcs/check_if_sorted.c \
		srcs/check_arg.c \
		srcs/parsing.c \
		srcs/char_to_int.c \
		srcs/free_all.c \
		srcs/fill_stack.c \
		srcs/utils_math.c \
		srcs/utils_math_2.c \
		srcs/swap.c \
		srcs/push.c \
		srcs/rotate.c \
		srcs/reverse_rotate.c \
		srcs/get_next_line.c \
		srcs/get_next_line_utils.c \
		srcs/do_mvt.c \

INCLUDES = ft_printf/libftprintf.a \
			libft/libft.a \

# ============================================================================ #
#                                   Functions                                  #
# ============================================================================ #

all: $(NAME) 

clean:
	@$(RM) $(OBJS) $(B_OBJS)
	@make -C ft_printf clean
	@make -C libft clean
	@echo "$(BLUE)push_swap object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@make -C ft_printf fclean
	@make -C libft fclean
	@echo "$(BLUE)push_swap executable files cleaned!$(DEF_COLOR)"

re: fclean all

.PHONY:	all clean fclean re bonus

# ============================================================================ #
#                                    Recipes                                   #
# ============================================================================ #

# Link object files together
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LINKERFLAGS) -o $(NAME)

# Compile source code into object files
objs/%.o: srcs/%.c $(INCLUDES)
	@mkdir -p objs
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS) : $(B_OBJS)
	$(CC) $(B_OBJS) $(LINKERFLAGS) -o $(NAME_BONUS)

bonus : $(NAME_BONUS)

ft_printf/libftprintf.a:
	make -C ft_printf

libft/libft.a:
	make -C libft
