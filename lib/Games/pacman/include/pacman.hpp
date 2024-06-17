/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-raphael.zeitoun
** File description:
** pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "../../IGame.hpp"

extern "C" std::unique_ptr<IGame> create();

class pacman : public IGame {
public:
    pacman();
    virtual ~pacman();
    virtual std::string getName() const;
    virtual std::string *get_ptrMap();
    virtual int simulate(globalKeys::keys_t key);
    virtual int get_score() {
            return (this->score);
        }
private:
    int score;
    int move_all(globalKeys::keys_t  key);
    void move_pac(std::string *map);
    void move_ghost(int &ghost, char &chghost, char &ghostletter, int listghost[], int reset, int resetmax, int &ghost_pos, std::string *map);
    globalKeys::keys_t current_move;
    void god_mode_on();
    void god_mode_off();
    void reset_ghost(int &ghost, char &chghost, int &ghost_pos, int ghost_base, char ghostl, std::string *map);
    int current_pos;
    char ghostletter;
    char ghostletter2;
    char ghostletter3;
    char ghostletter4;
    int ghost;
    int ghost2;
    int ghost3;
    int ghost4;
    int base_ghost;
    int base_ghost2;
    int base_ghost3;
    int base_ghost4;
    char chghost;
    char chghost2;
    char chghost3;
    char chghost4;
    int win;
    int listghost[57];
    int reset;
    int resetmax;
    int listghost2[50];
    int reset2;
    int resetmax2;
    int listghost3[44];
    int reset3;
    int resetmax3;
    int listghost4[56];
    int reset4;
    int resetmax4;
    int ghost_pos;
    int ghost_pos2;
    int ghost_pos3;
    int ghost_pos4;
    int god_mode;
    void get_pacman_pos(std::string *map);
    bool check_move(int i, std::string *map);
    bool check_move_ghost(int i, int &ghost, char &chghost, std::string *map);
    bool check_win(std::string *map);
};

#endif /* !PACMAN_HPP_ */

// haut 
//   U
// bas 
//   n
// gauche
//   D
// Droite
//   C