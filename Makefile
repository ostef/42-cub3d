NAME = cube
INCLUDE_DIRS = . libft mlx
INCLUDE_FILES = cube.h
SRC_DIR = source
SRC_FILES = main.c
SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJ_DIR = obj
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))
LIB_DIRS = libft mlx
LIBS = ft mlx
DEPENDENCIES = $(INCLUDE_FILES) Makefile libft/libft.a mlx/libmlx.a
CC = gcc
C_FLAGS = $(addprefix -I, $(INCLUDE_DIRS)) -Wall -Wextra -Werror
LINK_FLAGS = $(addprefix -L, $(LIB_DIRS)) $(addprefix -l, $(LIBS)) -framework OpenGL -framework AppKit

all : | libft mlx $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPENDENCIES)
	@mkdir -p $(dir $@)
	$(CC) $(C_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LINK_FLAGS) -o $(NAME)

libft:
	@make -C libft

mlx:
	@make -C mlx

clean:
	@make -C libft clean
	@make -C mlx clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) libmlx.dylib
	$(RM) $(NAME)

re: fclean all

.PHONY: all libft mlx clean fclean re