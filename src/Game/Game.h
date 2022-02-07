#ifndef _Game_H_
#define _Game_H_

#include "Player.h"

class Game
{

private:

    sf::Event windowEvent;
    sf::RenderWindow * window;
    sf::VideoMode videoMode;
    Player player = Player(400, 400);

public:
    //Constructors and deconstructors
    Game();
    ~Game();

    //Input
    void keyboardInput();

    //Functions
    const bool running();
    void update();
    void initWindow();
    void render();
};
#endif