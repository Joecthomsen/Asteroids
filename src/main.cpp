#include "Game.h"

int main()
{
/*
    The game loop is runned from here.
    -Set seed for random number function
    -Initialize the game engine
    -initialize the window
    -Enter gameloop, and run while the window is not terminated
*/
    //Seed for random number
    srand((unsigned int)time(NULL));
    
    //Init game engine
    Game game;

    //Initialize window
    game.initWindow();

    while (game.running())   
    {
    //Take input
    game.keyboardInput();
    //Update game
    game.update();
    //Render 
    game.render();
    }

    return 0;
}