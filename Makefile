# Colours
T_BLK = \033[5m
T_NRM = \033[25m
T_CLR = \033[K
C_YLW = \033[33m
C_LRED = \033[91m
C_GRN = \033[32m
C_LYLW = \033[93m
C_LGRN = \033[92m
C_LMGN = \033[95m
C_END = \033[0m

NAME = ft_containers

SRC_DIR = ./srcs/
HEADERS_DIR := ./includes/
OBJS_DIR := ./obj/

SRC = main.cpp

SRCS = ${addprefix $(SRC_DIR), $(SRC)}
FLAGS = -Wall -Wextra -Werror -g -std=c++98

OBJ 		= 	$(SRCS:.cpp=.o)
OBJS := $(patsubst %.cpp,$(OBJS_DIR)%.o,$(SRC))

HEADERS := $(HEADERS_DIR)*.hpp
DEPS := $(HEADERS)

NB = $(words $(SRCS))
IND = 0
PER = 0

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS) $(DEPS)
	@echo "$(C_LYLW)➜ [$(NAME)] Compiling objects ... $(C_END)"
	@clang++ $(FLAGS) -I$(HEADERS) $(OBJS) -o $@
	@echo "\033[1A$(T_CLR)$(C_LGRN)➜ [$(NAME)] Objects have been compiled successfully ! $(C_END)"
	@echo "$(C_LGRN)➜ [$(NAME)] $(NAME) has been Compiled Successfully !$(C_END)"

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

$(OBJS_DIR)%.o : $(SRC_DIR)%.cpp $(DEPS)
	@clang++ $(FLAGS)  -I$(HEADERS) -c $< -o $@
	@$(eval IND=$(shell echo $$(($(IND) + 1))))
	@$(eval PER=$(shell echo $$((($(IND) * 100) / $(NB)))))
	@printf "$(T_CLR)$(C_LMGN)➜ progress: %3d %% $(C_END)\n\033[1A$(C_END)" $(PER);


clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(C_LYLW)➜ [$(NAME)] Objects have been cleaned Successfully !$(C_END)"


fclean: clean
	@rm -f $(NAME)
	@rm -f mine.txt real.txt
	@echo "$(C_LRED)➜ [$(NAME)] $(NAME) has been deleted Successfully !$(C_END)"

re: fclean all
	@echo "$(C_LMGN)➜ [$(NAME)] $(NAME) has been re-builded \
	Successfully !$(C_END)"

run: all exec diff

exec:
	@./$(NAME) 5

diff:
	@if [ $(SRC) = "main.cpp" ]; then \
		echo "$(C_LMGN)➜ Printing differences!$(C_END)"; \
		$(shell (touch mine.txt)) \
		$(shell (touch real.txt)) \
		if [ $(shell (diff real.txt mine.txt | wc -l | xargs)) = "0" ]; then \
			echo "$(C_GRN)➜ No differences detected !$(C_END)"; \
		else \
			echo "$(C_LRED)➜ Differences detected !$(C_END)"; \
		fi \
	fi
	
leaks: all
	@leaks --atExit -- ./$(NAME)

.PHONY:		all clean fclean re testall leaks test1 test2 run intra
