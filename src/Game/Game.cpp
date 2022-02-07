#include "Game.h"

//Constructors and deconstructors
Game::Game() 
{
    //this->player = Player(200, 200);
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
    -Update the speed of the player
    -Update the actuarl position
*/
    this->player.move();
    this->player.setPosition();
    //printf("%f   %f\n",this->player.getPlayer().getPosition().x, this->player.getPlayer().getPosition().y);
}


//Keyboard input
void Game::keyboardInput() {
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
}

const bool Game::running() {
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
    this->window->clear();
    this->window->draw(this->player.getPlayer());   
    this->window->display(); 
}
