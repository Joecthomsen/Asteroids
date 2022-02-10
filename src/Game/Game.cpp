#include "Game.h"

//Constructors and deconstructors
Game::Game() 
{
    this->initWindow();
}
Game::~Game() {}


//Functions
void Game::initWindow() {
/*
    @void
    This fuction initialize and render the window
    - Set the window size
    - Render the window on the monitor
*/
    this->videoMode = sf::VideoMode(800, 800);
    this->window = new sf::RenderWindow(this->videoMode, "Astroids", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
    this->player.renderPlayer(this->window);
}


void Game::update() {
/*
    @void 
    This function updates the players position
    -Take input
    -Update the player position
    -Update the bullet position
    -Check if the bullet is out of bounce, if so, delete it. 
*/
    this->keyboardInput();
    this->player.setPosition();
    if(!this->bulletList.empty())
    {
        for(int index = 0 ; index < bulletList.size() ; index++)
        {
            this->bulletList[index].setPos();
            if(this->bulletList[index].getPos().x > 800 || this->bulletList[index].getPos().x < 0 || this->bulletList[index].getPos().y > 800 || this->bulletList[index].getPos().y < 0)
            {
                this->bulletList.erase(this->bulletList.begin() + index);
            }
        }
    }
    if(this->timerOn)
    {
        this->startTime += 0.1f;
        if(this->startTime > this->bulletDelay){this->startTime = 0.f; this->timerOn = false;}
    }
    //printf("%f\n", this->startTime);

}


//Keyboard input
void Game::keyboardInput() 
{
/*
    @void
    Takes keyboard input from the user
    -Check if there is an input
    -If input ESCAPE close the window
*/
     while (this->window->pollEvent(this->windowEvent))
    {
        switch (this->windowEvent.key.code)
        {
        case sf::Keyboard::Escape :
            this->window->close();
            break;

        default:
            break;
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        this->player.rotateLeft();
    }    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        this->player.rotateRight();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        this->player.setVelocity();
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        if(!this->timerOn)  //Avoid mulitple bullets being spawned
        {
            this->bullet = Weapon(player);
            this->bulletList.push_back(bullet);
            this->timerOn = true;
        }  
    }
}

const bool Game::running() 
{
/*
    @bool
    Check if the window is still open
*/
    return this->window->isOpen();
}

void Game::render() 
{
/*  @Void
    Render the player and the astroids.
    -Clear the old frame
    -Draw the next frame
    -Display the new frame
*/
//Clear new frame
    this->window->clear();
//Draw next frame
    if(!this->bulletList.empty())
    {
         for(int index = 0 ; index < bulletList.size() ; index++)
        {
           this->window->draw(this->bulletList[index].getBullet());
        }
        //this->window->draw(this->bulletList[0].getBullet());
    }
    this->window->draw(this->player.getPlayer());   
//Change frame
    this->window->display(); 
}

/*
bool Game::insideBoarders(Weapon w) {
    
    if(w.getBullet().getPosition().x > 800 || w.getBullet().getPosition().x < 0 || w.getBullet().getPosition().y > 800 || w.getBullet().getPosition().y < 0 )
    {
        return false;
    }
    return true;    
}
*/