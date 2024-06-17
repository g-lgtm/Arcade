/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-gael.leroy
** File description:
** nibbler
*/

#include "../include/nibbler.hpp"

nibbler::nibbler(): IGame("nibbler", "lib/Games/nibbler/map/map_nibbler.txt") {
    this->map = IGame::get_ptrMap();
    for (int i = 0; i < (int)(*map).length(); i++) {
        if ((*map)[i] == 'B' || (*map)[i] == 'r' || (*map)[i] == 'd' || (*map)[i] == 'l' || (*map)[i] == 'u')
            body.emplace_front((pos_t){i, (*map)[i]});
    }
    for (this->len = 0; (*map)[this->len] != '\n'; this->len++);
    this->score = 0;
}

nibbler::~nibbler() {
    ;
}

static bool is_dead(std::string &map, int rank, char move, int len)
{
    int change = rank;
    char up = map[change -  len], left = map[change - 1], right = map[change + 1], down = map[change + len];
    if (move == 'u' && !(left != 'x' && right != 'x' && up != 'x'))
        return (true);
    if (move == 'l' && !(up != 'x' && left != 'x' && down != 'x'))
        return (true);
    if (move == 'd' && !(left != 'x' && right != 'x' && down != 'x'))
        return (true);
    if (move == 'r' && !(right != 'x' && up != 'x' && down != 'x'))
        return (true);
    return (false);
}

bool nibbler::move_body(char move)
{
    int save = (*body.begin()).rank, change = 0;
    if (move == 'r')
        change = save + 1;
    else if (move == 'd')
        change = save + (this->len + 1);
    else if (move == 'l')
        change = save - 1;
    else if (move == 'u')
        change = save - (this->len + 1);
    (*map)[change] = (*map)[save];
    (*map)[save] = ' ';
    auto it = body.begin();
    (*it).rank = change;
    while (++it != body.end()) {
        change = save;
        save = (*it).rank;
        (*it).rank = change;
        (*map)[change] = (*map)[save];
        (*map)[save] = ' ';
    }
    if (is_dead(*map, (*body.begin()).rank, move, this->len + 1))
        return (true);
    return (false);
}

static int count_it(std::string &s, char to_find)
{
    return (std::count(s.begin(), s.end(), to_find));
}

int nibbler::simulate(globalKeys::keys_t key)
{
    pos_t *act = &(*body.begin());
    int change = 0;
    if (key == globalKeys::LEFT) {
        if ((*act).head == 'r')
            (*act).head = 'u';
        else if ((*act).head == 'u')
            (*act).head = 'l';
        else if ((*act).head == 'l')
            (*act).head = 'd';
        else
            (*act).head = 'r';
    }
    else if (key == globalKeys::RIGHT) {
        if ((*act).head == 'r')
            (*act).head = 'd';
        else if ((*act).head == 'u')
            (*act).head = 'r';
        else if ((*act).head == 'l')
            (*act).head = 'u';
        else
            (*act).head = 'l';
    }
    if (move_body((*body.begin()).head))
        return (1);
    if ((*act).head == 'u')
        change = -this->len + 1;
    else if ((*act).head == 'r')
        change = 1;
    else if ((*act).head == 'd')
        change = this->len + 1;
    else
        change = - 1;
    if ((*map)[(*act).rank + change] == 'o') {
        auto it = body.end();
        it--;
        (*map)[(*act).rank + change] = ' ';
        (*map)[(*it).rank - change] = 'B';
        body.emplace_back((pos_t){(*it).rank - change, 'B'});
        this->score += 10;
    }
    if (!count_it(*map, 'o'))
        return (2);
    return (-1);
}

std::string nibbler::getName() const
{
    return (IGame::getName());
}

std::string *nibbler::get_ptrMap()
{
    return (this->map);
}

int nibbler::get_score()
{
    return (this->score);
}

extern "C" std::unique_ptr<IGame> create()
{
    return (std::make_unique<nibbler>());
}