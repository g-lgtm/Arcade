/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-gael.leroy
** File description:
** sdl2
*/

#include "../include/sdl2.hpp"

sdl2::sdl2(): IGraphic("sdl2") {
    this->key = globalKeys::NOTHING;
}

sdl2::~sdl2() {
    ;
}

std::string sdl2::getName() const
{
    return (IGraphic::getName());
}

void sdl2::set_pmpos(std::string *map)
{
    static int pmopen = 0;
    int height = 25 / 2, width = 25 / 2;
    auto wall = this->pmanSp["wall"].begin();
    auto gum = this->pmanSp["gum"].begin();
    auto supergum = this->pmanSp["supergum"].begin();
    auto pacman = this->pmanSp["pacman"].begin();
    auto fantomes = this->pmanSp["fantomes"].begin();
    if (this->rect.w == -1) {
        int x = 0, y = 0;
        for (int i = 0; i < (int)(*map).length(); i++) {
            if ((*map)[i] == '\n') y++;
            else if (y == 0) x++;
        }
        this->rect = {this->rect.x - (x * (25 / 2)) / 2, this->rect.y - (y * (25 / 2)) / 2, 0, 0};
        this->rectT.x = this->rect.x;
        this->rectT.y -= this->rect.y - 50;
    }
    SDL_Rect savePos = this->rect, tmp = (*fantomes)->rect;
    for (int i = 0; i < (int)(*map).length(); i++) {
        if ((*map)[i] == '\n') {
            this->rect.x = savePos.x;
            this->rect.y += height;
        }
        else if ((*map)[i] == 'x') {
            (*wall)->pos.x = this->rect.x;
            (*wall)->pos.y = this->rect.y;
            (*wall)->is_free = false;
            wall++;
            this->rect.x += width;
        } else if ((*map)[i] == 'o') {
            (*gum)->pos.x = this->rect.x;
            (*gum)->pos.y = this->rect.y;
            (*gum)->is_free = false;
            gum++;
            this->rect.x += width;
        } else if ((*map)[i] == '0') {
            (*supergum)->pos.x = this->rect.x;
            (*supergum)->pos.y = this->rect.y;
            (*supergum)->is_free = false;
            supergum++;
            this->rect.x += width;
        } else if ((*map)[i] == 'w' || (*map)[i] == 'm' || (*map)[i] == 'f' || (*map)[i] == 'g' || (*map)[i] == 'W' || (*map)[i] == 'M' || (*map)[i] == 'F' || (*map)[i] == 'G') {
            (*fantomes)->pos.x = this->rect.x;
            (*fantomes)->pos.y = this->rect.y;
            (*fantomes)->is_free = false;
            (*fantomes)->rect = tmp;
            tmp.x += 25;
            if ((*map)[i] == 'W' || (*map)[i] == 'M' || (*map)[i] == 'F' || (*map)[i] == 'G')
                (*fantomes)->rect.y = 25;
            else
                (*fantomes)->rect.y = 0;
            fantomes++;
            this->rect.x += width;
        } else if ((*map)[i] == 'u' || (*map)[i] == 'd'|| (*map)[i] == 'l'|| (*map)[i] == 'r') {
            (*pacman)->pos.x = this->rect.x;
            (*pacman)->pos.y = this->rect.y;
            if (pmopen < 2) (*pacman)->rect = {0, 0, 25, 25};
            else (*pacman)->rect = {25, 0, 25, 25};
            (*pacman)->is_free = false;
            this->rect.x += width;
            if ((*map)[i] == 'u')
                (*pacman)->rotate = 90;
            else if ((*map)[i] == 'r')
                (*pacman)->rotate = 180;
            else if ((*map)[i] == 'd')
                (*pacman)->rotate = -90;
            else
                (*pacman)->rotate = 0;
            pacman++;
        } else this->rect.x += width;
    }
    this->rect = savePos;
    pmopen = (pmopen < 2) ? pmopen + 1 : 0;
}

void sdl2::set_nblrpos(std::string *map)
{
    auto wall = this->nblrSp["wall"].begin();
    auto body = this->nblrSp["body"].begin();
    auto food = this->nblrSp["food"].begin();
    if (this->rect.w == -1) {
        int x = 0, y = 0;
        for (int i = 0; i < (int)(*map).length(); i++) {
            if ((*map)[i] == '\n') y++;
            else if (y == 0) x++;
        }
        this->rect = {this->rect.x - (x * (25 / 2)) / 2, this->rect.y - (y * (25 / 2)) / 2, 0, 0};
        this->rectT.x = this->rect.x;
        this->rectT.y -= this->rect.y - 50;
    }
    SDL_Rect savePos = this->rect;
    for (int i = 0; i < (int)(*map).length(); i++) {
        if ((*map)[i] == '\n') {
            this->rect.x = savePos.x;
            this->rect.y += 25 / 2;
        }
        else if ((*map)[i] == 'x') {
            (*wall)->pos.x = this->rect.x;
            (*wall)->pos.y = this->rect.y;
            (*wall)->is_free = false;
            wall++;
            this->rect.x += 25 / 2;
        }
        else if ((*map)[i] == 'o') {
            (*food)->pos.x = this->rect.x;
            (*food)->pos.y = this->rect.y;
            (*food)->is_free = false;
            food++;
            this->rect.x += 25 / 2;
        }
        else if ((*map)[i] == 'B') {
            (*body)->pos.x = this->rect.x;
            (*body)->pos.y = this->rect.y;
            (*body)->is_free = false;
            body++;
            this->rect.x += 25 / 2;
        }
        else if ((*map)[i] == 'r' || (*map)[i] == 'u' || (*map)[i] == 'l' || (*map)[i] == 'd') {
            this->nblrSp["head"].front()->pos.x = this->rect.x;
            this->nblrSp["head"].front()->pos.y = this->rect.y;
            this->nblrSp["head"].front()->is_free = false;
            if ((*map)[i] == 'r')
                this->nblrSp["head"].front()->rotate = 90;
            else if ((*map)[i] == 'd')
                this->nblrSp["head"].front()->rotate = 180;
            else if ((*map)[i] == 'l')
                this->nblrSp["head"].front()->rotate = 270;
            else
                this->nblrSp["head"].front()->rotate = 0;
            this->rect.x += 25 / 2;
        } else this->rect.x += 25 / 2;
    }
    this->rect = savePos;
}

int sdl2::draw_game(std::string *map, int score)
{
    if (map == NULL || (*map) == "ERROR")
        return (84);
    if (!this->pmanSp.empty())
        this->set_pmpos(map);
    else
        this->set_nblrpos(map);
    this->set_score(score);
    this->key = globalKeys::NOTHING;
    while (SDL_PollEvent(&(this->evt))) {
        if (this->evt.type == SDL_KEYDOWN) {
            if (this->evt.key.keysym.sym == SDLK_SPACE)
                return (0);
            if (this->evt.key.keysym.sym == SDLK_LEFT)
                this->key = globalKeys::LEFT;
            else if (this->evt.key.keysym.sym == SDLK_RIGHT)
                this->key = globalKeys::RIGHT;
            else if (evt.key.keysym.sym == SDLK_UP)
                this->key = globalKeys::UP;
            else if (evt.key.keysym.sym == SDLK_DOWN)
                this->key = globalKeys::DOWN;
            else if (evt.key.keysym.sym == SDLK_p)
                this->key = globalKeys::PREVGRAPH;
            else if (evt.key.keysym.sym == SDLK_n)
                this->key = globalKeys::NEXTGRAPH;
            else if (evt.key.keysym.sym == SDLK_l)
                this->key = globalKeys::PREVGAME;
            else if (evt.key.keysym.sym == SDLK_o)
                this->key = globalKeys::NEXTGAME;
            else if (evt.key.keysym.sym == SDLK_r)
                this->key = globalKeys::RESTART;
            else if (evt.key.keysym.sym == SDLK_m)
                this->key = globalKeys::MENU;
            else if (evt.key.keysym.sym == SDLK_s)
                this->key = globalKeys::SAVE;
        }
    }
    SDL_RenderClear(this->rend);
    SDL_RenderCopy(this->rend, this->scoreT, NULL, &this->rectT);
    for (auto &i : pmanSp)
        for (auto &j : i.second)
            if (j->is_free == false)
                SDL_RenderCopyEx(this->rend, j->tu, &j->rect, &j->pos, j->rotate, NULL, SDL_FLIP_NONE);
    for (auto &i : nblrSp)
        for (auto &j : i.second)
            if (j->is_free == false)
                SDL_RenderCopyEx(this->rend, j->tu, &j->rect, &j->pos, j->rotate, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(this->rend);
    return (-1);
}

static void draw_rect_if_in(int *is_on, int x, int y, SDL_Rect txtr_draw)
{
    if (x >= txtr_draw.x && x <= txtr_draw.x + txtr_draw.w
    && y >= txtr_draw.y && y <= txtr_draw.y + txtr_draw.h)
        *is_on = 3;
    else *is_on = 0;
}


bool sdl2::is_mouse_in(SDL_Rect rect)
{
    int x = 0, y = 0;
    SDL_GetMouseState(&x, &y);
    if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h)
        return (true);
    return (false);
}

int sdl2::draw_menu()
{
    int final = -1, texW = 0, texH = 0;
    SDL_Event evt;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);
    Mix_Init(MIX_INIT_OGG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    SDL_Window *win = SDL_CreateWindow("Sdl2 - Arcade", 100, 100, 800, 600, SDL_WINDOW_HIDDEN);
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, 0);
    TTF_Font *font = TTF_OpenFont("./lib/Graphic/sfml/assets/menu/ARCADE_I.TTF", 20);
    TTF_Font *small_font = TTF_OpenFont("./lib/Graphic/sfml/assets/menu/ARCADE_I.TTF", 15);
    SDL_Color white = {255, 255, 255, 255};
    SDL_Rect txtr[] = {{350, 440, 0, 0}, {350, 480, 0, 0}, {150, 100, 0, 0}, {150, 140, 0, 0}, {450, 100, 0, 0}, {450, 140, 0, 0}, {450, 180, 0, 0}, {150, 300, 0, 0}, {150, 340, 0, 0}, {150, 380, 0, 0}};
    SDL_Rect txtr_draw[] = {{350, 440, 0, 0}, {350, 480, 0, 0}, {150, 100, 0, 0}, {150, 140, 0, 0}, {450, 140, 0, 0}, {450, 180, 0, 0}, {150, 300, 0, 0}};
    const char *txt[] = {"Play", "Quit", "pacman", "nibbler", "actual: sdl2", "sfml", "ncurses", "Highscores:", "nibbler: 1234567 - 123456789", "pacman: 1234567 - 123456789"};
    int game_chosed = 0, max_len = 0;
    std::ifstream fs("lib/Games/high_score.txt");
    std::string line1, line2, tmptxt = "Highscores:";
    SDL_Surface *surface[11];
    SDL_Texture *texture[11];
    int is_on[] = {0, 0, 0, 0, 0, 0, 1};
    Mix_Music *music = Mix_LoadMUS("lib/Graphic/musics/menu.ogg");
    if (fs.is_open()) {
        getline(fs, line1);
        txt[8] = line1.c_str();
        getline(fs, line2);
        txt[9] = line2.c_str();
        fs.close();
    }
    if (line2.length() > line1.length())
        max_len = (line2.length() > tmptxt.length()) ? 9 : 7;
    else max_len = (line1.length() > tmptxt.length()) ? 8 : 7;
    for (int i = 0, ju = 0; i < 10; i++) {
        if (i == 8 || i == 9)
            surface[i] = TTF_RenderText_Solid(small_font, txt[i], white);
        else
            surface[i] = TTF_RenderText_Solid(font, txt[i], white);
        texture[i] = SDL_CreateTextureFromSurface(renderer, surface[i]);
        SDL_QueryTexture(texture[i], NULL, NULL, &texW, &texH);
        txtr[i] = {txtr[i].x, txtr[i].y, texW, texH};
        if (i == 4 || i > 5)
            continue;
        txtr_draw[ju] = {txtr_draw[ju].x - 4, txtr_draw[ju].y - 4, texW + 8, texH + 8};
        ju++;
    }
    SDL_QueryTexture(texture[6], NULL, NULL, &texW, &texH);
    txtr_draw[5] = {txtr_draw[5].x - 4, txtr_draw[5].y - 4, texW + 8, texH + 8};
    txtr_draw[6] = {txtr[7].x - 4, txtr[7].y - 4, 0, 0};
    txtr_draw[6].w = txtr[max_len].w + 8;
    txtr_draw[6].h = (txtr[8].h + txtr[7].h + txtr[6].h) * 2 - 6;
    SDL_SetRenderDrawColor(renderer, 220, 20, 60, 255);
    surface[10] = IMG_Load("lib/Graphic/sfml/assets/menu/bg.png");
    texture[10] = SDL_CreateTextureFromSurface(renderer, surface[10]);
    Mix_PauseMusic();
    SDL_ShowWindow(win);
    Mix_PlayMusic(music, -1);
    Mix_VolumeMusic(100);
    while (final == -1) {
        while (SDL_PollEvent(&evt)) {
            if (evt.type == SDL_QUIT)
                final = 0;
            else if (evt.type == SDL_MOUSEMOTION) {
                SDL_GetMouseState(&texW, &texH);
                for (int i = 0; i < 6; i++)
                    draw_rect_if_in(&is_on[i], texW, texH, txtr_draw[i]);
            }
            else if (evt.type == SDL_MOUSEBUTTONDOWN) {
                for (int i = 0; i < 6; i++) {
                    if (is_on[i] >= 2) {
                        if (i == 0 && game_chosed)
                            final = game_chosed;
                        else if (i == 1)
                            final = 0;
                        else if (i == 2 && is_mouse_in(txtr[i]))
                            game_chosed = (game_chosed == 5) ? 0 : 5;
                        else if (i == 3 && is_mouse_in(txtr[i]))
                            game_chosed = (game_chosed == 6) ? 0 : 6;
                        else if (i == 4 || i == 5)
                            final = (i == 4) ? 3 : 1;
                    }
                }
            }
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture[10], NULL, NULL);
        if (game_chosed == 5) {
            is_on[2] = 2;
            is_on[3] = (is_on[3] == 2) ? 0 : is_on[3];
        }
        else if (game_chosed == 6) {
            is_on[3] = 2;
            is_on[2] = (is_on[2] == 2) ? 0 : is_on[2];
        }
        for (int i = 0; i < 10; i++) {
            if (i == 0 && !game_chosed)
                continue;
            SDL_RenderCopy(renderer, texture[i], NULL, &txtr[i]);
            if (i <= 6 && is_on[i]) {
                if (is_on[i] == 1)
                    SDL_SetRenderDrawColor(renderer, 0, 0, 128, 255);
                else if (is_on[i] == 2)
                    SDL_SetRenderDrawColor(renderer, 220, 20, 60, 255);
                else SDL_SetRenderDrawColor(renderer, 255, 215, 0, 255);
                SDL_RenderDrawRect(renderer, &txtr_draw[i]);
            }
        }
        SDL_RenderPresent(renderer);
    }
    Mix_FreeMusic(music);
    for (int i = 0; i < 11; i++) {
        SDL_DestroyTexture(texture[i]);
        SDL_FreeSurface(surface[i]);
    }
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    Mix_CloseAudio();
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
    return (final);
}

void sdl2::load_pacman()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_EVENTS);
    SDL_Init(SDL_INIT_AUDIO);
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);
    Mix_Init(MIX_INIT_OGG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    this->_win = SDL_CreateWindow("Sdl2 - Pacman", 0, 0, 1920, 1080, SDL_WINDOW_HIDDEN);
    this->rend = SDL_CreateRenderer(this->_win, -1, 0);
    this->pmanSp["pacman"].emplace_back(new sdl2::sprites("./lib/Graphic/sfml/assets/pacman/pman.png", this->rend));
    for (int i = 0; i < 4; i++) {
        this->pmanSp["fantomes"].emplace_back(new sdl2::sprites("./lib/Graphic/sfml/assets/pacman/fantomes.png", this->rend));
        this->pmanSp["supergum"].emplace_back(new sdl2::sprites("./lib/Graphic/sfml/assets/pacman/super_gum.png", this->rend));
    }
    for (int i = 0; i < 364; i++)
        this->pmanSp["wall"].emplace_back(new sdl2::sprites("./lib/Graphic/sfml/assets/pacman/wall.png", this->rend));
    for (int i = 0; i < 226; i++)
        this->pmanSp["gum"].emplace_back(new sdl2::sprites("./lib/Graphic/sfml/assets/pacman/gum.png", this->rend));
    
    this->music = Mix_LoadMUS("lib/Graphic/musics/pacman.ogg");
    Mix_PlayMusic(this->music, -1);
    SDL_GetWindowSize(this->_win, &(this->rect.x), &(this->rect.y));
    this->rect = {this->rect.x / 2, this->rect.y / 2, -1, -1};
    this->font = TTF_OpenFont("./lib/Graphic/sfml/assets/menu/ARCADE_I.TTF", 15);
    this->suT = TTF_RenderText_Solid(this->font, "Score: 0", (SDL_Color){255, 255, 255, 255});
    this->scoreT = SDL_CreateTextureFromSurface(this->rend, this->suT);
    SDL_QueryTexture(this->scoreT, NULL, NULL, &this->rectT.w, &this->rectT.h);
    SDL_SetWindowFullscreen(this->_win, true);
    SDL_ShowWindow(this->_win);
}

void sdl2::set_score(int score)
{
    std::string txt = "Score: ";
    SDL_FreeSurface(this->suT);
    SDL_DestroyTexture(this->scoreT);
    txt += std::to_string(score);
    this->suT = TTF_RenderText_Solid(this->font, txt.c_str(), (SDL_Color){192, 192, 192, 255});
    this->scoreT = SDL_CreateTextureFromSurface(this->rend, this->suT);
    SDL_QueryTexture(this->scoreT, NULL, NULL, &this->rectT.w, &this->rectT.h);
}

void sdl2::unload_pacman()
{
    for (auto &i : this->pmanSp) {
        while (!i.second.empty()) {
            SDL_FreeSurface(i.second.front()->sp);
            SDL_DestroyTexture(i.second.front()->tu);
            i.second.pop_front();
        }
    }
    SDL_DestroyTexture(this->scoreT);
    SDL_FreeSurface(this->suT);
    TTF_CloseFont(this->font);
    Mix_FreeMusic(this->music);
    SDL_DestroyRenderer(this->rend);
    SDL_DestroyWindow(this->_win);
    Mix_CloseAudio();
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
    this->pmanSp.clear();
}

void sdl2::load_nibbler()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_EVENTS);
    SDL_Init(SDL_INIT_AUDIO);
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);
    Mix_Init(MIX_INIT_OGG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    this->_win = SDL_CreateWindow("Sdl2 - Nibbler", 0, 0, 1920, 1080, SDL_WINDOW_HIDDEN);
    this->rend = SDL_CreateRenderer(this->_win, -1, 0);
    for (int i = 0; i < 189; i++)
        this->nblrSp["wall"].emplace_back(new sdl2::sprites("./lib/Graphic/sfml/assets/nibbler/wall.png", this->rend));
    for (int i = 0; i < 171; i++)
        this->nblrSp["body"].emplace_back(new sdl2::sprites("./lib/Graphic/sfml/assets/nibbler/body.png", this->rend));
    this->nblrSp["head"].emplace_back(new sdl2::sprites("./lib/Graphic/sfml/assets/nibbler/head.png", this->rend));
    for (int i = 0; i < 10; i++)
        this->nblrSp["food"].emplace_back(new sdl2::sprites("./lib/Graphic/sfml/assets/nibbler/food.png", this->rend));
    this->music = Mix_LoadMUS("./lib/Graphic/musics/nibbler.ogg");
    Mix_PlayMusic(this->music, -1);
    SDL_GetWindowSize(this->_win, &(this->rect.x), &(this->rect.y));
    this->rect = {this->rect.x / 2, this->rect.y / 2, -1, -1};
    this->font = TTF_OpenFont("./lib/Graphic/sfml/assets/menu/ARCADE_I.TTF", 20);
    this->suT = TTF_RenderText_Solid(this->font, "Score: 0", (SDL_Color){255, 255, 255, 255});
    this->scoreT = SDL_CreateTextureFromSurface(this->rend, this->suT);
    this->rectT = this->rect;
    SDL_ShowWindow(this->_win);
}

void sdl2::unload_nibbler()
{
    for (auto &i : this->nblrSp) {
        while (!i.second.empty()) {
            SDL_FreeSurface(i.second.front()->sp);
            SDL_DestroyTexture(i.second.front()->tu);
            i.second.pop_front();
        }
    }
    SDL_DestroyTexture(this->scoreT);
    SDL_FreeSurface(this->suT);
    TTF_CloseFont(this->font);
    Mix_FreeMusic(this->music);
    SDL_DestroyRenderer(this->rend);
    SDL_DestroyWindow(this->_win);
    Mix_CloseAudio();
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
    this->nblrSp.clear();
}

globalKeys::keys_t sdl2::getGlobalKey()
{
    return (this->key);
}

static SDL_Texture *getTxt(SDL_Renderer *rend, TTF_Font *fnt, const char *txt, SDL_Color color, SDL_Rect *rect)
{
    SDL_Surface *su = TTF_RenderText_Solid(fnt, txt, color);
    SDL_Texture *tu = SDL_CreateTextureFromSurface(rend, su);
    SDL_QueryTexture(tu, NULL, NULL, &(*rect).w, &(*rect).h);
    SDL_FreeSurface(su);
    return (tu);
}

std::string sdl2::draw_end(int score, bool is_win)
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);
    Mix_Init(MIX_INIT_OGG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    SDL_Event evnt;
    SDL_Window *win = SDL_CreateWindow("Sdl2 - Arcade", 100, 100, 800, 600, SDL_WINDOW_HIDDEN);
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, 0);
    TTF_Font *small_font = TTF_OpenFont("./lib/Graphic/sfml/assets/menu/ARCADE_I.TTF", 15);
    SDL_Color white = {255, 255, 255, 255};
    SDL_Color red = {255, 0, 0, 255};
    std::string tmp = (is_win) ? "That's a win !" : "That's a shame..", name_score = "";
    const char *txt[6] = {tmp.c_str(), "Please type your name:", "", "Restart", "Quit", "Back to menu"};
    SDL_Surface *su[6];
    SDL_Texture *tu[6];
    int width = 0, height = 0, final = -1;
    SDL_GetWindowSize(win, &width, &height);
    width /= 2;
    height /= 2;
    SDL_Rect rects[6] = {{width, 0, 0, 0}, {width, 0, 0, 0}, {width, 0, 0, 0}, {width, height * 2, 0, 0}, {width, height * 2, 0, 0}, {width, height * 2, 0, 0}};
    for (int i = 0; i < 6; i++) {
        su[i] = TTF_RenderText_Solid(small_font, txt[i], white);
        tu[i] = SDL_CreateTextureFromSurface(renderer, su[i]);
        SDL_QueryTexture(tu[i], NULL, NULL, &width, &height);
        if (i == 4)
            rects[i] = {rects[i].x - width / 2, rects[i].y - height * 2, width, height};
        else if (i == 5)
            rects[i] = {rects[i].x - width / 2, rects[i].y - height * 4, width, height};
        else if (i == 3)
            rects[i] = {rects[i].x - width / 2, rects[i].y - height * 6, width, height};
        else
            rects[i] = {rects[i].x - width / 2, i * 50 + 20, width, height};
        SDL_FreeSurface(su[i]);
    }
    Mix_Music *music = Mix_LoadMUS("lib/Graphic/musics/menu.ogg");
    Mix_VolumeMusic(100);
    Mix_PlayMusic(music, -1);
    SDL_ShowWindow(win);
    while (final == -1) {
        while (SDL_PollEvent(&evnt)) {
            if (evnt.type == SDL_QUIT)
                final = 0;
            else if (evnt.type == SDL_MOUSEMOTION) {
                for (int i = 3; i < 6; i++) {
                    if (this->is_mouse_in(rects[i])) {
                        SDL_DestroyTexture(tu[i]);
                        tu[i] = getTxt(renderer, small_font, txt[i], red, &rects[i]);
                    } else {
                        SDL_DestroyTexture(tu[i]);
                        tu[i] = getTxt(renderer, small_font, txt[i], white, &rects[i]);
                    }
                }
            }
            else if (evnt.type == SDL_MOUSEBUTTONDOWN) {
                for (int i = 3; i < 6; i++) {
                    if (is_mouse_in(rects[i])) {
                        if (i == 3)
                            this->key = globalKeys::RESTART;
                        else if (i == 5)
                            this->key = globalKeys::MENU;
                        final = 0;
                    }
                }
            }
            else if (evnt.type == SDL_KEYDOWN) {
                switch (evnt.key.keysym.sym) {
                    case SDLK_a:
                        name_score += "A";
                        break;
                    case SDLK_b:
                        name_score += "B";
                        break;
                    case SDLK_c:
                        name_score += "C";
                        break;
                    case SDLK_d:
                        name_score += "D";
                        break;
                    case SDLK_e:
                        name_score += "E";
                        break;
                    case SDLK_f:
                        name_score += "F";
                        break;
                    case SDLK_g:
                        name_score += "G";
                        break;
                    case SDLK_h:
                        name_score += "H";
                        break;
                    case SDLK_i:
                        name_score += "I";
                        break;
                    case SDLK_j:
                        name_score += "J";
                        break;
                    case SDLK_k:
                        name_score += "K";
                        break;
                    case SDLK_l:
                        name_score += "L";
                        break;
                    case SDLK_m:
                        name_score += "M";
                        break;
                    case SDLK_n:
                        name_score += "N";
                        break;
                    case SDLK_o:
                        name_score += "O";
                        break;
                    case SDLK_p:
                        name_score += "P";
                        break;
                    case SDLK_q:
                        name_score += "Q";
                        break;
                    case SDLK_r:
                        name_score += "R";
                        break;
                    case SDLK_s:
                        name_score += "S";
                        break;
                    case SDLK_t:
                        name_score += "T";
                        break;
                    case SDLK_u:
                        name_score += "U";
                        break;
                    case SDLK_v:
                        name_score += "V";
                        break;
                    case SDLK_w:
                        name_score += "W";
                        break;
                    case SDLK_x:
                        name_score += "X";
                        break;
                    case SDLK_y:
                        name_score += "Y";
                        break;
                    case SDLK_z:
                        name_score += "Z";
                        break;
                    case SDLK_BACKSPACE:
                        if (!name_score.empty())
                            name_score.pop_back();
                        break;
                    default:
                        break;
                }
                if (name_score.length() > 7)
                    name_score.pop_back();
                SDL_DestroyTexture(tu[2]);
                tu[2] = getTxt(renderer, small_font, name_score.c_str(), white, &rects[2]);
                SDL_GetWindowSize(win, &rects[2].x, NULL);
                rects[2].x = rects[2].x / 2 - rects[2].w / 2;
            }
        }
        SDL_RenderClear(renderer);
        for (int i = 0; i < 6; i++)
            SDL_RenderCopy(renderer, tu[i], NULL, &rects[i]);
        SDL_RenderPresent(renderer);
    }
    TTF_CloseFont(small_font);
    for (int i = 0; i < 6; i++)
        SDL_DestroyTexture(tu[i]);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    Mix_CloseAudio();
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
    name_score += " - " + std::to_string(score);
    return (name_score);
}

extern "C" std::unique_ptr<IGraphic> create()
{
    return std::make_unique<sdl2>();
}