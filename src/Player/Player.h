#ifndef _Player_H_
#define _Player_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <vector>
#include <ctime>

class Player
{

private:

    sf::RectangleShape player;
    sf::Vector2f velocity = sf::Vector2f(0, 0);
    sf::Vector2f rotation = sf::Vector2f(0, 0); 
    float acceleration = 0.1;
    bool deleted = false;
 


public:

    //Constructors and deconstructors
    Player(float x = 0, float y = 0);
    ~Player();

    //Accessors
    sf::RectangleShape getPlayer();
    sf::Vector2f getDirection();
    sf::Vector2f getPos();

    //Modifiers
    void setPlayerSize(sf::Vector2f playerSize);
    void setPlayerStartPosition(float x, float y);
    void setPlayerColor();   //TODO
    void rotateRight();
    void rotateLeft();
    void setVelocity();


    //Functions
    void takeInput();
    void setPosition();
    void renderPlayer(sf::RenderWindow * target);

};

#endif


