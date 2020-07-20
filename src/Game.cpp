#include <iostream>
#include <ncurses.h>
#include <string>

#include "Game.hpp"
#include "Snake.hpp"

using namespace std;

void Game::display() {
    
    // Display board
    for (int i=0; i<=this->HEIGHT; i++) {
        for (int j=0; j<=this->WIDTH; j++) {
           if (i==0 or i==this->HEIGHT)
               mvprintw(i, j, this->BORDER);
           else if (j==0 or j==this->WIDTH)
               mvprintw(i, j, this->BORDER);
        }

    }

   
    // Display fruit
    mvprintw(this->fruit[1], this->fruit[0], this->FRUIT);

}

void Game::play() {
    // Create snake
    this->snake = Snake(this->WIDTH/2, this->HEIGHT/2);
    
    // Randomise fruit
    this->randomise_fruit();
    
    // ncurses.h stuff
    initscr();
    keypad(stdscr, TRUE);
    timeout(1000/this->FPS);


    char c;
    while (true) {
        clear();
        this->display();
        this->snake.display();

        // Check if snake has eaten fruit.
        // If so, make snake longer, increase
        // score and randomise fruit.
        if (this->snake.has_eaten(this->fruit)) {
            ++this->score;
            this->snake.increase_size(); 
            this->randomise_fruit();
       }

        mvprintw(this->HEIGHT + 2, 0, "Score: "); 
        mvprintw(this->HEIGHT + 3, 0, to_string(this->score).c_str());

        if (this->pause>0)
            mvprintw(this->HEIGHT + 1, 0, "You died!");


        // User input
        c = getch();

        if (this->pause==0) {
            //Game not paused

           
            if (c == 'w' or c == 'W')
                // Up
                this->snake.change_dir(0, -1);
            else if (c == 's' or c == 'S')
                // Down
                this->snake.change_dir(0, 1);
            else if (c == 'a' or c == 'A')
                // Left
                this->snake.change_dir(-1, 0);
            else if (c == 'd' or c == 'D')
                // Right
                this->snake.change_dir(1, 0);
            
            // Snake dynamics
            this->snake.update(); // Move snake
            this->snake.move_tail();
            if (this->snake.self_intersect()
                or this->snake.out_boundaries(this->WIDTH, this->HEIGHT))

                this->pause = 10;

        } else {
            --this->pause;
            
            if (this->pause==0)
                // Restart game!
                this->snake = Snake(this->WIDTH/2, this->HEIGHT/2);
                this->score = 0;
                    

               
        }

        refresh();

    }

    endwin();
}
