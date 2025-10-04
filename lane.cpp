#include "lane.h"

Lane::Lane(int width) {
    for (int i = 0; i < width; i++) {
        // init
        cars.push_front(false);
    }
    // 0 for false, 1 for true
    right = rand() % 2;
}

void Lane::drive() {
    if (right) {
        if (rand() % 10 == 1)
            cars.push_front(true);
        else
            cars.push_front(false);
        
        // maintain width
        cars.pop_back();
    } else {
        if (rand() % 10 == 1)
            cars.push_back(true);
        else
            cars.push_back(false);
        
        // maintain width
        cars.pop_front();
    }
    
}

bool Lane::checkPos(int pos) {
    return cars[pos];
}