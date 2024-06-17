/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-raphael.zeitoun
** File description:
** pacman
*/

#include "../include/pacman.hpp"

pacman::pacman(): IGame("pacman", "lib/Games/pacman/map/map_pacman.txt") {
    this->current_move = globalKeys::NOTHING;
    this->score = 0;
    this->win = 0;
    this->chghost = ' ';
    this->chghost2 = ' ';
    this->chghost3 = ' ';
    this->chghost4 = ' ';
    this->ghostletter = 'f';
    this->ghostletter2 = 'g';
    this->ghostletter3 = 'w';
    this->ghostletter4 = 'm';

    this->listghost[0] = 2;
    this->listghost[1] = -100;
    this->listghost[2] = -100;
    this->listghost[3] = -100;
    this->listghost[4] = -2;
    this->listghost[5] = -2;
    this->listghost[6] = -2;
    this->listghost[7] = 100;
    this->listghost[8] = 100;
    this->listghost[9] = 100;
    this->listghost[10] = 100;
    this->listghost[11] = 100;
    this->listghost[12] = 100;
    this->listghost[13] = 100;
    this->listghost[14] = -2;
    this->listghost[15] = -2;
    this->listghost[16] = -2;
    this->listghost[17] = -2;
    this->listghost[18] = -2;
    this->listghost[19] = -2;
    this->listghost[20] = -2;
    this->listghost[21] = -2;
    this->listghost[22] = 100;
    this->listghost[23] = 100;
    this->listghost[24] = 2;
    this->listghost[25] = 2;
    this->listghost[26] = 100;
    this->listghost[27] = 100;
    this->listghost[28] = -2;
    this->listghost[29] = -2;
    this->listghost[30] = 100;
    this->listghost[31] = 100;
    this->listghost[32] = 100;
    this->listghost[33] = 2;
    this->listghost[34] = 2;
    this->listghost[35] = 2;
    this->listghost[36] = 2;
    this->listghost[37] = 2;
    this->listghost[38] = 2;
    this->listghost[39] = 2;
    this->listghost[40] = 2;
    this->listghost[41] = 2;
    this->listghost[42] = 2;
    this->listghost[43] = -100;
    this->listghost[44] = -100;
    this->listghost[45] = -100;
    this->listghost[46] = -2;
    this->listghost[47] = -2;
    this->listghost[48] = -100;
    this->listghost[49] = -100;
    this->listghost[50] = -2;
    this->listghost[51] = -2;
    this->listghost[52] = -2;
    this->listghost[53] = -100;
    this->listghost[54] = -100;
    this->listghost[55] = 2;
    this->listghost[56] = 2;
    this->listghost[57] = 2;

    this->listghost2[0] = -2;
    this->listghost2[1] = -100;
    this->listghost2[2] = -100;
    this->listghost2[3] = -100;
    this->listghost2[4] = 2;
    this->listghost2[5] = -100;
    this->listghost2[6] = -100;
    this->listghost2[7] = -100;
    this->listghost2[8] = 2;
    this->listghost2[9] = 2;
    this->listghost2[10] = -100;
    this->listghost2[11] = -100;
    this->listghost2[12] = -100;
    this->listghost2[13] = 2;
    this->listghost2[14] = 2;
    this->listghost2[15] = 2;
    this->listghost2[16] = 100;
    this->listghost2[17] = 100;
    this->listghost2[18] = 100;
    this->listghost2[19] = 2;
    this->listghost2[20] = 2;
    this->listghost2[21] = 2;
    this->listghost2[22] = 2;
    this->listghost2[23] = 2;
    this->listghost2[24] = -100;
    this->listghost2[25] = -100;
    this->listghost2[26] = -100;
    this->listghost2[27] = -100;
    this->listghost2[28] = -100;
    this->listghost2[29] = -100;
    this->listghost2[30] = -2;
    this->listghost2[31] = -2;
    this->listghost2[32] = -2;
    this->listghost2[33] = -2;
    this->listghost2[34] = -2;
    this->listghost2[35] = -2;
    this->listghost2[36] = -2;
    this->listghost2[37] = -2;
    this->listghost2[38] = -2;
    this->listghost2[39] = -2;
    this->listghost2[40] = 100;
    this->listghost2[41] = 100;
    this->listghost2[42] = 100;
    this->listghost2[43] = 2;
    this->listghost2[44] = 2;
    this->listghost2[45] = 100;
    this->listghost2[46] = 100;
    this->listghost2[47] = 100;
    this->listghost2[48] = -2;
    this->listghost2[49] = -2;

    this->listghost3[0] = 2;
    this->listghost3[1] = -100;
    this->listghost3[2] = -100;
    this->listghost3[3] = -2;
    this->listghost3[4] = -100;
    this->listghost3[5] = -100;
    this->listghost3[6] = -100;
    this->listghost3[7] = -2;
    this->listghost3[8] = -2;
    this->listghost3[9] = -100;
    this->listghost3[10] = -100;
    this->listghost3[11] = -100;
    this->listghost3[12] = -2;
    this->listghost3[13] = -2;
    this->listghost3[14] = -2;
    this->listghost3[15] = 100;
    this->listghost3[16] = 100;
    this->listghost3[17] = 100;
    this->listghost3[18] = -2;
    this->listghost3[19] = -2;
    this->listghost3[20] = -2;
    this->listghost3[21] = -2;
    this->listghost3[22] = -2;
    this->listghost3[23] = -100;
    this->listghost3[24] = -100;
    this->listghost3[25] = -100;
    this->listghost3[26] = -100;
    this->listghost3[27] = -100;
    this->listghost3[28] = -100;
    this->listghost3[29] = 2;
    this->listghost3[30] = 2;
    this->listghost3[31] = 2;
    this->listghost3[32] = 2;
    this->listghost3[33] = 2;
    this->listghost3[34] = 2;
    this->listghost3[35] = 2;
    this->listghost3[36] = 2;
    this->listghost3[37] = 2;
    this->listghost3[38] = 2;
    this->listghost3[39] = 100;
    this->listghost3[40] = 100;
    this->listghost3[41] = 100;
    this->listghost3[42] = -2;
    this->listghost3[43] = -2;
    this->listghost3[44] = -2;

    this->listghost4[0] = -2;
    this->listghost4[1] = -100;
    this->listghost4[2] = -100;
    this->listghost4[3] = -100;
    this->listghost4[4] = 2;
    this->listghost4[5] = 2;
    this->listghost4[6] = 2;
    this->listghost4[7] = 100;
    this->listghost4[8] = 100;
    this->listghost4[9] = 100;
    this->listghost4[10] = 100;
    this->listghost4[11] = 100;
    this->listghost4[12] = 100;
    this->listghost4[13] = 100;
    this->listghost4[14] = -2;
    this->listghost4[15] = -2;
    this->listghost4[16] = 100;
    this->listghost4[17] = 100;
    this->listghost4[18] = 2;
    this->listghost4[19] = 2;
    this->listghost4[20] = 100;
    this->listghost4[21] = 100;
    this->listghost4[22] = -2;
    this->listghost4[23] = -2;
    this->listghost4[24] = 100;
    this->listghost4[25] = 100;
    this->listghost4[26] = 100;
    this->listghost4[27] = 2;
    this->listghost4[28] = 2;
    this->listghost4[29] = 2;
    this->listghost4[30] = 2;
    this->listghost4[31] = 2;
    this->listghost4[32] = 2;
    this->listghost4[33] = 2;
    this->listghost4[34] = 2;
    this->listghost4[35] = 2;
    this->listghost4[36] = 2;
    this->listghost4[37] = -100;
    this->listghost4[38] = -100;
    this->listghost4[39] = -100;
    this->listghost4[40] = -2;
    this->listghost4[41] = -2;
    this->listghost4[42] = -100;
    this->listghost4[43] = -100;
    this->listghost4[44] = 2;
    this->listghost4[45] = 2;
    this->listghost4[46] = -100;
    this->listghost4[47] = -100;
    this->listghost4[48] = -2;
    this->listghost4[49] = -2;
    this->listghost4[50] = -2;
    this->listghost4[51] = -2;
    this->listghost4[52] = -2;
    this->listghost4[53] = -2;
    this->listghost4[54] = -2;
    this->listghost4[55] = -2;
    this->listghost4[56] = -2;

    this->ghost_pos = 0;
    this->ghost_pos2 = 0;
    this->ghost_pos3 = 0;
    this->ghost_pos4 = 0;

    this->reset = 13;
    this->reset2 = 7;
    this->reset3 = 11;
    this->reset4 = 13;

    this->resetmax = 57;
    this->resetmax2 = 50;
    this->resetmax3 = 44;
    this->resetmax4 = 56;

    this->god_mode = 0;
}

pacman::~pacman() {
    ;
}

void pacman::get_pacman_pos(std::string *map)
{
    int len = (*map).length();
    for (int i = 0; i < len; i++) {
        if ((*map)[i] == 'l' || (*map)[i] == 'r' || (*map)[i] == 'd' || (*map)[i] == 'u')
            this->current_pos = i;
        if ((*map)[i] == 'f') {
            this->ghost = i;
            this->base_ghost = i;
        }
        if ((*map)[i] == 'g') {
            this->ghost2 = i;
            this->base_ghost2 = i;
        }
        if ((*map)[i] == 'w') {
            this->ghost3 = i;
            this->base_ghost3 = i;
        }
        if ((*map)[i] == 'm') {
            this->ghost4 = i;
            this->base_ghost4 = i;
        }
    }
}

int pacman::simulate(globalKeys::keys_t key)
{
    this->current_move = key;
    return (this->move_all(key));
}

bool pacman::check_move_ghost(int move, int &ghost, char &chghost, std::string *map)
{
    if ((*map)[ghost + move] == 'x') return (false);
    if ((*map)[ghost + move] == 'o') chghost = 'o';
    if ((*map)[ghost + move] == '0') chghost = '0';
    if ((*map)[ghost + move] == ' ') chghost = ' ';
    if ((*map)[ghost + move] == 'l' || (*map)[ghost + move] == 'r' || (*map)[ghost + move] == 'd' ||  (*map)[this->ghost + move] == 'u')
        this->win = 1;
    return (true);
}

void pacman::move_ghost(int &ghost, char &chghost, char &ghostletter, int list[], int reset, int resetmax, int &ghost_pos, std::string *map)
{
    if (list[ghost_pos] == 2) {
        (*map)[ghost] = chghost;
        if (this->check_move_ghost(2, ghost, chghost, map)) {
            if ((*map)[ghost + 2] == 'v') {
                (*map)[ghost - 44] = ghostletter;
                ghost -= 44;
            } else {
                (*map)[ghost + 2] = ghostletter;
                ghost += 2; 
            }
        }
    }
    if (list[ghost_pos] == 100) { 
        (*map)[ghost] = chghost;
        if (this->check_move_ghost(100, ghost, chghost, map)) {
            (*map)[ghost + 100] = ghostletter;
            ghost += 100;
        }
    }
    if (list[ghost_pos] == -2) {
        (*map)[ghost] = chghost;
        if (this->check_move_ghost(-2, ghost, chghost, map)) {
            if ((*map)[ghost - 2] == 'v') {
                (*map)[ghost + 44] = ghostletter;
                ghost += 44;
            } else {
                (*map)[ghost - 2] = ghostletter;
                ghost -= 2;
            }
        }
    }
    if (list[ghost_pos] == -100) {
        (*map)[ghost] = chghost;
        if (this->check_move_ghost(-100, ghost, chghost, map)) {
            (*map)[ghost - 100] = ghostletter;
            ghost -= 100;
        }
    }
    ghost_pos++;
    if (ghost_pos == resetmax)
        ghost_pos = reset;
}

void pacman::god_mode_on()
{
    this->ghostletter = 'F';
    this->ghostletter2 = 'G';
    this->ghostletter3 = 'W';
    this->ghostletter4 = 'M';
}

void pacman::god_mode_off()
{
    this->ghostletter = 'f';
    this->ghostletter2 = 'g';
    this->ghostletter3 = 'w';
    this->ghostletter4 = 'm';
}

void pacman::reset_ghost(int &ghost, char &chghost, int &ghost_pos, int ghost_base, char ghostl, std::string *map)
{
    ghost = ghost_base;
    chghost = ' ';
    ghost_pos = 0;
    (*map)[ghost_base] = ghostl;
}

bool pacman::check_move(int move, std::string *map)
{
    if ((this->current_pos - move) < 0) return (false);
    if ((*map)[this->current_pos + move] == 'x') return (false);
    if ((*map)[this->current_pos + move] == 'o') this->score += 10;
    if ((*map)[this->current_pos + move] == '0') {
        this->god_mode_on();
        this->god_mode = 1;
    }
    if ((*map)[this->current_pos + move] == 'f' || (*map)[this->current_pos + move] == 'g' || (*map)[this->current_pos + move] == 'w' ||  (*map)[this->current_pos + move] == 'm')
        this->win = 1;
    if ((*map)[this->current_pos + move] == 'F')
        this->reset_ghost(this->ghost, this->chghost, this->ghost_pos, this->base_ghost, 'F', map);
    if ((*map)[this->current_pos + move] == 'G') 
        this->reset_ghost(this->ghost2, this->chghost2, this->ghost_pos2, this->base_ghost2, 'G', map);
    if ((*map)[this->current_pos + move] == 'M') 
        this->reset_ghost(this->ghost3, this->chghost3, this->ghost_pos3, this->base_ghost3, 'M', map);
    if ((*map)[this->current_pos + move] == 'W') 
        this->reset_ghost(this->ghost4, this->chghost4, this->ghost_pos4, this->base_ghost4, 'W', map);
    return (true);
}

void pacman::move_pac(std::string *map)
{
    if (this->current_move == globalKeys::UP) {
        if (this->check_move(-100, map)) {
            (*map)[this->current_pos] = ' ';
            (*map)[this->current_pos - 100] = 'u';
            this->current_pos -= 100;
        }
    }
    if (this->current_move == globalKeys::DOWN) {
        if (this->check_move(100, map)) {
            (*map)[this->current_pos] = ' ';
            (*map)[this->current_pos + 100] = 'd';
            this->current_pos += 100;
        }
    }
    if (this->current_move == globalKeys::LEFT) {
        if (this->check_move(-2, map)) {
            if ((*map)[this->current_pos -2] == 'v') {
                (*map)[this->current_pos] = ' ';
                (*map)[this->current_pos + 44] = 'l';
                this->current_pos += 44;
            } else {
                (*map)[this->current_pos] = ' ';
                (*map)[this->current_pos - 2] = 'l';
                this->current_pos -= 2;
            }
        }
    }
    if (this->current_move == globalKeys::RIGHT) {
        if (this->check_move(2, map)) {
            if ((*map)[this->current_pos + 2] == 'v') {
                (*map)[this->current_pos] = ' ';
                (*map)[this->current_pos - 44] = 'r';
                this->current_pos -= 44;
            } else {
                (*map)[this->current_pos] = ' ';
                (*map)[this->current_pos + 2] = 'r';
                this->current_pos += 2;
            }
        }
    }
}

bool pacman::check_win(std::string *map)
{
    int len = (*map).length();
    for (int i = 0; i < len; i++) {
        if ((*map)[i] == 'o')
            return (false);
    }
    return (true);
}

int pacman::move_all(globalKeys::keys_t key)
{
    std::string *map = this->get_ptrMap();
    static int first_simulate = 0;
    static int speed = 0;
    if (key == globalKeys::UP || key == globalKeys::DOWN || key == globalKeys::LEFT || key == globalKeys::RIGHT)
        this->current_move = key;
    if (speed == 0) {
        if (first_simulate == 0)
            this->get_pacman_pos(map);
        this->move_ghost(this->ghost, this->chghost, this->ghostletter, this->listghost, this->reset, this->resetmax, this->ghost_pos, map);
        if (first_simulate > 10)
            this->move_ghost(this->ghost2, this->chghost2, this->ghostletter2, this->listghost2, this->reset2, this->resetmax2, this->ghost_pos2, map);
        if (first_simulate > 20)
            this->move_ghost(this->ghost3, this->chghost3, this->ghostletter3, this->listghost3, this->reset3, this->resetmax3, this->ghost_pos3, map);
        if (first_simulate > 30)
            this->move_ghost(this->ghost4, this->chghost4, this->ghostletter4, this->listghost4, this->reset4, this->resetmax4, this->ghost_pos4, map);
    }
    if (this->win == 1)
        return (1);
    if (this->god_mode == 1) {
        this->god_mode += 1;
        if (this->god_mode == 35) {
            this->god_mode = 0;
            this->god_mode_off();
        }
    }
    this->move_pac(map);
    if (this->check_win(map))
        return (2);
    speed += 1;
    if (speed == 2)
        speed = 0;
    first_simulate += 1;
    return (-1);
}

std::string pacman::getName() const
{
    return (IGame::getName());
}

std::string *pacman::get_ptrMap()
{
    return (IGame::get_ptrMap());
}

extern "C" std::unique_ptr<IGame> create()
{
    return (std::make_unique<pacman>());
}