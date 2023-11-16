# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 13:13:10 by hamaarou          #+#    #+#              #
#    Updated: 2023/11/16 19:05:37 by hamaarou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3D
NAME_BONUS=cub3D_bonus
CC=cc
CFLAGS=-Wall -Wextra -Werror #-g3 -fsanitize=address
FRAMWORK=-lmlx -framework OpenGL -framework AppKit

LIB = ./library/lib.a

SRC = mandatory/cub3d.c $(wildcard mandatory/src/mlx/*.c) \
		$(wildcard mandatory/src/parsing/*.c) \
		$(wildcard mandatory/src/raycasting/events/*.c) $(wildcard mandatory/src/raycasting/utils/*.c) \
		$(wildcard mandatory/src/raycasting/line/*.c) $(wildcard mandatory/src/raycasting/walls/*.c) \
		$(wildcard mandatory/src/raycasting/textures_init/*.c) $(wildcard mandatory/src/raycasting/minimap/*.c)

# SRC_B= cub3d_bonus.c $(wildcard ./bonus/src/mlx/*.c) \
# 		$(wildcard ./bonus/src/parsing/*.c)  \
# 		$(wildcard ./bonus/src/raycasting/events/*.c) $(wildcard ./bonus/src/raycasting/utils/*.c) \
# 		$(wildcard ./bonus/src/raycasting/line/*.c) $(wildcard ./bonus/src/raycasting/walls/*.c) \
# 		$(wildcard ./bonus/src/raycasting/textures_init/*.c) $(wildcard ./bonus/src/raycasting/minimap/*.c)

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

# bonus: $(NAME_BONUS)
# 	$(CC) $(CFLAGS) $(PATH) $(SRC) $(LIB) $(FRAMWORK) -o $(NAME_BONUS)

clean:
	@echo "$(ORANGE)Cleaning...$(NC)"
	@rm -rf $(OBJ)
	@make -C  ./library clean

fclean:clean
	@echo "$(RED)Fcleaning...$(NC)"
	@rm -rf $(NAME)
	@make -C  ./library fclean

re: fclean all
