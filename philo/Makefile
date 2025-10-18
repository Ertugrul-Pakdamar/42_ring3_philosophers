NAME=philo

SRC=	*.c \
		srcs/*.c \
		srcs/*/* \

all: $(NAME)

$(NAME): $(SRC)
	@cc -Wall -Wextra -Werror $(SRC) -o $(NAME) -Iincludes
	@echo "Project Compiled Successfully."

clean:

fclean: clean
	@rm -f philo
	@echo "Project Cleaned Successfully."

re: fclean all
