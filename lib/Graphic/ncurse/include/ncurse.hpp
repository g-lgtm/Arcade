/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-raphael.zeitoun
** File description:
** ncurse
*/

#ifndef NCURSE_HPP_
#define NCURSE_HPP_

#include "../../IGraphic.hpp"
#include <ncurses.h>

extern "C" std::unique_ptr<IGraphic> create();

class ncurse : public IGraphic {
        bool check_size_terminal();
        void print_quit() const;
        void print_graphic() const;
        void print_games() const;
        void print_highscore();
        void print_draw() const;
        void print_all_menu();
        void set_pos_cursor();
        bool ncurse_initialiser();
        void ncurse_stopper() const;
        void ncurse_colors() const;
        int event_key(int &pos, int &result, int &key) const;
        bool get_hightscore();
        int xcursor[5];
        int ycursor[5];
        int key;
        void ncurse_ini_end();
        std::string hightscorepacman, hightscorenibblers, pacman_draw;
    public:
        ncurse();
        virtual ~ncurse();
        virtual std::string getName() const;
        virtual int draw_game(std::string *map, int score);
        virtual int draw_menu();
        virtual globalKeys::keys_t getGlobalKey();
        virtual void unload_pacman();
        virtual void unload_nibbler();
        virtual std::string draw_end(int scrore, bool is_win);
};

#endif /* !NCURSE_HPP_ */
