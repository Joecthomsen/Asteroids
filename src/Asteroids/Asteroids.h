#ifndef _Weapon_H_
#define _Weapon_H_
#include <Player.h>


class Asteroids
{

private:

    sf::CircleShape asteroid;
    sf::Vector2f direction;
    float speed = 5.f;
    int level = 1;
   
public:
    Asteroids();
    ~Asteroids();

    sf::CircleShape getAsteriod();
    void updatePos();
    

};


#endif