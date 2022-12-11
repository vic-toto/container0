NAME = ft_container

SRCS =  srcs/main.cpp \
		srcs/test.cpp \
		srcs/test_utils.cpp \
		srcs/test_vector.cpp \
		srcs/test_stack.cpp \
		srcs/test_map.cpp \
		srcs/rb_tree.cpp


INCLUDES = includes/.

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) -I$(INCLUDES)

all : $(NAME)

leaks : $(NAME)
		leaks --atExit -- ./$(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf ${NAME}

re : fclean all
