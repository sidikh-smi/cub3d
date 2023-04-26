# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 00:40:29 by ebakchic          #+#    #+#              #
#    Updated: 2023/04/15 10:30:38 by skhaliff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = ft_free_db.c ft_run_game.c ft_manage_key.c ft_init.c ft_move.c	ft_render.c ft_raycasting.c ft_norm.c ft_mini_map.c ft_textur.c\
		parse/cub3d.c parse/error.c parse/get_next_line.c parse/get_next_line_utils.c parse/check.c parse/position_p.c parse/trans_color.c parse/free_it.c parse/components_cub.c parse/check_map.c parse/new_line.c parse/init.c parse/Textures.c parse/path_textur.c
NAME    = cub3D
LBFT	= libft/libft.a
CC		= cc -O3
CFLAGS  = -Wall -Wextra -Werror
MX		= -lmlx -framework OpenGL -framework Appkit
MAKEC	= make clean
MAKEF	= make fclean
MAKER	= make re
OBJS 	= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): ${OBJS}
	@$(MAKE) -C libft
	@$(CC) $(CFLAGS) $(MX) ${LBFT} ${OBJS} -o ${NAME}

clean:
	@$(MAKEC) -C libft
	@${RM} ${OBJS}

fclean: clean
	@$(MAKEF) -C libft
	@${RM} ${NAME}

re: fclean all
	@$(MAKER) -C libft

.PHONY: all clean fclean re
