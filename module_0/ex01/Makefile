NAME = crappy
HEADER = Crappy.hpp
FLAGS = -Wall -Wextra -Werror
FILE = Crappy.cpp main.cpp add.cpp search.cpp
OBJ = $(FILE:.cpp=.o)

$(NAME):
	g++ $(FLAGS) $(FILE) $(HEADER) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
