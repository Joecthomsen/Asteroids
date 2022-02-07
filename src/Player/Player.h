#ifndef _Player_H_
#define _Player_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

class Player
{

private:

    sf::RectangleShape player;
    sf::Vector2f speed = sf::Vector2f(0, 0);
    sf::Vector2f rotation = sf::Vector2f(0, 0); 
    float acceleration = 0.1;
    void rotateRight();
    void rotateLeft();

public:

    //Constructors and deconstructors
    Player(float x = 0, float y = 0);
    ~Player();

    //Accessors
    sf::RectangleShape getPlayer();

    //Modifiers
    void setPlayerSize(sf::Vector2f playerSize);
    void setPlayerStartPosition(float x, float y);
    void setPlayerColor();   //TODO


    //Functions
    void move();
    void setPosition();
    void renderPlayer(sf::RenderWindow * target);

};

#endif


