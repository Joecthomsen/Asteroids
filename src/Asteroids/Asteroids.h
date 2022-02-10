#ifndef _Asteroids_H_
#define _Asteroids_H_
#include <Weapon.h>


class Asteroids
{

private:

    enum spawnSide {TOP, RIGHT, DOWN, LEFT};
    int spawnSide;
    sf::CircleShape asteroid;
    sf::Vector2f direction;
    float speed = 3.f;
    int level = 1;
    float directionDegree;


public:
    Asteroids();
    Asteroids(sf::RenderWindow * target);
    ~Asteroids();

    sf::CircleShape getAsteriod();
    void setVariables();
    void updatePos();

};


#endif