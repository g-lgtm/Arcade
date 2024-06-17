/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-raphael.zeitoun
** File description:
** ncurse
*/

#include "../include/ncurse.hpp"

ncurse::ncurse(): IGraphic("ncurse") {
    ;
}

ncurse::~ncurse() {
    ;
}

std::string ncurse::getName() const
{
    return (IGraphic::getName());
}

globalKeys::keys_t ncurse::getGlobalKey()
{
    if (this->key == KEY_UP)
        return (globalKeys::UP);
    if (this->key == KEY_DOWN)
        return (globalKeys::DOWN);
    if (this->key == KEY_LEFT)
        return (globalKeys::LEFT);
    if (this->key == KEY_RIGHT)
        return (globalKeys::RIGHT);
    if (this->key == KEY_RIGHT)
        return (globalKeys::RIGHT);
    if (this->key == 32)
        return (globalKeys::EXIT);
    if (this->key == 112)
        return (globalKeys::PREVGRAPH);
    if (this->key == 110)
        return (globalKeys::NEXTGRAPH);
    if (this->key == 111)
        return (globalKeys::NEXTGAME);
    if (this->key == 108)
        return (globalKeys::PREVGAME);
    if (this->key == 114)
        return (globalKeys::RESTART);
    if (this->key == 115)
        return (globalKeys::SAVE);
    if (this->key == globalKeys::MENU || this->key == globalKeys::RESTART)
        return ((globalKeys::keys_t)this->key);
    return (globalKeys::NOTHING);
}

int ncurse::draw_game(std::string *map, int score)
{
    if (map == NULL) return (84);
    static int ncurse_ini = 0;
    int len = (*map).length();
    int x = -13, y = -13, i = 0;
    if (ncurse_ini == 0) {
        if (!this->ncurse_initialiser()) return (84);
        nodelay(stdscr, true);
        ncurse_ini = 1;
    }
    this->ncurse_colors();
    clear();
    if (!this->check_size_terminal()) return (84);
    attron(COLOR_PAIR(6));
    mvprintw(LINES / 2 - 15, COLS / 2 - 15, "SCORE: %d", score);
    attroff(COLOR_PAIR(6));
    while (i < len) {
        if ((*map)[i] == 'x') {
            attron(COLOR_PAIR(5));
            mvprintw(LINES / 2 + y, COLS / 2 + x, "x");
            attroff(COLOR_PAIR(5));
        }
        else if ((*map)[i] == '0') {
            attron(COLOR_PAIR(6));
            mvprintw(LINES / 2 + y, COLS / 2 + x, "0");
            attroff(COLOR_PAIR(6));
        }
        else if ((*map)[i] == 'o') {
            attron(COLOR_PAIR(1));
            mvprintw(LINES / 2 + y, COLS / 2 + x, "o");
            attroff(COLOR_PAIR(1));
        }
        else if ((*map)[i] == 'f' || (*map)[i] == 'm' || (*map)[i] == 'w' || (*map)[i] == 'g') {
            attron(COLOR_PAIR(3));
            mvprintw(LINES / 2 + y, COLS / 2 + x, "f");
            attroff(COLOR_PAIR(3));
        }
        else if ((*map)[i] == 'F' || (*map)[i] == 'M' || (*map)[i] == 'W' || (*map)[i] == 'G') {
            attron(COLOR_PAIR(4));
            mvprintw(LINES / 2 + y, COLS / 2 + x, "F");
            attroff(COLOR_PAIR(4));
        }
        else if ((*map)[i] == ' ') {
            attron(COLOR_PAIR(7));
            mvprintw(LINES / 2 + y, COLS / 2 + x, " ");
            attroff(COLOR_PAIR(7));
        }
        else if ((*map)[i] == 'r') {
            attron(COLOR_PAIR(1));
            mvprintw(LINES / 2 + y, COLS / 2 + x, "C");
            attroff(COLOR_PAIR(1));
        }
        else if ((*map)[i] == 'u') {
            attron(COLOR_PAIR(1));
            mvprintw(LINES / 2 + y, COLS / 2 + x, "U");
            attroff(COLOR_PAIR(1));
        }
        else if ((*map)[i] == 'l') {
            attron(COLOR_PAIR(1));
            mvprintw(LINES / 2 + y, COLS / 2 + x, "D");
            attroff(COLOR_PAIR(1));
        }
        else if ((*map)[i] == 'd') {
            attron(COLOR_PAIR(1));
            mvprintw(LINES / 2 + y, COLS / 2 + x, "n");
            attroff(COLOR_PAIR(1));
        }
        else if ((*map)[i] == 'B') {
            attron(COLOR_PAIR(3));
            mvprintw(LINES / 2 + y, COLS / 2 + x, "B");
            attroff(COLOR_PAIR(3));
        }
        x++;
        i++;
        if ((*map)[i] == '\n') {
            y++;
            i+=51;
            x = -13;
        } else 
            i++;
    }
    this->key = getch();
    refresh();
    return (-1);
}

void ncurse::unload_pacman()
{
    this->ncurse_stopper();
}

void ncurse::unload_nibbler()
{
    this->ncurse_stopper();
}

void ncurse::print_graphic() const
{
    attron(COLOR_PAIR(4));
    mvprintw(LINES / 2 - 8, COLS / 2 + 3, "Select graphical library");
    mvprintw(LINES / 2 - 7, COLS / 2 + 3, "*******************************");
    mvprintw(LINES / 2 - 6, COLS / 2 + 3, "*  Current: Ncurse            *");
    mvprintw(LINES / 2 - 5, COLS / 2 + 3, "*  Sfml                       *");
    mvprintw(LINES / 2 - 4, COLS / 2 + 3, "*  SDL2                       *");
    mvprintw(LINES / 2 - 3, COLS / 2 + 3, "*******************************");
    attroff(COLOR_PAIR(4));
}

void ncurse::print_games() const
{
    attron(COLOR_PAIR(4));
    mvprintw(LINES / 2 - 8, COLS / 2 - 35, "Select a game");
    mvprintw(LINES / 2 - 7, COLS / 2 - 35, "*******************************");
    mvprintw(LINES / 2 - 6, COLS / 2 - 35, "*  Pacman                     *");
    mvprintw(LINES / 2 - 5, COLS / 2 - 35, "*  Nibblers                   *");
    mvprintw(LINES / 2 - 4, COLS / 2 - 35, "*******************************");
    attroff(COLOR_PAIR(4));
}

void ncurse::print_highscore()
{
    attron(COLOR_PAIR(4));
    mvprintw(LINES / 2 + 4, COLS / 2 - 35, "Hightscore");
    mvprintw(LINES / 2 + 5, COLS / 2 - 35, "*******************************");
    mvprintw(LINES / 2 + 6, COLS / 2 - 35, "*                             *");
    mvprintw(LINES / 2 + 7, COLS / 2 - 35, "*                             *");
    mvprintw(LINES / 2 + 8, COLS / 2 - 35, "*******************************");
    mvprintw(LINES / 2 + 6, COLS / 2 - 33, this->hightscorepacman.data());
    mvprintw(LINES / 2 + 7, COLS / 2 - 33, this->hightscorenibblers.data());
    attroff(COLOR_PAIR(4));
}

void ncurse::print_quit() const
{
    attron(COLOR_PAIR(4));
    mvprintw(LINES / 2 + 4, COLS / 2 + 3, "Quit the game");
    mvprintw(LINES / 2 + 5, COLS / 2 + 3, "*******************************");
    mvprintw(LINES / 2 + 6, COLS / 2 + 3, "*  Quit                       *");
    mvprintw(LINES / 2 + 7, COLS / 2 + 3, "*******************************");
    attroff(COLOR_PAIR(4));
}

void ncurse::print_draw() const
{
    attron(COLOR_PAIR(1));
    mvprintw(LINES / 2 - 2, COLS / 2 - 15, "####");
    mvprintw(LINES / 2 - 1, COLS / 2 - 17, "######");
    mvprintw(LINES / 2, COLS / 2 - 17, "####");
    mvprintw(LINES / 2 + 1, COLS / 2 - 17, "######");
    mvprintw(LINES / 2 + 2, COLS / 2 - 16, "####");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(3));
    mvprintw(LINES / 2 - 1, COLS / 2 + 11, "############");
    mvprintw(LINES / 2, COLS / 2 + 11, "#");
    mvprintw(LINES / 2 + 1, COLS / 2 + 11, "#       ###:>");
    mvprintw(LINES / 2 + 2, COLS / 2 + 11, "#########");
    attroff(COLOR_PAIR(3));
}

bool ncurse::check_size_terminal()
{
    int key;
    if (COLS < 82 || LINES < 24) {
        mvprintw(LINES / 2 - 1, COLS / 2 - 10, "Terminal too small."); 
        mvprintw(LINES / 2, COLS / 2 - 19,  "Increase the size to display the game");
        mvprintw(LINES / 2 + 1, COLS / 2 - 10,  "Press Space to quit");        
        while (COLS < 82 && LINES < 24) {
            key = getch();
            if (key == 32) {
                this->ncurse_stopper();
                std::cerr << "terminal too small, need atleast 82 cols and 24 lignes" << std::endl;
                return (false);
            }
        }
    }
    return (true);
}

bool ncurse::ncurse_initialiser()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    return (this->check_size_terminal());
}

void ncurse::ncurse_stopper() const
{
    endwin();
}

void ncurse::ncurse_colors() const
{
    if(has_colors() == FALSE)
        return;
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_WHITE);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLUE);
    init_pair(6, COLOR_RED, COLOR_BLACK);
    init_pair(7, COLOR_BLACK, COLOR_BLACK);
}

void ncurse::set_pos_cursor()
{
    this->xcursor[0] = COLS / 2 - 34;
    this->ycursor[0] = LINES / 2 - 6;
    this->xcursor[1] = COLS / 2 - 34;
    this->ycursor[1] = LINES / 2 - 5;
    this->xcursor[2] = COLS / 2 + 4;
    this->ycursor[2] = LINES / 2 - 5;
    this->xcursor[3] = COLS / 2 + 4;
    this->ycursor[3] = LINES / 2 - 4;
    this->xcursor[4] = COLS / 2 + 4;
    this->ycursor[4] = LINES / 2 + 6;
}

bool ncurse::get_hightscore()
{
    std::ifstream fs("lib/Games/high_score.txt");
    if (!fs.is_open()) return (false);
    getline(fs, hightscorepacman);
    getline(fs, hightscorenibblers);
    fs.close();
    return (true);
}

void ncurse::print_all_menu()
{
    this->print_games();
    this->print_graphic();
    this->print_highscore();
    this->print_quit();
    this->print_draw();
}

int ncurse::event_key(int &pos, int &result, int &key) const
{
    if (key == 113) {
        return (1);
    }
    if (key == KEY_DOWN) {
        pos += 1;
        if (pos == 5)
            pos = 0;
    }
    if (key == KEY_UP){
        pos -= 1;
        if (pos == -1)
            pos = 4;
    }
    if (key == KEY_RIGHT) {
        if (pos < 2) 
            pos += 2;
    }
    if (key == KEY_LEFT) {
        if (pos > 1) 
            pos -= 2;
    }
    if (key == 32) {
        if (pos == 0) result = 5;
        if (pos == 1) result = 6;
        if (pos == 2) result = 3;
        if (pos == 3) result = 2;
        if (pos == 4) result = 0;
        return (1);
    }
    return (0);
}

void ncurse::ncurse_ini_end()
{
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
}

std::string ncurse::draw_end(int scrore, bool is_win)
{
    int key = 0, rank = 0;
    std::string win = is_win ? "YOU WIN" : "YOU LOSE", ask = "Type your name:", name = "", restart = "Restart", quit = "Quit", menu = "Back to menu";
    int x[] = {COLS / 2 - (int)restart.length() / 2 - 2, COLS / 2 - (int)menu.length() / 2 - 2, COLS / 2 - (int)quit.length() / 2 - 2};
    int y[] = {LINES / 2 + 3, LINES / 2 + 5, LINES / 2 + 7};
    this->ncurse_ini_end();
    while (42) {
        clear();
        mvprintw(LINES / 2 - 10, COLS / 2 - win.length() / 2, win.data());
        mvprintw(LINES / 2 - 5, COLS / 2 - ask.length() / 2, ask.data());
        mvprintw(LINES / 2 - 3, COLS / 2 - name.length() / 2, name.data());
        mvprintw(LINES / 2 + 3, COLS / 2 - restart.length() / 2, restart.data());
        mvprintw(LINES / 2 + 5, COLS / 2 - menu.length() / 2, menu.data());
        mvprintw(LINES / 2 + 7, COLS / 2 - quit.length() / 2, quit.data());
        mvprintw(y[rank], x[rank], "->");
        refresh();
        key = getch();
        if (key >= 'a' && key <= 'z') {
            if (name.length() < 7)
                name += key - 32;
        }
        else if (key == 127) {
            if (!name.empty())
                name.pop_back();
        }
        else if (key == KEY_DOWN)
            rank = (rank == 2) ? 0 : rank + 1;
        else if (key == KEY_UP)
            rank = (rank == 0) ? 2 : rank - 1;
        else if (key == 32)
            break;
    }
    if (rank == 0)
        this->key = globalKeys::RESTART;
    else if (rank == 1)
        this->key = globalKeys::MENU;
    this->ncurse_stopper();
    name += " - " + std::to_string(scrore);
    return (name);
}

int ncurse::draw_menu()
{
    int pos = 0, result = 0, key;
    if (!this->ncurse_initialiser()) return (84);
    this->ncurse_colors();
    if (!this->get_hightscore()) return (84);
    while (1) {
        clear();
        if (!this->check_size_terminal()) return (84);
        this->set_pos_cursor();
        this->print_all_menu();
        attron(COLOR_PAIR(2));
        mvprintw(ycursor[pos], xcursor[pos], "->");
        attroff(COLOR_PAIR(2));
        refresh();
        key = getch();
        if (this->event_key(pos, result, key) == 1) break; 
    }
    this->ncurse_stopper();
    return (result);
}

extern "C" std::unique_ptr<IGraphic> create()
{
    return std::make_unique<ncurse>();
}