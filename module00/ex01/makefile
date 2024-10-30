NAME			= Vector

SRCS			= main.cpp Graph.cpp Vector2.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= @c++
CXXFLAGS		= -Wall -Wextra -Werror -I. -std=c++98

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				@rm -rf $(OBJS)
				@echo "\e[1mObject files deleted\033[0m"

fclean:			clean
				@rm -rf $(NAME)
				@echo "\e[1mExecutable files deleted\033[0m"

re:				fclean $(NAME)

.PHONY:			all clean fclean re