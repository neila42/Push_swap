NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

OBJ			= $(SRC:.c=.o)

SRC =	algo_utils2.c \
		algo_utils3.c \
		algo_utils.c \
		algo_utils4.c \
		algo_sort.c \
		list_utils.c \
		list.c \
		main.c \
		parsing2.c \
		parsing.c \
		instructions3.c \
		instructions2.c \
		instructions.c \

all:	$(NAME)

%.o : %.c
	${CC} -c -o $@ $^ -I./libft ${CFLAGS}
	
$(NAME):	$(OBJ) 
			${MAKE} -C libft	
			gcc -o ${NAME} ${OBJ} -L./libft -lft

libft:
			${MAKE} -C libft

clean:
			$(RM) $(OBJ)
			$(MAKE) -C libft clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C libft fclean

re:			fclean all

.PHONY:		all libft clean fclean re

