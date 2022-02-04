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
}


void Game::update() {
/*
    @void 
    This function updates the game constantly
    -Take keyboard input
*/
    this->keyboardInput();    
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
    return this->window->isOpen();
}
