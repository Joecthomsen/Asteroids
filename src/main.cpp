#include "Game.h"

int main()
{
/*
    The game loop is runned from here.
    -Initialize the game engine
    -initialize the window
    -Enter gameloop, and run while the window is not terminated
*/

    //Init game engine
    Game game;

    //Initialize window
    game.initWindow();

    while (game.running())   
    {
    //Take input

    //Update game

    game.update();

    //Render 
    }

    return 0;
}