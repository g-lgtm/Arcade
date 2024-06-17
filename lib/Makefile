##
## EPITECH PROJECT, 2021
## B-OOP-400-NCE-4-1-arcade-gael.leroy
## File description:
## Makefile
##

CPPFLAGS    = -fPIC -shared -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

CPPFLAGS	+=	-W -Wall -Wextra

LDFLAGS	=	$(shell sdl2-config --libs) -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

FLAGS	=	-W -Wall -Wextra -std=c++11 -g3 -fPIC -shared

## Games
# Pacman

PACMANDIR	=	Games/pacman/src

PACMANSRC	=	$(PACMANDIR)/pacman.cpp

PACMANOBJ	=	$(PACMANSRC:.cpp=.o)

PACMANNAME	=	arcade_pacman.so

PACMANFLAGS	=	-I./Games/pacman/include

# NIBBLER

NIBBLERDIR	=	Games/nibbler/src

NIBBLERSRC	=	$(NIBBLERDIR)/nibbler.cpp

NIBBLEROBJ	=	$(NIBBLERSRC:.cpp=.o)

NIBBLERNAME	=	arcade_nibbler.so

NIBBLERFLAGS	=	-I./Games/nibbler/include

## Graphic
# Ncurses

NCURSEDIR	=	Graphic/ncurse/src

NCURSESRC	=	$(NCURSEDIR)/ncurse.cpp

NCURSEOBJ	=	$(NCURSESRC:.cpp=.o)

NCURSENAME	=	arcade_ncurses.so

NCURSEFLAGS	=	-I./Graphic/ncurse/include -lncurses

# Sdl2

SDL2DIR	=	Graphic/sdl2/src

SDL2SRC	=	$(SDL2DIR)/sdl2.cpp

SDL2OBJ	=	$(SDL2SRC:.cpp=.o)

SDL2NAME	=	arcade_sdl2.so

SDL2FLAGS	=	-I./Graphic/sdl2/include

# Sfml

SFMLDIR	=	Graphic/sfml/src

SFMLSRC	=	$(SFMLDIR)/sfml.cpp

SFMLOBJ	=	$(SFMLSRC:.cpp=.o)

SFMLNAME	=	arcade_sfml.so

SFMLFLAGS	=	-I./Graphic/sfml/include -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

## Compilation

all:	games graphicals

games:	$(PACMANOBJ) $(NIBBLEROBJ)
		g++ -o $(PACMANNAME) $(PACMANOBJ) $(FLAGS) $(PACMANFLAGS) -I./Games
		g++ -o $(NIBBLERNAME) $(NIBBLEROBJ) $(FLAGS) $(NIBBLERFLAGS) -I./Games

graphicals:	$(NCURSEOBJ) $(SDL2OBJ) $(SFMLOBJ)
		g++ -o $(NCURSENAME) $(NCURSEOBJ) $(FLAGS) -I./Graphic $(NCURSEFLAGS)
		g++ -o $(SDL2NAME) $(SDL2OBJ) $(FLAGS) -I./Graphic $(SDL2FLAGS) $(LDFLAGS)
		g++ -o $(SFMLNAME) $(SFMLOBJ) $(FLAGS) -I./Graphic $(SFMLFLAGS)

clean: cleanGames cleanGraphicals

cleanGames:
		rm -f $(PACMANOBJ) $(NIBBLEROBJ)

cleanGraphicals:
		rm -f $(NCURSEOBJ) $(SDL2OBJ) $(SFMLOBJ)

fclean:	clean
		rm -f $(PACMANNAME) $(NIBBLERNAME)
		rm -f $(NCURSENAME) $(SDL2NAME) $(SFMLNAME)

re:	fclean all

.PHONY:	all clean fclean re games cleanGames graphicals cleanGraphicals