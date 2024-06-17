/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-gael.leroy
** File description:
** sfml
*/

#include "../include/sfml.hpp"

sfml::sfml(): IGraphic("sfml") {
    this->_win = NULL;
    this->music = NULL;
    this->key = globalKeys::NOTHING;
}

sfml::~sfml() {
    ;
}

std::string sfml::getName() const
{
    return (IGraphic::getName());
}

void sfml::set_pmpos(std::string *map, sf::Vector2f prevPos)
{
    static int pmopen = 0;
    int height = 0, width = 0;
    height = 25 / 2;
    width = 25 / 2;
    sf::Vector2f savePos = prevPos;
    auto wall = this->pmanSp["wall"].begin();
    auto gum = this->pmanSp["gum"].begin();
    auto supergum = this->pmanSp["supergum"].begin();
    auto pacman = this->pmanSp["pacman"].begin();
    auto fantomes = this->pmanSp["fantomes"].begin();
    sf::IntRect recttmp = (*pacman)->sp.getTextureRect();
    for (int i = 0; i < (int)(*map).length(); i++) {
        if ((*map)[i] == '\n') {
            prevPos.x = savePos.x;
            prevPos.y += height;
        }
        else if ((*map)[i] == 'x') {
            (*wall)->sp.setPosition({prevPos.x, prevPos.y});
            (*wall)->is_free = false;
            wall++;
            prevPos.x += width;
        } else if ((*map)[i] == 'o') {
            (*gum)->sp.setPosition({prevPos.x, prevPos.y});
            (*gum)->is_free = false;
            gum++;
            prevPos.x += width;
        } else if ((*map)[i] == '0') {
            (*supergum)->sp.setPosition({prevPos.x, prevPos.y});
            (*supergum)->is_free = false;
            supergum++;
            prevPos.x += width;
        } else if ((*map)[i] == 'w' || (*map)[i] == 'm' || (*map)[i] == 'f' || (*map)[i] == 'g' || (*map)[i] == 'W' || (*map)[i] == 'M' || (*map)[i] == 'F' || (*map)[i] == 'G') {
            (*fantomes)->sp.setPosition({prevPos.x, prevPos.y});
            sf::IntRect tmprect = (*fantomes)->sp.getTextureRect();
            if ((*map)[i] == 'W' || (*map)[i] == 'M' || (*map)[i] == 'F' || (*map)[i] == 'G')
                tmprect.top = 25;
            else
                tmprect.top = 0;
            (*fantomes)->sp.setTextureRect(tmprect);
            (*fantomes)->is_free = false;
            fantomes++;
            prevPos.x += width;
        } else if ((*map)[i] == 'u' || (*map)[i] == 'd'|| (*map)[i] == 'l'|| (*map)[i] == 'r') {
            (*pacman)->sp.setPosition({prevPos.x, prevPos.y});
            (*pacman)->is_free = false;
            prevPos.x += width;
            if (pmopen < 2) (*pacman)->sp.setTextureRect({0, recttmp.top, recttmp.width, recttmp.height});
            else (*pacman)->sp.setTextureRect({25, recttmp.top, recttmp.width, recttmp.height});
            if ((*map)[i] == 'u') {
                (*pacman)->sp.setRotation(90);
                (*pacman)->sp.move((sf::Vector2f){25, 0});
            }
            else if ((*map)[i] == 'r') {
                (*pacman)->sp.setRotation(180);
                (*pacman)->sp.move((sf::Vector2f){25, 25});
            }
            else if ((*map)[i] == 'd') {
                (*pacman)->sp.setRotation(-90);
                (*pacman)->sp.move((sf::Vector2f){0, 25});
            }
            else if ((*map)[i] == 'l')
                (*pacman)->sp.setRotation(0);
            pacman++;
        } else prevPos.x += width;
    }
    pmopen = pmopen >= 4 ? 0 : pmopen + 1;
}

void sfml::set_nblrpos(std::string *map, sf::Vector2f prevPos)
{
    sf::Vector2f savePos = prevPos;
    int size = 25 / 2;
    auto wall = this->nblrSp["wall"].begin();
    auto body = this->nblrSp["body"].begin();
    auto food = this->nblrSp["food"].begin();
    for (int i = 0; i < (int)(*map).length(); i++) {
        if ((*map)[i] == '\n') {
            prevPos.x = savePos.x;
            prevPos.y += size;
        }
        else if ((*map)[i] == 'x') {
            (*wall)->sp.setPosition(prevPos);
            (*wall)->is_free = false;
            wall++;
            prevPos.x += size;
        }
        else if ((*map)[i] == 'o') {
            (*food)->sp.setPosition(prevPos);
            (*food)->is_free = false;
            food++;
            prevPos.x += size;
        }
        else if ((*map)[i] == 'B') {
            (*body)->sp.setPosition(prevPos);
            (*body)->is_free = false;
            body++;
            prevPos.x += size;
        }
        else if ((*map)[i] == 'r' || (*map)[i] == 'u' || (*map)[i] == 'l' || (*map)[i] == 'd') {
            this->nblrSp["head"].front()->sp.setPosition(prevPos);
            this->nblrSp["head"].front()->is_free = false;
            if ((*map)[i] == 'r') {
                this->nblrSp["head"].front()->sp.setRotation(90);
                this->nblrSp["head"].front()->sp.move({25, 0});
            } else if ((*map)[i] == 'd') {
                this->nblrSp["head"].front()->sp.setRotation(180);
                this->nblrSp["head"].front()->sp.move({25, 25});
            } else if ((*map)[i] == 'l') {
                this->nblrSp["head"].front()->sp.setRotation(270);
                this->nblrSp["head"].front()->sp.move({0, 25});
            } else this->nblrSp["head"].front()->sp.setRotation(0);
            this->dir = (*map)[i];
            prevPos.x += size;
        } else prevPos.x += size;
    }
}

int sfml::draw_game(std::string *map, int score)
{
    static sf::Vector2f prevPos = {0, 0};
    int i = 0, x = 0, y = 0;
    if (map == NULL || (*map) == "ERROR")
        return (84);
    if (!this->_win) {
        this->_win = new sf::RenderWindow((sf::VideoMode){1920, 1080, 32}, this->pmanSp.empty() ? "Sfml - Nibbler" : "Sfml - Pacman", sf::Style::Fullscreen);
        this->_win->setFramerateLimit(60);
        for (i = 0, x = 0, y = 0; i < (int)(*map).length(); i++) {
            if ((*map)[i] == '\n')
                y += 1;
            else if (y == 0)
                x += 1;
        }
        prevPos = {(float)this->_win->getSize().x / 2 - (x * (25 / 2)) / 2, (float)this->_win->getSize().y / 2 - (y * (25 / 2)) / 2};
        if (this->music)
            this->music->play();
        this->scoreT->setPosition({prevPos.x, prevPos.y - 50});
    }
    this->scoreT->setString("Score: " + std::to_string(score));
    if (!this->pmanSp.empty())
        this->set_pmpos(map, prevPos);
    else
        this->set_nblrpos(map, prevPos);
    this->key = globalKeys::NOTHING;
    while (this->_win->pollEvent(this->evt)) {
        if (evt.type == sf::Event::KeyPressed) {
            if (evt.key.code == sf::Keyboard::Space)
                return (0);
            if (evt.key.code == sf::Keyboard::Left)
                this->key = globalKeys::LEFT;
            else if (evt.key.code == sf::Keyboard::Right)
                this->key = globalKeys::RIGHT;
            else if (evt.key.code == sf::Keyboard::Up)
                this->key = globalKeys::UP;
            else if (evt.key.code == sf::Keyboard::Down)
                this->key = globalKeys::DOWN;
            else if (evt.key.code == sf::Keyboard::P)
                this->key = globalKeys::PREVGRAPH;
            else if (evt.key.code == sf::Keyboard::N)
                this->key = globalKeys::NEXTGRAPH;
            else if (evt.key.code == sf::Keyboard::L)
                this->key = globalKeys::PREVGAME;
            else if (evt.key.code == sf::Keyboard::O)
                this->key = globalKeys::NEXTGAME;
            else if (evt.key.code == sf::Keyboard::R)
                this->key = globalKeys::RESTART;
            else if (evt.key.code == sf::Keyboard::M)
                this->key = globalKeys::MENU;
            else if (evt.key.code == sf::Keyboard::S)
                this->key = globalKeys::SAVE;
        }
    }
    this->_win->clear();
    for (auto &i : pmanSp)
        for (auto &j : i.second)
            if (j->is_free == false)
                this->_win->draw(j->sp);
    for (auto &i : nblrSp)
        for (auto &j : i.second)
            if (j->is_free == false)
                this->_win->draw(j->sp);
    this->_win->draw(*(this->scoreT));
    this->_win->display();
    return (-1);
}

static bool is_in_rect(sf::RenderWindow &win, sf::RectangleShape &act)
{
    sf::Vector2i mpos = sf::Mouse::getPosition(win);
    sf::FloatRect gbounds = act.getGlobalBounds();
    if (mpos.x >= gbounds.left && mpos.x <= gbounds.left + gbounds.width
     && mpos.y >= gbounds.top && mpos.y <= gbounds.top + gbounds.height)
        return (true);
    return (false);
}

static void draw_in_rect(sf::RenderWindow &win, sf::RectangleShape &rect)
{
    if (is_in_rect(win, rect))
        rect.setOutlineColor(sf::Color(255, 215, 0));
    else if (rect.getOutlineColor() != sf::Color(220,20,60))
        rect.setOutlineColor(sf::Color(220,20,60));
}

static void set_assets(std::list<sf::RectangleShape> &rects)
{
    sf::RectangleShape playr((sf::Vector2f){84, 30});
    playr.setOutlineColor(sf::Color(220,20,60));
    playr.setOutlineThickness(2);
    playr.setFillColor(sf::Color(0, 0, 0, 0));
    sf::RectangleShape quitr(playr), pacmanr(playr), nibblerr(playr), stdl2r(playr), ncursesr(playr), hgscr(playr);
    playr.setPosition((sf::Vector2f){347, 437});
    quitr.setPosition((sf::Vector2f){347, 476});
    pacmanr.setSize((sf::Vector2f){123, 30});
    pacmanr.setPosition((sf::Vector2f){148, 97});
    nibblerr.setSize((sf::Vector2f){143, 30});
    nibblerr.setPosition((sf::Vector2f){148, 137});
    stdl2r.setSize((sf::Vector2f){85, 30});
    stdl2r.setPosition((sf::Vector2f){448, 97});
    ncursesr.setSize((sf::Vector2f){143, 30});
    ncursesr.setPosition((sf::Vector2f){448, 177});
    hgscr.setPosition((sf::Vector2f){147, 297});
    hgscr.setOutlineColor(sf::Color(0, 0, 128));
    rects.emplace_back(playr);
    rects.emplace_back(quitr);
    rects.emplace_back(pacmanr);
    rects.emplace_back(nibblerr);
    rects.emplace_back(stdl2r);
    rects.emplace_back(ncursesr);
    rects.emplace_back(hgscr);
}

int sfml::draw_menu()
{
    sf::RenderWindow win(sf::VideoMode(800, 600), "Sfml - Arcade");
    sf::Event evt;
    sf::Music theme;
    std::list<sf::RectangleShape> rects;
    sf::Font font;
    std::string line, hgscore = "\n";
    std::ifstream fs("lib/Games/high_score.txt");
    sf::Texture tu;
    sf::Sprite sp;
    int game_chosed = 0, graphic_chosed = 0, have_to_return = -1;
    theme.openFromFile("lib/Graphic/musics/menu.ogg");
    theme.setLoop(true);
    tu.loadFromFile("lib/Graphic/sfml/assets/menu/bg.png");
    sp.setTexture(tu);
    sp.setScale(win.getSize().x / sp.getGlobalBounds().width, win.getSize().y / sp.getGlobalBounds().height);
    if (fs.is_open()) {
        getline(fs, line);
        hgscore += line + "\n\n";
        getline(fs, line);
        hgscore += line;
        fs.close();
    }
    font.loadFromFile("lib/Graphic/sfml/assets/menu/ARCADE_I.TTF");
    sf::Text playt("Play", font, 20), quitt("Quit", font, 20), pacmant("pacman", font, 20), nibblert("nibbler", font, 20), stdl2t("sdl2", font, 20), ncursest("ncurses", font, 20), sfmlt("actual: sfml", font, 20), hgsst("Highscores:", font, 20), hgst("Play", font, 15);
    playt.setPosition((sf::Vector2f){350, 440});
    quitt.setPosition((sf::Vector2f){350, 480});
    pacmant.setPosition((sf::Vector2f){150, 100});
    nibblert.setPosition((sf::Vector2f){150, 140});
    stdl2t.setPosition((sf::Vector2f){450, 100});
    sfmlt.setPosition((sf::Vector2f){450, 140});
    ncursest.setPosition((sf::Vector2f){450, 180});
    hgsst.setPosition((sf::Vector2f){150, 300});
    hgst.setPosition((sf::Vector2f){150, 340});
    hgst.setString(hgscore);
    set_assets(rects);
    for (auto &&i : rects)
        if (i.getPosition() == (sf::Vector2f){147, 297})
            i.setSize((sf::Vector2f){6 + (hgst.getGlobalBounds().width > hgsst.getGlobalBounds().width ? hgst.getGlobalBounds().width : hgsst.getGlobalBounds().width), hgst.getGlobalBounds().height + hgsst.getGlobalBounds().height + 46});
    win.setPosition((sf::Vector2i){100, 100});
    theme.play();
    while (!graphic_chosed && have_to_return == -1) {
        win.clear(sf::Color::Black);
        while (win.pollEvent(evt)) {
            if (evt.type == sf::Event::Closed)
                have_to_return = 0;
            if (evt.type == sf::Event::MouseMoved) {
                for (auto &&i : rects) {
                    if (i.getPosition() == (sf::Vector2f){147, 297})
                        continue;
                    draw_in_rect(win, i);
                }
            }
            if (evt.type == sf::Event::MouseButtonPressed) {
                for (auto &&i : rects) {
                    if (is_in_rect(win, i)) {
                        if (i.getPosition() == (sf::Vector2f){347, 476})
                            have_to_return = 0;
                        else if (i.getPosition() == (sf::Vector2f){347, 437} && game_chosed)
                            have_to_return = game_chosed;
                        if (i.getPosition().x == 148) {
                            if (i.getPosition().y == 97)
                                game_chosed = (game_chosed == 5) ? 0 : 5;
                            else
                                game_chosed = (game_chosed == 6) ? 0 : 6;
                        }
                        else if (i.getPosition().x == 448) {
                            if (i.getPosition().y == 97)
                                graphic_chosed = 2;
                            else
                                graphic_chosed = 1;
                        }
                    }
                }
            }
        }
        win.draw(sp);
        for (auto iter = rects.begin(); iter != rects.end(); iter++) {
            if ((*iter).getPosition() == (sf::Vector2f){347, 437} && !game_chosed)
                continue;
            if ((*iter).getOutlineColor() == sf::Color(255, 215, 0) || (*iter).getPosition() == (sf::Vector2f){147, 297})
                win.draw(*iter);
        }
        if (game_chosed) {
            win.draw(playt);
            for (auto &&i : rects) {
                if (game_chosed == 5 && i.getPosition() == (sf::Vector2f){148, 97})
                    win.draw(i);
                else if (game_chosed == 6 && i.getPosition() == (sf::Vector2f){148, 137})
                    win.draw(i);
            }
        }
        win.draw(quitt);
        win.draw(pacmant);
        win.draw(nibblert);
        win.draw(stdl2t);
        win.draw(sfmlt);
        win.draw(ncursest);
        win.draw(hgsst);
        win.draw(hgst);
        win.display();
    }
    theme.stop();
    if (have_to_return != -1)
        return (have_to_return);
    if (graphic_chosed)
        return (graphic_chosed);
    return (game_chosed);
}

void sfml::load_pacman()
{
    sf::IntRect frect = (sf::IntRect){0, 0, 25, 25};
    this->pmanSp["pacman"].emplace_back(new sfml::sprites("./lib/Graphic/sfml/assets/pacman/pman.png"));
    this->pmanSp["pacman"].back()->sp.setTextureRect((sf::IntRect){0, 0, 25, 25});
    for (int i = 0; i < 4; i++) {
        this->pmanSp["fantomes"].emplace_back(new sfml::sprites("./lib/Graphic/sfml/assets/pacman/fantomes.png"));
        this->pmanSp["fantomes"].back()->sp.setTextureRect(frect);
        frect.left += 25;
        this->pmanSp["supergum"].emplace_back(new sfml::sprites("./lib/Graphic/sfml/assets/pacman/super_gum.png"));
    }
    for (int i = 0; i < 364; i++)
        this->pmanSp["wall"].emplace_back(new sfml::sprites("./lib/Graphic/sfml/assets/pacman/wall.png"));
    for (int i = 0; i < 226; i++)
        this->pmanSp["gum"].emplace_back(new sfml::sprites("./lib/Graphic/sfml/assets/pacman/gum.png"));
    this->music = new sf::Music;
    this->music->openFromFile("./lib/Graphic/musics/pacman.ogg");
    this->music->setLoop(true);
    this->font = new sf::Font;
    this->font->loadFromFile("./lib/Graphic/sfml/assets/menu/ARCADE_I.TTF");
    this->scoreT = new sf::Text("Score: 0", *(this->font), 15);
}

void sfml::unload_pacman()
{
    for (auto &i : this->pmanSp) {
        while (!i.second.empty()) {
            delete i.second.front();
            i.second.pop_front();
        }
    }
    if (this->music) {
        this->music->stop();
        delete this->music;
        this->music = NULL;
    }
    if (this->_win)
        delete this->_win;
    this->_win = NULL;
    delete this->scoreT;
    delete this->font;
    this->pmanSp.clear();
}

void sfml::load_nibbler()
{
    for (int i = 0; i < 189; i++)
        this->nblrSp["wall"].emplace_back(new sfml::sprites("./lib/Graphic/sfml/assets/nibbler/wall.png"));
    for (int i = 0; i < 171; i++)
        this->nblrSp["body"].emplace_back(new sfml::sprites("./lib/Graphic/sfml/assets/nibbler/body.png"));
    this->nblrSp["head"].emplace_back(new sfml::sprites("./lib/Graphic/sfml/assets/nibbler/head.png"));
    for (int i = 0; i < 10; i++)
        this->nblrSp["food"].emplace_back(new sfml::sprites("./lib/Graphic/sfml/assets/nibbler/food.png"));
    this->music = new sf::Music;
    this->music->openFromFile("./lib/Graphic/musics/nibbler.ogg");
    this->music->setLoop(true);
    this->font = new sf::Font;
    this->font->loadFromFile("./lib/Graphic/sfml/assets/menu/ARCADE_I.TTF");
    this->scoreT = new sf::Text("Score: 0", *(this->font), 15);
}

void sfml::unload_nibbler()
{
    for (auto &i : this->nblrSp) {
        while (!i.second.empty()) {
            delete i.second.front();
            i.second.pop_front();
        }
    }
    if (this->music) {
        this->music->stop();
        delete this->music;
        this->music = NULL;
    }
    if (this->_win)
        delete this->_win;
    this->_win = NULL;
    delete this->scoreT;
    delete this->font;
    this->nblrSp.clear();
}

globalKeys::keys_t sfml::getGlobalKey()
{
    return (this->key);
}

std::string sfml::draw_end(int score, bool is_win)
{
    sf::RenderWindow win(sf::VideoMode(800, 600), "Sfml - Arcade");
    sf::Event evnt;
    std::string win_loose = (is_win) ? "That's a win !" : "That's a shame..";
    std::string name_score = "";
    sf::Font fnt;
    sf::Music theme;
    theme.openFromFile("lib/Graphic/musics/menu.ogg");
    theme.setLoop(true);
    fnt.loadFromFile("./lib/Graphic/sfml/assets/menu/ARCADE_I.TTF");
    sf::Text state(win_loose, fnt, 30), ask("Please type your name:", fnt, 15), name("", fnt, 15), restart("Restart", fnt, 15), quit("Quit", fnt, 15), goMenu("Back to menu", fnt, 15);
    state.setPosition({win.getSize().x / 2 - state.getGlobalBounds().width / 2, 10});
    ask.setPosition({win.getSize().x / 2 - ask.getGlobalBounds().width / 2, 30});
    ask.move({0, state.getGlobalBounds().height + 10});
    name.setPosition(ask.getPosition());
    name.move(0, ask.getGlobalBounds().height + 10);
    quit.setPosition(win.getSize().x / 2 - quit.getGlobalBounds().width / 2, win.getSize().y - quit.getGlobalBounds().height * 3);
    goMenu.setPosition({win.getSize().x / 2 - goMenu.getGlobalBounds().width / 2, quit.getPosition().y - (goMenu.getGlobalBounds().height + 25)});
    restart.setPosition({win.getSize().x / 2 - restart.getGlobalBounds().width / 2, goMenu.getPosition().y - (restart.getGlobalBounds().height + 25)});
    win.setPosition({100, 100});
    while (win.isOpen()) {
        while (win.pollEvent(evnt)) {
            if (evnt.type == sf::Event::Closed)
                win.close();
            else if (evnt.type == sf::Event::MouseMoved) {
                if (quit.getGlobalBounds().contains(win.mapPixelToCoords(sf::Mouse::getPosition(win))))
                    quit.setColor(sf::Color::Red);
                else
                    quit.setColor(sf::Color::White);
                if (goMenu.getGlobalBounds().contains(win.mapPixelToCoords(sf::Mouse::getPosition(win))))
                    goMenu.setColor(sf::Color::Red);
                else
                    goMenu.setColor(sf::Color::White);
                if (restart.getGlobalBounds().contains(win.mapPixelToCoords(sf::Mouse::getPosition(win))))
                    restart.setColor(sf::Color::Red);
                else
                    restart.setColor(sf::Color::White);
            }
            else if (evnt.type == sf::Event::MouseButtonPressed) {
                if (quit.getGlobalBounds().contains(win.mapPixelToCoords(sf::Mouse::getPosition(win))))
                    win.close();
                else if (goMenu.getGlobalBounds().contains(win.mapPixelToCoords(sf::Mouse::getPosition(win)))) {
                    this->key = globalKeys::MENU;
                    win.close();
                }
                else if (restart.getGlobalBounds().contains(win.mapPixelToCoords(sf::Mouse::getPosition(win)))) {
                    this->key = globalKeys::RESTART;
                    win.close();
                }
            }
            else if (evnt.type == sf::Event::KeyReleased) {
                switch (evnt.key.code) {
                    case sf::Keyboard::A:
                        name_score += "A";
                        break;
                    case sf::Keyboard::B:
                        name_score += "B";
                        break;
                    case sf::Keyboard::C:
                        name_score += "C";
                        break;
                    case sf::Keyboard::D:
                        name_score += "D";
                        break;
                    case sf::Keyboard::E:
                        name_score += "E";
                        break;
                    case sf::Keyboard::F:
                        name_score += "F";
                        break;
                    case sf::Keyboard::G:
                        name_score += "G";
                        break;
                    case sf::Keyboard::H:
                        name_score += "H";
                        break;
                    case sf::Keyboard::I:
                        name_score += "I";
                        break;
                    case sf::Keyboard::J:
                        name_score += "J";
                        break;
                    case sf::Keyboard::K:
                        name_score += "K";
                        break;
                    case sf::Keyboard::L:
                        name_score += "L";
                        break;
                    case sf::Keyboard::M:
                        name_score += "M";
                        break;
                    case sf::Keyboard::N:
                        name_score += "N";
                        break;
                    case sf::Keyboard::O:
                        name_score += "O";
                        break;
                    case sf::Keyboard::P:
                        name_score += "P";
                        break;
                    case sf::Keyboard::Q:
                        name_score += "Q";
                        break;
                    case sf::Keyboard::R:
                        name_score += "R";
                        break;
                    case sf::Keyboard::S:
                        name_score += "S";
                        break;
                    case sf::Keyboard::T:
                        name_score += "T";
                        break;
                    case sf::Keyboard::U:
                        name_score += "U";
                        break;
                    case sf::Keyboard::V:
                        name_score += "V";
                        break;
                    case sf::Keyboard::W:
                        name_score += "W";
                        break;
                    case sf::Keyboard::X:
                        name_score += "X";
                        break;
                    case sf::Keyboard::Y:
                        name_score += "Y";
                        break;
                    case sf::Keyboard::Z:
                        name_score += "Z";
                        break;
                    case sf::Keyboard::BackSpace:
                        if (!name_score.empty())
                            name_score.pop_back();
                        break;
                    default:
                        break;
                }
                if (name_score.length() > 7)
                    name_score.pop_back();
                if (name_score != name.getString()) {
                    name.setString(name_score);
                    name.setPosition({win.getSize().x / 2 - name.getGlobalBounds().width / 2, name.getPosition().y});
                }
            }
        }
        win.clear(sf::Color::Black);
        win.draw(state);
        win.draw(ask);
        win.draw(name);
        win.draw(restart);
        win.draw(goMenu);
        win.draw(quit);
        win.display();
    }
    theme.stop();
    name_score += " - " + std::to_string(score);
    return (name_score);
}

extern "C" std::unique_ptr<IGraphic> create()
{
    return std::make_unique<sfml>();
}