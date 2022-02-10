#ifndef _Weapon_H_
#define _Weapon_H_

#include "Player.h"


class Weapon
{
private:

    float speed = 10.f;

    sf::RectangleShape player;
    sf::Vector2f pos;
    sf::CircleShape circleShape;
    //std::vector<Weapon> bulletList;
    sf::Vector2f direction;
   
public:

    

    Weapon();
    Weapon(Player p);
    ~Weapon();

    sf::CircleShape getBullet();

    void setPos();
    sf::Vector2f getPos();

};

#endif