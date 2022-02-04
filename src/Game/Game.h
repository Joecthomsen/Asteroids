#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

class Game
{

private:

    sf::Event windowEvent;
    sf::RenderWindow * window;
    sf::VideoMode videoMode;

public:
    //Constructors and deconstructors
    Game();
    ~Game();

    //Input
    void keyboardInput();

    //Functions
    const bool running();
    void update();
    void initWindow();
    void renderWindow();  

};
