NAME		=	push_swap
NAME2		=	checker
CC			=	clang
FLAGS		=	-Wall -Werror -Wextra -I $(HEADER) -I $(LIBFT) -fsanitize=address

HEADER		=	./includes/
LIBFT		=	./libft/

SRCS		=	srcs/main.c								\
				srcs/utils.c							\
				srcs/list.c								\
				srcs/less_than_five.c					\
				srcs/median.c							\
				srcs/operations/swap.c					\
				srcs/operations/reverse_rotate.c		\
				srcs/operations/reverse.c				\
				srcs/operations/push.c					\

#SRCS2		=	srcs/checker/main.c						\
				srcs/utils.c							\
				srcs/list.c								\
				srcs/less_than_five.c					\
				srcs/median.c							\
				srcs/operations/swap.c					\
				srcs/operations/reverse_rotate.c		\
				srcs/operations/reverse.c				\
				srcs/operations/push.c					\

.c.o		:
				$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

OBJS		=	$(SRCS:.c=.o)

#OBJS2		=	$(SRCS2:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(OBJS2) $(HEADER)
			make -C $(LIBFT)
			$(CC) -o $(NAME) $(FLAGS) $(OBJS) ./libft/libft.a
			#$(CC) -o $(NAME2) $(FLAGS) $(OBJS2) ./libft/libft.a

clean		:
			rm -rf $(OBJS)
			make clean -C $(LIBFT)

fclean		:	clean
			rm -f $(NAME)
			make fclean -C $(LIBFT)

re			:	fclean all