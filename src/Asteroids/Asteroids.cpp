#include <Asteroids.h>

//Constructors and deconstructors

Asteroids::Asteroids() {}

Asteroids::Asteroids(sf::RenderWindow * target) 
{
    
    this->spawnSide = DOWN;
    this->spawnSection = LEFT;
    this->setVariables();

    switch (this->spawnSide)
    {
    case TOP :
        if(this->spawnSection == LEFT)
        {
            this->asteroid.setPosition(static_cast<float>( rand() % static_cast<int>(target->getSize().x * 0.33 - 15)) , -50.f);
            this->directionDegree = static_cast<float>( rand() % static_cast<int>(90));
            this->direction.x = sin(((directionDegree/360)*2*M_PI));
            this->direction.y = -cos(((directionDegree)/360)*2*M_PI);
        }
        else if(this->spawnSection == MIDDEL)
        {
            this->asteroid.setPosition(static_cast<float>( rand() % static_cast<int>(target->getSize().x * 0.33 - 15)) + (rand() % static_cast<int>(target->getSize().x * 0.66 - 15)) , -50.f);
            this->directionDegree = static_cast<float>(45 - rand() % static_cast<int>(90));
            this->direction.x = sin(((directionDegree/360)*2*M_PI));
            this->direction.y = -cos(((directionDegree)/360)*2*M_PI);
        }
        else
        {
            this->asteroid.setPosition(target->getSize().x * 0.66 + rand() % target->getSize().x * 0.33 , -50.f);
            this->directionDegree = static_cast<float>(-1 * rand() % static_cast<int>(90));
            this->direction.x = sin(((directionDegree/360)*2*M_PI));
            this->direction.y = -cos(((directionDegree)/360)*2*M_PI);
        }
        printf("%f    %f\n", this->direction.x, this->direction.y); 
        break;

    case DOWN :

        if(this->spawnSection == LEFT)
        {
            this->asteroid.setPosition(rand() % target->getSize().x * 0.33 , 830.f);
            this->directionDegree = static_cast<float>(-1 * rand() % static_cast<int>(90));
            this->direction.x = -sin(((directionDegree/360)*2*M_PI));
            this->direction.y = cos(((directionDegree)/360)*2*M_PI);
        }
        else if(this->spawnSection == MIDDEL)
        {
            this->asteroid.setPosition(target->getSize().x * 0.33 + rand() % target->getSize().x * 0.33 , 830.f);
            this->directionDegree = static_cast<float>(45 - rand() % static_cast<int>(90));
            this->direction.x = -sin(((directionDegree/360)*2*M_PI));
            this->direction.y = cos(((directionDegree)/360)*2*M_PI);
        }
        else
        {
            this->asteroid.setPosition(target->getSize().x * 0.66 + rand() % target->getSize().x * 0.33 , 830.f);
            this->directionDegree = static_cast<float>(rand() % static_cast<int>(90));
            this->direction.x = -sin(((directionDegree/360)*2*M_PI));
            this->direction.y = cos(((directionDegree)/360)*2*M_PI);
        }
        printf("%f    %f\n", this->direction.x, this->direction.y); 
        break;

    /*
        this->directionDegree = static_cast<float>( rand() % static_cast<int>(110)) - 70;
        this->asteroid.setPosition(static_cast<float>( rand() % static_cast<int>(target->getSize().x - 15)), 830.f);
        this->direction.x = sin(((directionDegree/360)*2*M_PI));
        this->direction.y = -cos(((directionDegree)/360)*2*M_PI);
    */
        printf("%f    %f\n", this->direction.x, this->direction.y); 
        break;
    case LEFT : 
        this->directionDegree = 110 + static_cast<float>( rand() % static_cast<int>(70));
        this->asteroid.setPosition(-30.f, rand() % static_cast<int>(target->getSize().x - 15));
        this->direction.x = sin(((directionDegree)/360)*2*M_PI);
        this->direction.y = -cos(((directionDegree)/360)*2*M_PI);
        printf("%f    %f\n", this->direction.x, this->direction.y);         break;
    case RIGHT :
        //this->directionDegree = 70 + static_cast<float>( rand() % static_cast<int>(98));
        this->directionDegree = 30 - static_cast<float>( rand() % static_cast<int>(60));
        this->asteroid.setPosition(830.f, rand() % static_cast<int>(target->getSize().x - 15));
        //if(directionDegree < 0){this->direction.x = -cos(((directionDegree)/360)*2*M_PI);}
        //else{this->direction.x = cos(((directionDegree)/360)*2*M_PI);}
        this->direction.x = cos(((directionDegree)/360)*2*M_PI);
        this->direction.y = sin(((directionDegree)/360)*2*M_PI);
        //this->direction.x =  sin(((directionDegree)/360)*2*M_PI);
        //this->direction.y = -cos(((directionDegree)/360)*2*M_PI);
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
        //this->asteroid.move(sf::Vector2f(this->direction.x * this->speed, -this->direction.y * this->speed));
        this->asteroid.move(sf::Vector2f(this->direction.x * this->speed, this->speed));
        break;
    case DOWN :
        //this->asteroid.move(sf::Vector2f(this->direction.x * this->speed, this->direction.y * this->speed));
        this->asteroid.move(sf::Vector2f(this->direction.x * this->speed, -this->speed));
        break;
    case LEFT :
        this->asteroid.move(sf::Vector2f(this->speed, this->direction.y * this->speed));
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

