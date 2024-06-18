CC = cc -g
NAME = push_swap
FT_PRINTF = ft_printf/libftprintf.a
FLAGS = -Wall -Werror -Wextra
SRCS = srcs/push_swap.c srcs/parse_input.c srcs/moves_swap.c srcs/move_helpers.c \
	srcs/moves_push.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${FT_PRINTF}:
	@make --silent -C ft_printf

${NAME}: ${OBJS} ${FT_PRINTF}
	@echo "\033[0;32mCompiling program...\033[0m"
	@${CC} ${OBJS} ${MLX} ${FT_PRINTF} ${FLAGS} -o ${NAME}
	@echo "\033[0;32mFDF successfully compiled.\033[0m"

%.o: %.c
	@${CC} -c $< -o $@ -Wall -Werror -Wextra

clean:
	@rm -f ${OBJS}
	@make --no-print-directory -C ft_printf/ fclean

fclean:	clean
	@rm ${NAME}

re: fclean all


.PHONY : all clean fclean re
