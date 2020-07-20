#include <ncurses.h>
#include <string>
#include <vector>

#include "Snake.hpp"


using namespace std;

Snake::Snake(int pos_x, int pos_y) {
    this->pos_x = pos_x;
    this->pos_y = pos_y;

    for (int i=0; i<this->size-1; i++)
        tail.push_back(vector<int> {0, -1});

}

void Snake::display() {
    int x = this->pos_x;
    int y = this->pos_y;

    mvprintw(this->pos_y, this->pos_x, "O");
    for (int i=0; i<this->size-1; i++) {
        x += this->tail[i][0];
        y += this->tail[i][1];

        mvprintw(y, x, "O");
    }
}

void Snake::update() {
    this->pos_x += this->dir[0];
    this->pos_y += this->dir[1];
}

void Snake::move_tail() {
    // Move tail
    for (int i=this->size-2; i>0; i--)
        this->tail[i] = this->tail[i-1];

    this->tail[0] = {-this->dir[0], -this->dir[1]};

}

void Snake::change_dir(int dx, int dy) {
    if (abs(this->dir[0]) != abs(dx)
        or abs(this->dir[1]) != abs(dy)) {
        // If not trying to reverse direction
        // instantly
        this->dir = {dx, dy};

        
   }
}


bool Snake::self_intersect() {
    int x = this->pos_x;
    int y = this->pos_y;

    for (int i=0; i<this->size-1; i++) {
        x += this->tail[i][0];
        y += this->tail[i][1];

        if (x==this->pos_x and y==this->pos_y)
            return true;
    }

    return false;
}

bool Snake::out_boundaries(const int w, const int h) {
    if (this->pos_x >= w)
        return true;
    if (this->pos_x <= 0)
        return true;
    if (this->pos_y >= h)
        return true;
    if (this->pos_y <= 0)
        return true;

    return false;
}


void Snake::increase_size() {
    this->tail.push_back(this->tail[this->size-2]);
    ++this->size;
}
