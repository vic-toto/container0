NAME	=	ft_containers
CPPC	=	c++
FLAGS	=	-Wall -Wextra -Werror
SRCS	=	srcs/*.cpp
OBJS	=	$(SRCS:.cpp=.o)

%.o			:	%.cpp
				$(CPPC) $(FLAGS) -c $< -o $@

all		:	$(NAME)

$(OBJS)	:	$(SRCS)
	-@$(CPPC) $(FLAGS) $(SRCS) -o $(NAME)

$(NAME) : $(OBJS)
	@echo Compiling: $(NAME)
	@$(CPPC) $(FLAGS) $(SRCS) -o $(NAME)
	@echo $NAME compiled successfully

clean:
	@echo Deleting objects files...
	@rm -f $(OBJS)
	@echo Deleting done!

fclean: clean
	@echo Deleting $(NAME)...
	@rm $(NAME)
	@rm -f $(OBJS)
	@echo Deleting done!

re: fclean all

.PHONY: all clean fclean re