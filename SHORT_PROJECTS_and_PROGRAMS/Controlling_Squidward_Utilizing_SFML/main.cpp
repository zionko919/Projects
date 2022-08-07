/***********************
 SFML: Simple and Fast Multimedia Library

 Description:
 This is a program where you can more around a 
 image of Handsome Squidward inside the program's
 window. It utilizes SFML.
***********************/

#include <SFML/Graphics.hpp>
#include <iostream>

int main() 
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1280,720), "SFML \"Handsome Squidward\" Window by Zion \"Sean\" Ko");

    window.setFramerateLimit(8);  // Set frame rate so the sprite don't move too fast

    // Load a text to disiplay
    sf::Font font;
    if(!font.loadFromFile("arial.ttf")) {
        std::cout << "ERROR! Can't find arial.ttf" << std::endl;
        return EXIT_FAILURE;
    }
    // Set text position, font size, etc.
    sf::Text text("Handsome Squidward Instructions:\n\t1)   ARROW KEYS to move\n\t2)   [ to rotate left\n\t3)   ] to rotate right\n\t4)   / to increase size\n\t5)   . to decrease size\n\t6)   RETURN to reset", font, 20);
    text.move(50, 150);


    // Load a sprite to display
    sf::Texture texture;
    if(!texture.loadFromFile("sprite.png")) {
        std::cout << "ERROR! Can't find sprite.png" << std::endl;
        return EXIT_FAILURE;
    }
    texture.setSmooth(true);    // it smooth out the sprite's texture to make it look nicer
    sf::Sprite sprite(texture);
    
    // Set sprite origin and position
    sprite.setOrigin(150.f, 200.f);
    sprite.setPosition(640, 360);
    sprite.setScale(.75, .75);

    // Load another sprite to display
    sf::Texture texture2;
    if(!texture2.loadFromFile("sprite2.png")) {
        std::cout << "ERROR! Can't find sprite2.png" << std::endl;
        return EXIT_FAILURE;
    }
    texture2.setSmooth(true);    // it smooth out the sprite's texture to make it look nicer
    sf::Sprite sprite2(texture2);

    // sprite2.setOrigin(150.f, 200.f);
    sprite2.setPosition(0, 0);
    sprite2.setScale(.10, .10);

    int num = 1;

    // Start the game loop
    while(window.isOpen()) {
        // process events
        sf::Event event;
        while(window.pollEvent(event)) {
            // close winodw: exit
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // Make sprite move with keyboard input - ARROW KEY (Up, down, left, right)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            sprite.move(0, -12);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            sprite.move(0, 12);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            sprite.move(-12, 0);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            sprite.move(12, 0);
        } 
        
        // Make sprite rotate with keyboard input - L and R Bracket: "[" to rotate left or "]" to rotate right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket)) {
            sprite.rotate(-4.5);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket)) {
            sprite.rotate(4.5);
        } 

        // Make sprite bigger or smaller with keyboard input - Period and Slash: "." to make sprite smaller or "/" to make sprite larger
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period)) {
            sprite.scale(0.95f, 0.95f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Slash)) {
            sprite.scale(1.05f, 1.05f);
        } 

        // Reset sprite to the starting point with keyboard input - Return (enter)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            sprite.setOrigin(150.f, 200.f);
            sprite.setPosition(650, 350);
            sprite.setRotation(0);
            sprite.setScale(.75, .75);
        }

    
        // Moves Sprite2 so it is circling around the window
        switch(num) {
            case 1:
                sprite2.move(1160, 0);
                num++;
                break;

            case 2:
                sprite2.move(0, 585);
                num++;
                break;

            case 3:
                sprite2.move(-1160, 0);
                num++;
                break;

            case 4:
                sprite2.move(0, -585);
                num++;
                break;
            
            default:
                num = 1;
                break;
        }

        // Clear screen
        window.clear();

        // Draw Squidward sprite
        window.draw(sprite);

        // Draw Patrick sprite
        window.draw(sprite2);

        // Draw the text
        window.draw(text);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}