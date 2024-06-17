/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-gael.leroy
** File description:
** nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "../../IGame.hpp"

extern "C" std::unique_ptr<IGame> create();

typedef struct pos_s {
    int rank;
    char head;
} pos_t;

class nibbler : public IGame {
public:
    nibbler();
    virtual ~nibbler();
    virtual int simulate(globalKeys::keys_t key);
    virtual std::string getName() const;
    virtual std::string *get_ptrMap();
    virtual int get_score();
private:
    bool move_body(char move);
    int len;
    int score;
    std::string *map;
    std::list<pos_t> body;
};

#endif /* !nibbler_HPP_ */
