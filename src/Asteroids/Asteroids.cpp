#include <Asteroids.h>

//Constructors and deconstructors

Asteroids::Asteroids() {}

Asteroids::Asteroids(sf::RenderWindow * target) 
{
    //this->directionDegree = rand() % 60;
    //t
    //this->spawnSide = rand() % 4;
    this->spawnSide = TOP;
    this->setVariables();

    switch (this->spawnSide)
    {
    case TOP :
        this->directionDegree = static_cast<float>( rand() % static_cast<int>(110)) - 70;
        this->asteroid.setPosition(static_cast<float>( rand() % static_cast<int>(target->getSize().x - 15)),-50.f);
        this->direction.x = sin(((directionDegree/360)*2*M_PI));
        this->direction.y = -cos(((directionDegree)/360)*2*M_PI);
        printf("%f    %f\n", this->direction.x, this->direction.y); 
        break;
    case DOWN :
        this->directionDegree = static_cast<float>( rand() % static_cast<int>(110)) - 70;
        this->asteroid.setPosition(static_cast<float>( rand() % static_cast<int>(target->getSize().x - 15)), 830.f);
        this->direction.x = sin(((directionDegree/360)*2*M_PI));
        this->direction.y = -cos(((directionDegree)/360)*2*M_PI);
        printf("%f    %f\n", this->direction.x, this->direction.y); 
        break;
    case LEFT : 
        this->directionDegree = 110 + static_cast<float>( rand() % static_cast<int>(80));
        this->asteroid.setPosition(-30.f, rand() % static_cast<int>(target->getSize().x - 15));
        this->direction.x = sin(((directionDegree)/360)*2*M_PI);
        this->direction.y = -cos(((directionDegree)/360)*2*M_PI);
        printf("%f    %f\n", this->direction.x, this->direction.y);         break;
    case RIGHT :
        this->directionDegree = 110 + static_cast<float>( rand() % static_cast<int>(80));
        this->asteroid.setPosition(830.f, rand() % static_cast<int>(target->getSize().x - 15));
        this->direction.x = sin(((directionDegree)/360)*2*M_PI);
        this->direction.y = -cos(((directionDegree)/360)*2*M_PI);
        printf("%f    %f\n", this->direction.x, this->direction.y);   
    default:
        break;
    }

    //this->asteroid.setPosition(static_cast<float>( rand() % static_cast<int>(target->getSize().x - 15)),-50.f);
    //this->direction.x = sin(((directionDegree/360)*2*M_PI));
    //this->direction.y = -cos(((directionDegree)/360)*2*M_PI);
    //printf("%d\n", this->spawnSide);
}

Asteroids::~Asteroids() {}

//Functions

sf::CircleShape Asteroids::getAsteriod() 
{
    return this->asteroid;
}

void Asteroids::updatePos() 
{   
    switch (this->spawnSide)
    {
    case TOP :
        this->asteroid.move(sf::Vector2f(this->direction.x * this->speed, -this->direction.y * this->speed));
        break;
    case DOWN :
        this->asteroid.move(sf::Vector2f(this->direction.x * this->speed, this->direction.y * this->speed));
        break;
    case LEFT :
        this->asteroid.move(sf::Vector2f(this->direction.x * this->speed, this->direction.y * this->speed));
        break;
    case RIGHT :
        this->asteroid.move(sf::Vector2f(-this->direction.x * this->speed, this->direction.y * this->speed));
        break;
    default:
        break;
    }
    //this->asteroid.move(sf::Vector2f(this->direction.x * this->speed, -this->direction.y * this->speed));
  //  printf("%f  ,  %f\n", direction.x, direction.y);
}

void Asteroids::setVariables() 
{
    this->asteroid.setRadius(30);
    this->asteroid.setFillColor(sf::Color::Yellow);
}

