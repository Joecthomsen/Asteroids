#include "Weapon.h"


Weapon::Weapon(Player p) 
{
    //this->player = p;
    this->circleShape.setRadius(3.0);
    this->circleShape.setFillColor(sf::Color::Yellow);
    this->circleShape.setPosition(p.getPos().x, p.getPos().y);
    this->direction = p.getDirection();
    //this->bullet.setPosition(player.getPosition().x, player.getPosition().y);
    
}

Weapon::Weapon() {
    
}


Weapon::~Weapon() {}



sf::CircleShape Weapon::getBullet() 
{
    return this->circleShape;
}


void Weapon::setPos() 
{
    this->circleShape.setPosition(this->circleShape.getPosition().x + this->speed * this->direction.x, this->circleShape.getPosition().y + this->speed * this->direction.y);
    
    //printf("%f, %f\n",this->circleShape.getPosition().x, this->circleShape.getPosition().y);

    if(this->circleShape.getPosition().x > 800 || this->circleShape.getPosition().x < 0 || this->circleShape.getPosition().y > 800 || this->circleShape.getPosition().x < 0)
    {
        
    }
}

sf::Vector2f Weapon::getPos() {
    return this->circleShape.getPosition();    
}
