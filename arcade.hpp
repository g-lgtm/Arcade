/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-gael.leroy
** File description:
** arcade
*/

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

#include <dlfcn.h>
#include <string>
#include <iostream>
#include <cstring>
#include <chrono>
#include <ctime>
#include <sys/time.h>
#include "Core/include/core.hpp"
#include <unordered_map>
#include "lib/Games/IGame.hpp"
#include "lib/Graphic/IGraphic.hpp"

#define NCURSE "./lib/arcade_ncurses.so"
#define SFML "./lib/arcade_sfml.so"
#define SDL "./lib/arcade_sdl2.so"
#define PACMAN "./lib/arcade_pacman.so"
#define NIBBLER "./lib/arcade_nibbler.so"

enum core_state {
    MENU = 0,
    GAME,
    MEND,
    END,
    ERROR,
    CHANGE
};

class arcade {
public:
    arcade(int const ac, char const **av);
    ~arcade();
    int get_lib();
    int get_game();
    void check_arg();
    void help();
    void set_lib_graphic(int lib = -1);
    void next_lib_graphic();
    void prev_lib_graphic();
    void set_lib_game(int lib = -1);
    void next_lib_game();
    void prev_lib_game();

    void menu();
    void game();
    void menu_end();
    int get_state();
    void draw_map();
    void save_progress(int score);
    int get_int(const std::string &str);
private:
    void *handle_graphic;
    void *handle_game;
    char const **_av;
    int _ac;
    int current_game;
    int current_lib;
    std::unordered_map <int, char const *> libmap;
    std::unique_ptr<IGraphic> (*_create_graphic)();
    std::unique_ptr<IGraphic> _graphic;
    std::unique_ptr<IGame> (*_create_game)();
    std::unique_ptr<IGame> _game;
    int state;
    std::string *_map;
    bool is_win;
};


#endif /* !ARCADE_HPP_ */