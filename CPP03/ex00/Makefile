NAME = ClapTrap

CXX = c++

CXX_FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp ClapTrap.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
			$(CXX) $(CXX_FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
		$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: all clean fclean

.PHONY: all clean fclean re
