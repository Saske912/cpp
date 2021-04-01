FLAG = -Wall -Wextra -Werror
NAME = megaphone
FILE = megaphone.cpp
OBJ = $(FILE:.cpp=.o)

$(NAME):
	g++ $(FLAG) $(FILE) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
