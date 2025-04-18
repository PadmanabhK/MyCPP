// In Progress

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Thread.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace std;

int printPosition(sf::RectangleShape &rect, sf::CircleShape food){
    int a = rect.getPosition().x;
    int b = rect.getPosition().y;

    int c = food.getPosition().x;
    int d = food.getPosition().y;

    if ( 1 > (c - a) && -1 < (c - a) ){
        return 1;
    }
    return 0;
}

int main(){
    srand(time(0));
    string direction = "Right";
    int x, y;
    int a, b;
    int coll = 0;
    sf::RenderWindow window(sf::VideoMode({1000, 800}), "SNAKE GAME");
    sf::RectangleShape rect({50, 50});

    sf::CircleShape food(20.f);
    food.setFillColor(sf::Color::Red);
    food.setPosition({100, 100});
    rect.setPosition({300, 300});
    rect.setFillColor(sf::Color::Blue);

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        coll = printPosition(rect, food);
        if (coll == 1) {
            a = rand() % 800;
            b = rand() % 600;
            food.setPosition(a, b);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            if(direction != "L"){
                direction = "R";
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            if(direction != "R"){
                direction = "L";
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            if(direction != "B"){
                direction = "U";
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            if(direction != "U"){
                direction = "B";
            }
        }

        if(direction == "R"){rect.setPosition(rect.getPosition().x + .20, rect.getPosition().y);}
        if(direction == "L"){rect.setPosition(rect.getPosition().x - .20, rect.getPosition().y);}
        if(direction == "U"){rect.setPosition(rect.getPosition().x, rect.getPosition().y-.20);}
        if(direction == "B"){rect.setPosition(rect.getPosition().x, rect.getPosition().y+.20);}

        window.clear();
        window.draw(food);
        window.draw(rect);
        window.display();
    }
    return 0;
}
