#ifndef LANE_H
#define LANE_H
#include <queue>

class Lane {
    // Obstacles opposing the player
    std::deque<bool> cars;
    
public:
    Lane(int width);

    // 1 in 10 chance of car appearing from the left
    void drive();

    bool checkPos(int pos);
};

#endif