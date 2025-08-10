NAME=philo

SRC=	ft_main.c \
		srcs/* \

all: $(NAME)

$(NAME): $(SRC)
	@cc -Wall -Wextra -Werror $(SRC) -o $(NAME) -Iincludes
	@echo "Project Compiled Successfully."

clean:
	@rm -rf philo
	@echo "Project Cleaned Successfully."

fclean: clean

re: fclean all
