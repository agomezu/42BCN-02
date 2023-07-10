# Colors
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# Program name
NAME	= fractol

# Compiler
CC		= gcc
CFLAGS		= -Wall -Wextra -Werror

# Minilibx
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX		= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC 		=	-I ./includes/\
      			-I ./libft/\
      			-I ./minilibx-linux/

# Sources
SRC_PATH	=	src/
SRC		=	fractol.c 
SRCS		=	$(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	=	obj/
OBJ		=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)fractal_sets
	@mkdir $(OBJ_PATH)color_schemes/

$(MLX):
	@echo "Making MiniLibx..."
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "$Making libft..."
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	@echo "Compiling fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm
	@echo "$(GREEN)Fractol ready.$(RESET)"

bonus: all

clean:
	@echo "$(RED)Removing .o object files...$(RESET)"
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@echo "$(RED)Removing fractol...$(RESET)"
	@rm -f $(NAME)
	@rm -f $(LIFBT_PATH)$(LIBFT_NAME)

re: fclean all

.PHONY: all re clean fclean
