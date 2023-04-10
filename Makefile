# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 14:12:09 by skhaliff          #+#    #+#              #
#    Updated: 2023/04/10 09:37:41 by skhaliff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = cub3d.c error.c get_next_line.c get_next_line_utils.c check.c position_p.c trans_color.c free_it.c components_cub.c check_map.c
NAME    = cub3D
LBFT	= libft/libft.a
CC		= cc -g
CFLAGS  = -Wall -Wextra -Werror -fsanitize=address
#MX		= -lmlx -framework OpenGL -framework Appkit
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