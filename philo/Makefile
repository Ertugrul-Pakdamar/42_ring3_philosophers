NAME=philo

SRC=	*.c \
		srcs/*.c \
		srcs/*/* \

all: $(NAME)

$(NAME): $(SRC)
	@cc -Wall -Wextra -Werror $(SRC) -o $(NAME) -Iincludes
	@echo "Project Compiled Successfully."

clean:
	@rm -f philo
	@echo "Project Cleaned Successfully."

fclean: clean

re: fclean all
