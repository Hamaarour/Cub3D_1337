# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/18 13:13:10 by hamaarou          #+#    #+#              #
#    Updated: 2023/08/28 09:47:43 by hamaarou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=Cub3D
CC=cc
CFLAGS=-Wall -Wextra -Werror #-g3 -fsanitize=address

SRC= cub3d.c \
	Parsing/read_map.c \
	Parsing/config/config_is_set.c \
	Parsing/player/num_of_player.c Parsing/player/position.c\
	Parsing/directions/cardinal_directions.c Parsing/directions/parsing_textures.c \
	Parsing/floor_ceiling/rgb_parse.c Parsing/floor_ceiling/checks.c Parsing/floor_ceiling/rgb.c Parsing/floor_ceiling/rgb_is_set.c\
	Parsing/free/free_array.c  Parsing/free/free_textures.c  Parsing/free/free_rgb.c Parsing/free/free_all.c\
	Parsing/init_struct/init.c \
	Parsing/map/dimension.c Parsing/map/map_is_last.c Parsing/map/is_map_closed.c Parsing/map/rectangle.c Parsing/map/map_lines.c Parsing/map/map_check.c \
	
OBJ=$(SRC:.c=.o)


LIBFT_DIR = ./Library/Libft
GNL_DIR = ./Library/Get_next_line

# Colors for messages
GREEN = \033[0;32m
ORANGE = \033[0;33m
RED= \033[0;31m
NC = \033[0m

all: $(NAME)

$(NAME): $(SRC)
	@ echo "$(GREEN)Building Libft... 🛠⏳$(NC)"
	@ make -C $(LIBFT_DIR) > /dev/null
	@ echo "$(GREEN)Building Get_next_line...🛠⏳$(NC)"
	@ make -C $(GNL_DIR) > /dev/null
	@ echo "$(GREEN)Compiling $(NAME)...🛠⏳$(NC)"
	@ $(CC) $(CFLAGS)  $(SRC) $(LIBFT_DIR)/libft.a $(GNL_DIR)/GNL  -o $(NAME) 
	@ echo "$(GREEN)Finished compiling $(NAME) ✅ ✅ $(NC)"

clean:
	@ echo "$(ORANGE)Cleaning object files...🧹🧹🧹$(NC)"
	@ make clean -C $(LIBFT_DIR) > /dev/null
	@ make clean -C $(GNL_DIR) > /dev/null
	@ rm -f $(OBJ)

fclean: clean
	@ echo "$(ORANGE)Cleaning executable...🧹🧹🧹$(NC)"
	@ make fclean -C $(LIBFT_DIR)  > /dev/null
	@ make fclean -C $(GNL_DIR) > /dev/null
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
