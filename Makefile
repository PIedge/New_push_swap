.DEFAULT_GOAL := help

D_PUSH		=	./src

D_CHCK		=	./srcs_checker

D_MV		=	./moves

D_UTL		=	./utils

SRCS_MOVES	=	$(D_MV)/push.c					\
				$(D_MV)/reverse_rotate.c		\
				$(D_MV)/rotate.c				\
				$(D_MV)/swap.c					\

SRCS_CHECK	= 	$(D_CHCK)/checker.c				\
				$(D_CHCK)/checker_utils.c		\
				$(D_CHCK)/main.c				\
				$(D_CHCK)/get_next_line.c		\
				$(D_CHCK)/get_next_line_utils.c	\
				$(D_CHCK)/utils.c				\

SRCS_UTL	=	$(D_UTL)/ft_itoa.c				\
				$(D_UTL)/ft_strncmp.c			\
				$(D_UTL)/ft_strlen.c			\
				$(D_UTL)/ft_atoi.c				\
				$(D_UTL)/ft_ceil.c				\
				$(D_UTL)/ft_free_dtab.c			\
				$(D_UTL)/ft_split.c				\
				$(D_UTL)/ft_substr.c			\
				$(D_UTL)/visual.c				\
				$(D_UTL)/ft_atol.c				\
				
SRCS_PUSH	=	$(D_PUSH)/main.c				\
				$(D_PUSH)/algos/apply_mv.c		\
				$(D_PUSH)/algos/calc_mv.c		\
				$(D_PUSH)/algos/range_next.c	\
				$(D_PUSH)/algos/rot_utils.c		\
				$(D_PUSH)/algos/where_put.c		\
				$(D_PUSH)/algos/five.c			\
				$(D_PUSH)/algos/three.c			\
				$(D_PUSH)/algos/hundreds.c		\
				$(D_PUSH)/algos/utils.c			\
				$(D_PUSH)/fill_c.c				\
				$(D_PUSH)/parser.c				\

OBJS_PUSH	=	$(SRCS_PUSH:.c=.o)

OBJS_CHCK	=	$(SRCS_CHECK:.c=.o)

OBJS_UTL	=	$(SRCS_UTL:.c=.o)

OBJS_MV		=	$(SRCS_MOVES:.c=.o)

CC			=	clang

FLAG		=	-Wall -Wextra -Werror -fsanitize=address

PUSH		=	push_swap

CHECK		=	checker

.c.o:
		$(CC) $(FLAG) -c $< -o $(<:.c=.o)

all: $(PUSH) ## compil everything exept bonuses

$(PUSH):	$(OBJS_PUSH) $(OBJS_UTL) $(OBJS_MV) ## compil push_swap exe
				$(CC) $(FLAG) $(OBJS_PUSH) $(OBJS_UTL) $(OBJS_MV) -o $(PUSH)

$(CHECK):	$(OBJS_CHCK) $(OBJS_UTL) $(OBJS_MV) ## compil checker exe
				$(CC) $(FLAG) $(OBJS_CHCK) $(OBJS_UTL) $(OBJS_MV) -o $(CHECK)

bonus: $(CHECK) $(PUSH)	## compil everything including bonuses

clean: ## deletes every object file
			rm -f $(OBJS_PUSH)
			rm -f $(OBJS_CHCK)
			rm -f $(OBJS_UTL)
			rm -f $(OBJS_MV)

fclean: clean ## like clean, delete exe too
			rm -f $(PUSH)
			rm -f $(CHECK)
re: fclean all ## remake everything from ground up

help: ## you found me
		@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?##"}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: all re clean fclean help
