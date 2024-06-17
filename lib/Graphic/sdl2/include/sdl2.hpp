/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-gael.leroy
** File description:
** sdl2
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include "../../IGraphic.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

extern "C" std::unique_ptr<IGraphic> create();

class sdl2 : public IGraphic {
    public:
        class sprites {
            sprites();
            public:
                sprites(const std::string &filepath, SDL_Renderer *rend) {
                    this->sp = IMG_Load(filepath.c_str());
                    this->tu = SDL_CreateTextureFromSurface(rend, this->sp);
                    this->is_free = true;
                    this->pos = {0, 0, 25, 25};
                    this->rect = {0, 0, 25, 25};
                    this->rotate = 0;
                }
                ~sprites() {
                    SDL_DestroyTexture(this->tu);
                    SDL_FreeSurface(this->sp);
                }
                SDL_Surface *sp;
                SDL_Texture *tu;
                SDL_Rect pos;
                SDL_Rect rect;
                float rotate;
                bool is_free;
        };
        sdl2();
        virtual ~sdl2();
        virtual int draw_game(std::string *map, int score);
        virtual int draw_menu();
        virtual std::string getName() const;
        virtual void load_pacman();
        virtual void unload_pacman();
        virtual void load_nibbler();
        virtual void unload_nibbler();
        virtual globalKeys::keys_t getGlobalKey();
        virtual std::string draw_end(int score, bool is_win);
    private:
        bool is_mouse_in(SDL_Rect rect);
        SDL_Window *_win;
        SDL_Renderer *rend;
        Mix_Music *music;
        SDL_Event evt;
        SDL_Rect rect;
        TTF_Font *font;
        SDL_Surface *suT;
        SDL_Rect rectT;
        SDL_Texture *scoreT;
        std::unordered_map<std::string, std::list<sprites *> > pmanSp;
        void set_pmpos(std::string *map);
        std::unordered_map<std::string, std::list<sprites *> > nblrSp;
        void set_nblrpos(std::string *map);
        globalKeys::keys_t key;
        void set_key(globalKeys::keys_t key);
        void set_score(int score);
};

#endif /* !SDL2_HPP_ */
