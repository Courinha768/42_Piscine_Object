NAME			= Vector

SRCS			= main.cpp srcs/Graph.cpp srcs/Vector2.cpp srcs/Line.cpp srcs/utils/writeToPng.cpp srcs/utils/writeToOs.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= @c++
CXXFLAGS		= -Wall -Wextra -Werror -I. -std=c++98
LDFLAGS			= `pkg-config --libs cairo`

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
				@rm -rf $(OBJS)
				@echo "\e[1mObject files deleted\033[0m"

fclean:			clean
				@rm -rf $(NAME)
				@echo "\e[1mExecutable files deleted\033[0m"

re:				fclean $(NAME)

setup:
				sudo apt install libcairo2-dev

run:			re
				@./Vector

.PHONY:			all clean fclean re