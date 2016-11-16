# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglens <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 17:25:06 by cglens            #+#    #+#              #
#    Updated: 2016/08/25 01:17:22 by cglens           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gcc 

SRC = fdf.c\
	  init.c\
	  key_code.c\
	  roset.c\
	  error.c\

OBJ = $(SRC:.c=.o) 

EXEC = fdf

$(NAME) :
	make -C libft	
	gcc -g  -lmlx -framework OpenGL -framework AppKit -o $(EXEC) libft/libft.a $(SRC)
clean:
	rm -f $(OBJ) $(EXEC)
	make clean -C libft

fclean: clean
	make fclean -C libft

re: fclean $(NAME)
	make fclean all -C libft

####################
#---BLA-BLA-BLA----#
####################
#recuperer la map
#lire -> atoi
#lire une valeur = 
#	i/j correspondent a lemplacement de la valeur dans le tableau
#	donner une hauteur de la valeur indique a l emplacement i/j(du tab) dans la map(pixl)
#images
