NAME = ft_ls

FILES = main.c modes.c sort.c \
		flags.c \
		error.c \
		store_arg.c \
		print.c \
		flag_l.c \
		free.c \
		flag_capr.c \
		no_flags.c \
		flags_only.c \
		help_flag_l.c \
		flag_o_g.c

OFILES = main.o modes.o sort.o \
		flags.o \
		error.o \
		store_arg.o \
		print.o \
		flag_l.o \
		free.o \
		flag_capr.o \
		no_flags.o \
		flags_only.o \
		help_flag_l.o \
		flag_o_g.o

FLAG = -Wextra -Werror -Wall

all: $(NAME)

$(NAME): $(OFILES)
		@make -C libft
		@gcc $(FLAG) -c $(FILES)
		ar rc ft_ls.a $(OFILES)
		@gcc $(FLAG) main.c ft_ls.a \
	   	libft/libft.a -o $(NAME)


clean:
		@make fclean -C libft
		rm -f $(OFILES)

fclean: clean
		@rm -f $(NAME)

re:	fclean all
