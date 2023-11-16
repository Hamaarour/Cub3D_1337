# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 13:13:10 by hamaarou          #+#    #+#              #
#    Updated: 2023/11/17 00:31:42 by hamaarou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3D
BONUS=cub3D_bonus
CC=cc
CFLAGS=-Wall -Wextra -Werror
FRAMWORK=-lmlx -framework OpenGL -framework AppKit -Ofast

LIB = ./library/lib.a

SRC = mandatory/cub3d.c \
		mandatory/src/mlx/mlx_put_pixel.c \
		mandatory/src/parsing/check_map.c mandatory/src/parsing/cleanup.c mandatory/src/parsing/directions.c mandatory/src/parsing/graphics.c mandatory/src/parsing/initialize.c  \
		mandatory/src/parsing/is_surrounded.c mandatory/src/parsing/parse.c mandatory/src/parsing/player.c mandatory/src/parsing/rect_map.c mandatory/src/parsing/rgbs.c mandatory/src/parsing/utils.c \
		mandatory/src/raycasting/events/checks.c mandatory/src/raycasting/events/help_keys.c  mandatory/src/raycasting/events/keys.c \
		mandatory/src/raycasting/utils/player_init.c mandatory/src/raycasting/utils/render.c \
		mandatory/src/raycasting/line/line_draw.c \
		mandatory/src/raycasting/walls/bilding_walls.c mandatory/src/raycasting/walls/help_building.c mandatory/src/raycasting/walls/renderwall.c \
		mandatory/src/raycasting/textures_init/textures_init.c

SRC_B= bonus/cub3d.c \
		bonus/src/mlx/mlx_put_pixel.c \
		bonus/src/parsing/check_map.c bonus/src/parsing/cleanup.c bonus/src/parsing/directions.c bonus/src/parsing/graphics.c bonus/src/parsing/initialize.c  \
		bonus/src/parsing/is_surrounded.c bonus/src/parsing/parse.c bonus/src/parsing/player.c bonus/src/parsing/rect_map.c bonus/src/parsing/rgbs.c bonus/src/parsing/utils.c \
		bonus/src/raycasting/events/checks.c bonus/src/raycasting/events/help_keys.c  bonus/src/raycasting/events/keys.c \
		bonus/src/raycasting/utils/player_init.c bonus/src/raycasting/utils/render.c \
		bonus/src/raycasting/line/line_draw.c \
		bonus/src/raycasting/walls/bilding_walls.c bonus/src/raycasting/walls/help_building.c bonus/src/raycasting/walls/renderwall.c \
		bonus/src/raycasting/textures_init/textures_init.c \
		bonus/src/raycasting/minimap/minimap.c


OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)
LIB_SRC = $(wildcard ./library/*.c)

GREEN = \033[0;32m
YELLOW = \033[0;33m
ORANGE = \033[0;33m
RED = \033[0;31mmake
NC = \033[0m

all: $(NAME)

$(LIB) : $(LIB_SRC)
	@make -C ./library

$(NAME): $(SRC) $(LIB)
	@echo "$(YELLOW)Compiling cub3D...$(NC)"
	@echo "$(GREEN)🎮 Game is Ready 🎮$(NC)"
	@$(CC) $(CFLAGS) $(SRC) $(LIB) $(FRAMWORK) -o $(NAME)

bonus : $(BONUS)

$(BONUS) : $(SRC_B) $(LIB)
	@echo "$(YELLOW)Compiling cub3D Bonus...$(NC)"
	@echo "$(GREEN)🎮 Game is Ready 🎮$(NC)"
	@$(CC) $(CFLAGS) $(SRC_B) $(LIB) $(FRAMWORK) -o $(BONUS)

clean:
	@echo "$(ORANGE)Cleaning...$(NC)"
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_B)
	@make -C  ./library clean

fclean:clean
	@echo "$(RED)Fcleaning...$(NC)"
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	@make -C  ./library fclean

re: fclean all
