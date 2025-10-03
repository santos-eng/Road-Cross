#include "lane.h"

Lane::Lane(int width) {
    for (int i = 0; i < width; i++) {
        // init
        cars.push_front(false);
    }
}

void Lane::drive() {
    if (rand() % 8 == 1)
        cars.push_front(true);
    else
        cars.push_front(false);
    
    // maintain width
    cars.pop_back();
}

bool Lane::checkPos(int pos) {
    return cars[pos];
}