#include <iostream>
#include "game.h"
#include "player.h"
#include "lane.h"  



int main() {
    srand(time(0));
    Game game(30,5);
    game.run();

    

}