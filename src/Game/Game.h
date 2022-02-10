#ifndef _Game_H_
#define _Game_H_

#include "Weapon.h"

class Game
{

private:

    sf::Event windowEvent;
    sf::RenderWindow * window;
    sf::VideoMode videoMode;
    std::vector<Weapon> bulletList;
    Player player = Player(400, 400);
    Weapon bullet; //Weapon(player);

    bool timerOn = false;
    float startTime = 0.f;
    float bulletDelay = 10.f;

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
    bool insideBoarders(Weapon w);
    
};
#endif