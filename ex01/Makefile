
NAME	= main

CXX		= c++

CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

SRC		= main.cpp Form.cpp Bureaucrat.cpp 

OBJ = $(SRC:%.cpp=%.o)

all		: $(NAME)

$(NAME)	: $(OBJ)
		$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean	:
	rm -rf $(OBJ)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
