##
## EPITECH PROJECT, 2021
## B-OOP-400-NCE-4-1-arcade-gael.leroy
## File description:
## Makefile
##

SRC	=	Core/src/core.cpp \
		arcade.cpp \
		main.cpp

CPPFLAGS	+=	-W -Wall -Wextra

OBJ	=	$(SRC:.cpp=.o)

NAME	=	arcade

FLAGS	=	-W -Wall -Wextra -std=c++11 -g3 -fPIC -shared

all:	core
		make -C lib/

games:
		make games -C lib/

core:	$(OBJ)
		g++ -o $(NAME) $(OBJ) -std=c++11 -g3 -ldl -I./Core/include -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

graphicals:
		make graphicals -C lib/

clean:
		make clean -C lib/
		rm -f $(OBJ)

fclean:	clean
		make fclean -C lib/
		rm -f $(NAME)

re:	fclean all

.PHONY:	games core graphicals all clean fclean re