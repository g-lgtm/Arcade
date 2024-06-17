/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-gael.leroy
** File description:
** global_keys
*/

#ifndef GLOBAL_KEYS_HPP_
#define GLOBAL_KEYS_HPP_

#include <fstream>

namespace globalKeys {
    enum keys_t {
        NOTHING = 0,
        NEXTGAME,
        PREVGAME,
        NEXTGRAPH,
        PREVGRAPH,
        RESTART,
        MENU,
        EXIT,
        SAVE,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        SHOOT,
        PAUSE,
    };
}

#endif /* !GLOBAL_KEYS_HPP_ */