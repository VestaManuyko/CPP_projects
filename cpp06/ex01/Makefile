NAME = serializer

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
TEST_LFLAGS = -I/usr/src/googletest/googletest/include \
    -L/usr/lib \
    -lgtest -lgtest_main -pthread

TEST_NAME = test
OBJ_DIR = obj
TEST_FILE = output.txt

SRC = main.cpp Serializer.cpp 
TEST_SRC = tests.cpp

OBJ = $(SRC:%.cpp=obj/%.o)
TEST_OBJ = $(TEST_SRC:%.cpp=$(OBJ_DIR)/%.o)

DEP = $(SRC:%.cpp=obj/%.d)
TEST_DEP = $(TEST_SRC:%.cpp=$(OBJ_DIR)/%.d)

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -MMD -MF $(@:.o=.d) -c $< -o $@

$(OBJ_DIR)/tests.o: tests.cpp | $(OBJ_DIR)
	@$(CC) -MMD -MF $(OBJ_DIR)/tests.d -c $< -o $@

$(NAME): $(OBJ) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(TEST_NAME): $(TEST_OBJ) | $(NAME) $(OBJ_DIR) 
	@$(CC) $(CFLAGS) $(TEST_OBJ) $(TEST_LFLAGS) -o $@

clean:
	@rm -f $(OBJ) $(DEP) $(TEST_OBJ) $(TEST_DEP) $(TEST_FILE)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
-include $(TEST_DEP)
