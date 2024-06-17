/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-gael.leroy
** File description:
** arcade
*/

#include "arcade.hpp"

arcade::arcade(int const ac, char const **av)
{
    this->_av = av;
    this->_ac = ac;
    this->current_game = 5;
    libmap[1] = NCURSE;
    libmap[2] = SDL;
    libmap[3] = SFML;
    libmap[5] = PACMAN;
    libmap[6] = NIBBLER;
    this->_map = NULL;
    this->state = MENU;
    this->is_win = false;
}

arcade::~arcade() {
    ;
}

void arcade::next_lib_graphic()
{
    dlclose(this->handle_graphic);
    this->current_lib++;
    if (this->current_lib == 4)
     this->current_lib = 1;
    this->set_lib_graphic();
}

void arcade::prev_lib_graphic()
{
    dlclose(this->handle_graphic);
    this->current_lib--;
    if (this->current_lib == 0)
        this->current_lib = 3;
    this->set_lib_graphic();
}

void arcade::set_lib_graphic(int lib)
{
    this->_graphic.~unique_ptr();
    if (lib != -1)
        this->current_lib = lib;
    this->handle_graphic = dlopen(libmap[this->current_lib], RTLD_LAZY);
    if (!this->handle_graphic)
        throw (std::string)"can't open graphical library";
    dlerror();
    this->_create_graphic = (std::unique_ptr<IGraphic>(*)())dlsym(this->handle_graphic, "create");
    if (dlerror())
        throw (std::string)"Error on dlsym.";
    this->_graphic = this->_create_graphic();
}

void arcade::set_lib_game(int lib)
{
    this->_map = NULL;
    this->_game.~unique_ptr();
    if (lib != -1)
        this->current_game = lib;
    this->handle_game = dlopen(libmap[this->current_game], RTLD_LAZY);
    if (!this->handle_game)
        throw (std::string)"can't open game library";
    dlerror();
    this->_create_game = (std::unique_ptr<IGame>(*)())dlsym(this->handle_game, "create");
    if (dlerror())
        throw (std::string)"Error on dlsym.";
    this->_game = this->_create_game();
    this->_map = this->_game->get_ptrMap();
    if (this->current_game == 5)
        this->_graphic->load_pacman();
    else if (this->current_game == 6)
        this->_graphic->load_nibbler();
}

void arcade::next_lib_game()
{
    dlclose(this->handle_game);
    this->current_game++;
    if (this->current_game == 7)
       this->current_game = 5;
    this->set_lib_game();
}

void arcade::prev_lib_game()
{
    dlclose(this->handle_game);
    this->current_game--;
    if (this->current_game == 4)
        this->current_game = 6;
    this->set_lib_game();
}

void arcade::help()
{
    std::cout << "To run the Arcade, write only on the following arguments to choose the grapic lib:" << std::endl;
    std::cout << "./lib/arcade_ncurses.so" << std::endl;
    std::cout << "./lib/arcade_sdl2.so" << std::endl;
    std::cout << "./lib/arcade_sfml.so" << std::endl;
}

void arcade::check_arg()
{
    if (this->_ac != 2) {
        std::cerr << "Run with -h to have more informations" << std::endl;
        this->current_lib = 84;
        return;
    }
    if (strcmp(this->_av[1], "./lib/arcade_ncurses.so") == 0)
        this->current_lib = 1;
    else if (strcmp(this->_av[1], "./lib/arcade_sdl2.so") == 0)
        this->current_lib = 2;
    else if (strcmp(this->_av[1], "./lib/arcade_sfml.so") == 0)
        this->current_lib = 3;
    else if (strcmp(this->_av[1], "-h") == 0 || strcmp(this->_av[1], "--help") == 0) {
        this->help();
        this->current_lib = 0;
    }
    else this->current_lib = 84;
}

int arcade::get_lib()
{
    return (this->current_lib);
}

int arcade::get_game()
{
    return (this->current_game);
}

void arcade::menu()
{
    if (this->state != MENU)
        return;
    this->current_game = this->_graphic->draw_menu();
    if (this->current_game >= 5)
        this->state = GAME;
}

void arcade::save_progress(int score)
{
    std::ofstream fs;
    std::string final = std::to_string(score);
    if (this->current_game == 5)
        fs.open("./lib/Games/pacman/map/save_progress.txt");
    else if (this->current_game == 6)
        fs.open("./lib/Games/nibbler/map/save_progress.txt");
    if (!fs.is_open()) {
        this->state = ERROR;
        return;
    }
    final += "\n";
    final += *this->_map;
    fs << final;
    fs.close();
}

void arcade::game()
{
    struct timeval time_now{};
    time_t save = 0, msecs_time = 0;
    int graphic = -1, game = -1, final = -1, begin = 0;
    globalKeys::keys_t key = globalKeys::NOTHING;
    if (this->state != GAME && this->state != CHANGE)
        return;
    if (this->state == GAME)
        this->set_lib_game(this->current_game);
    gettimeofday(&time_now, nullptr);
    msecs_time = ((time_now.tv_sec * 1000) + (time_now.tv_usec / 1000)) / 100;
    while (final == -1 && graphic == -1 && game == -1 && !(key == globalKeys::RESTART || key == globalKeys::NEXTGAME || key == globalKeys::NEXTGRAPH || key == globalKeys::PREVGAME || key == globalKeys::PREVGRAPH || key == globalKeys::MENU)) {
        do {
            gettimeofday(&time_now, nullptr);
            save = msecs_time;
            msecs_time = ((time_now.tv_sec * 1000) + (time_now.tv_usec / 1000)) / 100;
        } while (msecs_time == save);
        graphic = this->_graphic->draw_game(this->_map, this->_game->get_score());
        key = this->_graphic->getGlobalKey();
        if (key == globalKeys::SAVE)
            this->save_progress(this->_game->get_score());
        if (begin < 20) {
            begin++;
            continue;
        }
        game = this->_game->simulate(key);
    }
    this->state = (graphic == 84 || game == 84) ? ERROR : END;
    if (this->state == END || key == globalKeys::RESTART || key == globalKeys::NEXTGAME || key == globalKeys::NEXTGRAPH || key == globalKeys::PREVGAME || key == globalKeys::PREVGRAPH || this->state == ERROR || key == globalKeys::MENU) {
        if (this->current_game == 5)
            this->_graphic->unload_pacman();
        else if (this->current_game == 6)
            this->_graphic->unload_nibbler();
    }
    if (game == 1 || game == 2) {
        this->state = MEND;
        this->is_win = (game == 1) ? false : true;
        return;
    }
    if (key == globalKeys::MENU) {
        this->_game.~unique_ptr();
        this->state = MENU;
        return;
    }
    if (graphic > 0 || key == globalKeys::RESTART || key == globalKeys::NEXTGAME || key == globalKeys::NEXTGRAPH || key == globalKeys::PREVGAME || key == globalKeys::PREVGRAPH) {
        if (key == globalKeys::NEXTGAME || key == globalKeys::PREVGAME) {
            this->current_game = (this->current_game == 5) ? 6 : 5;
            graphic = this->current_game;
        }
        else if (key == globalKeys::NEXTGRAPH) {
            if (this->current_lib == 3)
                this->current_lib = 1;
            else this->current_lib++;
            graphic = this->current_lib;
        }
        else if (key == globalKeys::PREVGRAPH) {
            if (this->current_lib == 1)
                this->current_lib = 3;
            else this->current_lib--;
            graphic = this->current_lib;
        }
        this->state = CHANGE;
        if (graphic < 5 && graphic > 0) {
            try {
                this->set_lib_graphic(graphic);
            } catch (const std::string &error) {
                std::cerr << error << std::endl;
                this->state = ERROR;
                final = 0;
            }
            if (this->current_game == 5)
                this->_graphic->load_pacman();
            else if (this->current_game == 6)
                this->_graphic->load_nibbler();
        } else {
            try {
                this->set_lib_game(key == globalKeys::RESTART ? this->current_game : graphic);
            } catch (const std::string &error) {
                std::cerr << error << std::endl;
                this->state = ERROR;
                final = 0;
            }
        }
    }
}

int arcade::get_int(const std::string &str)
{
    std::string nbr = "0";
    if (str == "")
        return (0);
    for (unsigned int i = 0; i < str.length(); i++)
        if (str[i] >= '0' && str[i] <= '9')
            nbr += str[i];
    return (std::stoi(nbr));
}

void arcade::menu_end()
{
    if (this->state != MEND)
        return;
    std::string score_name = this->_graphic->draw_end(this->_game->get_score(), this->is_win);
    globalKeys::keys_t key = this->_graphic->getGlobalKey();
    if (this->state == ERROR)
        return;
    if (key == globalKeys::MENU)
        this->state = MENU;
    else if (key == globalKeys::RESTART)
        this->state = GAME;
    else 
        this->state = END;
    std::fstream fs("./lib/Games/high_score.txt");
    if (!fs.is_open())
        return;
    std::string line1, line2, fullscore;
    getline(fs, line1);
    getline(fs, line2);
    fs.close();
    if (this->current_game == 5 && this->get_int(line1) < this->get_int(score_name))
        line1 = "Pacman: " + score_name;
    else if (this->current_game == 6 && this->get_int(line2) < this->get_int(score_name))
        line2 = "Nibbler: " + score_name;
    fullscore = line1 + "\n" + line2;
    fs.open("./lib/Games/high_score.txt");
    fs.write(fullscore.c_str(), fullscore.length());
    fs.close();
}

int arcade::get_state()
{
    return (this->state);
}

void arcade::draw_map()
{
    if (!this->_map)
        return;
    this->_graphic->draw_game(this->_map, this->_game->get_score());
}