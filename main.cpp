#include <iostream>
#include "game.cpp"
#include "player.cpp"
#include "lane.cpp"  



int main() {
    srand(time(0));
    Game game(30,5);
    game.run();

    

}