/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-gael.leroy
** File description:
** main
*/

#include "arcade.hpp"

int main(int const ac, char const **av)
{
    arcade arcade(ac, av);
    int state = 0;
    arcade.check_arg();
    state = arcade.get_lib();
    if (state == 84 || state == 0)
        return (state == 84 ? 84 : 0);
    try {
        arcade.set_lib_graphic();
    } catch (const std::string error) {
        std::cerr << error << std::endl;
        return (84);
    }
    state = 0;
    while (42) {
        arcade.menu();
        state = arcade.get_game();
        if (state == 84 || state == 0)
            return (state == 84 ? 84 : 0);
        if (state < 5) {
            try {
                arcade.set_lib_graphic(state);
            } catch (const std::string error) {
                std::cerr << error << std::endl;
                return (84);
            }
        }
        arcade.game();
        arcade.menu_end();
        state = arcade.get_state();
        if (state == END || state == ERROR)
            break;
    }
    if (state == END || state == ERROR) {
        try {
            arcade.set_lib_game(0);
        } catch (const std::string &error) {};
        try {
            arcade.set_lib_graphic(0);
        } catch (const std::string &error) {};
        return (state == ERROR ? 84 : 0);
    }
    return (0);
}