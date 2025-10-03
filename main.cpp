#include <iostream>
#include <queue>
#include "game.h"
#include "player.h"
#include "lane.h"  



int main() {
    srand(time(0));
    Lane lane1(20);

    
    for (int j = 0; j < 20; j++) {
        lane1.drive();
        for (int i = 0; i < 20; i++) {
        if (lane1.checkPos(i)) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
        }
        std::cout << std::endl;
    }

    

}