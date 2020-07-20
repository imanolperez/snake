#ifndef GAME_HPP
#define GAME_HPP

#include "Snake.hpp"

class Game {
    private:
        const int WIDTH = 30;
        const int HEIGHT = 15;
        const int FPS = 6;
        int pause=0;
        int score=0;

        // Chars
        const char BORDER[2] = "*";
        const char FRUIT[2] = "X";

        // Direction
        int dir = 1;

        // Snake
        Snake snake;

        // Fruit
        int fruit[2];

    public:
        Game() {srand((unsigned int)time(NULL));}

        void display();
        void play();
        void randomise_fruit() {
            this->fruit[0] = 1 + (rand() % (this->WIDTH - 2));
            this->fruit[1] = 1 + (rand() % (this->HEIGHT - 2));
        }
};

#endif
