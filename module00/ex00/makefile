NAME			= DivideAndRule

SRCS			= main.cpp Bank.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= @c++
CXXFLAGS		= -Wall -Wextra -Werror -I. -std=c++98

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				@rm -rf $(OBJS)

fclean:			clean
				@rm -rf $(NAME)

re:				fclean $(NAME)

run:			re
				@./DivideAndRule

.PHONY:			all clean fclean re