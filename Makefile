NAME = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = obj

SRC = megaphone.cpp

OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEP = $(SRC:%.cpp=$(OBJ_DIR)/%.d)

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -MMD -MF $(@:.o=.d) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ) $(DEP)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
