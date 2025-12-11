NAME = form
CC = c++
CFLAGS = -std=c++98 -Wall -Werror -Wextra

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

SRCS = main.cpp \
		Bureaucrat.cpp \
		Form.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
		@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "$(GREEN)[$(NAME)] Compiled successfully!$(RESET)"

clean:
		@rm -f $(OBJS)
		@echo "$(YELLOW)[$(NAME)] Object files removed.$(RESET)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(RED)[$(NAME)] Executable removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re