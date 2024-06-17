/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-gael.leroy
** File description:
** sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "../../IGraphic.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>


extern "C" std::unique_ptr<IGraphic> create();

class sfml : public IGraphic {
    public:
        class sprites {
                sprites();
            public:
                sprites(const std::string &filepath) {
                    std::string file = filepath;
                    this->tu.loadFromFile(file);
                    this->sp.setTexture(this->tu);
                    this->is_free = true;
                };
                ~sprites() {};
                sf::Sprite sp;
                sf::Texture tu;
                bool is_free;
        };
        sfml();
        virtual ~sfml();
        virtual std::string getName() const;
        virtual int draw_game(std::string *map, int score = 0);
        virtual int draw_menu();
        virtual void load_pacman();
        virtual void unload_pacman();
        virtual void load_nibbler();
        virtual void unload_nibbler();
        virtual globalKeys::keys_t getGlobalKey();
        virtual std::string draw_end(int score, bool is_win);
    private:
        sf::RenderWindow *_win;
        sf::Music *music;
        sf::Event evt;
        sf::Text *scoreT;
        sf::Font *font;
        std::unordered_map<std::string, std::list<sprites *> > pmanSp;
        void set_pmpos(std::string *map, sf::Vector2f prevPos);
        std::unordered_map<std::string, std::list<sprites *> > nblrSp;
        void set_nblrpos(std::string *map, sf::Vector2f prevPos);
        globalKeys::keys_t key;
        char dir;
};

#endif /* !SFML_HPP_ */
