/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-gael.leroy
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <chrono>
#include <ctime>
#include <cstring>
#include <list>
#include <algorithm>
#include "../global_keys.hpp"

class IGame {
    std::string _name;
    std::string map;
    std::string current_score;
    std::string player_name;
    int score;
    public:
        IGame() = delete;
        virtual ~IGame() = default;
        virtual int get_score() {
            return (this->score);
        }
        virtual int simulate(globalKeys::keys_t key) {
            (void)key;
            return (-1);
        };
        virtual std::string getName() const {
            return (this->_name);
        };
        virtual std::string *get_ptrMap() {
            return (&map);
        };
    protected:
        IGame(const std::string &name, const std::string &filepath) {
            std::ifstream fs(filepath);
            std::stringstream buffer;
            if (fs.is_open()) {
                buffer << fs.rdbuf();
                fs.close();
                this->map = buffer.str();
            } else
                this->map = "ERROR";
            this->_name = name;
        };
};

#endif /* !IGAME_HPP_ */