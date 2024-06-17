/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-gael.leroy
** File description:
** IGraphic
*/

#ifndef IGRAPHIC_HPP_
#define IGRAPHIC_HPP_

#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <list>
#include <unordered_map>
#include "../global_keys.hpp"

class IGraphic {
    std::string _name;
    public:
        IGraphic() = delete;
        virtual ~IGraphic() = default;
        virtual std::string getName() const {
            return (this->_name);
        };
        virtual int draw_game(std::string *map, int score = 0) = 0;
        virtual int draw_menu() = 0;
        virtual void load_pacman() {};
        virtual void unload_pacman() {};
        virtual void load_nibbler() {};
        virtual void unload_nibbler() {};
        virtual globalKeys::keys_t getGlobalKey() {
            return (globalKeys::NOTHING);
        };
        virtual std::string draw_end(int score, bool is_win) {
            (void)score;
            (void)is_win;
            return (std::string());
        };
    protected:
        IGraphic(const std::string &name) {
            this->_name = name;
        };
};

#endif /* !IGRAPHIC_HPP_ */