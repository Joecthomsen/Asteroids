#include "Player.h"


//Constructors and deconstructors
Player::Player(float x, float y) 
{
/*
    @Constructor
    Construct player object
    -Set the players start position
    -Set the players size
    -Set the players color
    -Set players point of refrence (from left cornor to the middle of the player)
*/
    this->setPlayerStartPosition(x, y);
    this->setPlayerSize(sf::Vector2f(50, 100));
    this->setPlayerColor();
    this->player.setOrigin(this->player.getSize().x/2, this->player.getSize().y/2);
}   

Player::~Player() 
{
    
}

////////////////////////////////Modifyers////////////////////////////////

void Player::setPlayerSize(sf::Vector2f playerSize) 
{
/*
    @void
    Set player size
    #Take a float vector as parameter
*/
    this->player.setSize(playerSize);
}

void Player::setPlayerStartPosition(float x, float y) 
{
/*
    @void
    Set player size
    #float x as size x
    #float y as size y
*/
    this->player.setPosition(x, y);   
}



void Player::renderPlayer(sf::RenderWindow * target) 
{
    target->draw(this->player);
}

sf::RectangleShape Player::getPlayer() 
{
    return this->player;    
}

void Player::setPlayerColor() {
    this->player.setFillColor(sf::Color::Blue);   
}

void Player::move() 
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        //this->speed.x -= this->acceleration;
        this->rotateLeft();
    }    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        this->rotateRight();
        //this->speed.x += this->acceleration;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        this->speed.x += rotation.x/10;
        this->speed.y += rotation.y/10;
        //this->speed.y -= this->acceleration;
    }
    /*
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        this->speed.y += this->acceleration;
    }
    */
}

void Player::setPosition() 
{
    this->player.move(sf::Vector2f(this->speed.x, this->speed.y));
}

void Player::rotateLeft() 
{
    this->player.rotate(-1);
    rotation.x = sin(((player.getRotation())/360)*2*M_PI);
    rotation.y = -cos(((player.getRotation())/360)*2*M_PI);
    printf("x = %f  y = %f\n", rotation.x, rotation.y);   
}

void Player::rotateRight() 
{
    this->player.rotate(1);
    rotation.x = sin(((player.getRotation())/360)*2*M_PI);
    rotation.y = -cos(((player.getRotation())/360)*2*M_PI);
    printf("x = %f  y = %f\n", rotation.x, rotation.y);
}
