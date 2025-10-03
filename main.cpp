#include <iostream>
#include <queue>

class Player {
    int x, y;
    
public:
    Player(int width) {
        //Player begins in the top middle of the map
        x = width / 2;
        y = 0;
    }
};

class Lane {
    // Obstacles opposing the player
    std::deque<bool> cars;
public:
    Lane(int width) {
        for (int i = 0; i < width; i++) {
            // init
            cars.push_front(false);
        }
    }

    // 1 in 10 chance of car appearing from the left
    void drive() {
        if (rand() % 10 == 1)
            cars.push_front(true);
        else
            cars.push_front(false);
        
        // maintain width
        cars.pop_back();
    }

    bool checkPos(int pos) {
        return cars[pos];
    }
};

class Game {
    bool quit;
public:
    void draw() {

    }

    void input() {

    }

    void logic() {

    }

    void run() {
        while (!quit) {
            input();
            draw();
            logic();
        }

    }
};

int main() {
    Lane lane1(20);

    for (int i = 0; i < 20; i++) {
        if (lane1.checkPos(i)) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
    }
    lane1.drive();
    for (int i = 0; i < 20; i++) {
        if (lane1.checkPos(i)) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
    }
}