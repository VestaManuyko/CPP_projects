NAME = replace

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
TEST_LFLAGS = -lgtest -lgtest_main

TEST_NAME = tests
OBJ_DIR = obj

SRC = main.cpp Replace.cpp
TEST_SRC = tests.cpp

OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
TEST_OBJ = $(TEST_SRC:%.cpp=$(OBJ_DIR)/%.o)

DEP = $(SRC:%.cpp=$(OBJ_DIR)/%.d)
TEST_DEP = $(TEST_SRC:%.cpp=$(OBJ_DIR)/%.d)

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -MMD -MF $(@:.o=.d) -c $< -o $@

$(OBJ_DIR)/tests.o: tests.cpp | $(OBJ_DIR)
	@$(CC) -std=c++11 -MMD -MF $(OBJ_DIR)/tests.d -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@

$(TEST_NAME): $(NAME) $(OBJ_DIR) $(TEST_OBJ)
	@$(CC) $(CFLAGS) $(TEST_OBJ) $(TEST_LFLAGS) -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
-include $(TEST_DEP)
