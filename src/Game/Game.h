#ifndef _Game_H_
#define _Game_H_

#include <Asteroids.h>

class Game
{

private:

    sf::Event windowEvent;
    sf::RenderWindow * window;
    sf::VideoMode videoMode;
    std::vector<Weapon> bulletList;
    std::vector<Asteroids> astroidList;
    Player player = Player(400, 400);
    Weapon bullet; //Weapon(player);
    Asteroids asteroid;

    //Timer for the bullet, so that the player cannot shoot a burst
    bool bulletTimerOn = false;
    float startTime = 0.f;
    float bulletDelay = 10.f;

    //Timer for the asteroids spawning time
    bool asteroidTimer = false;
    float asteriodStartTimer = 0.f;
    float asteroidSpawningTime = 20.f;




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