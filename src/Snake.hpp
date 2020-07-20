#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>

using namespace std;

class Snake {
    private:
        int size = 3;
        int pos_x;
        int pos_y;
        vector<vector<int>> tail;
        vector<int> dir {0, 1};

    public:

        Snake() {}
        Snake(int, int);
        void display();
        void update();
        void move_tail();
        void change_dir(int, int);

        // Checks if snake dies of
        // self-intersection or running
        // away
        bool self_intersect();
        bool out_boundaries(int, int);

        // Has the snake eaten the fruit?
        bool has_eaten(int p[2]) {
            return (this->pos_x==p[0] and
                    this->pos_y==p[1]);
        }

        void increase_size();

};


#endif
