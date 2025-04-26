#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string positionChanger(float &x, float &y, float x1, float y1, string dir){
    x = x1;
    y = y1;
    return dir;
}

void print(float time){
    std::cout << time << endl;
}

int main(){
    srand(time(0));
    int score = 0;
    string heading = "Right";
    int foodPosX = rand() % 700;
    int foodPosY = rand() % 500;
    float x = .1;
    float y = 0;

    // Rendering a window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Snake");

    // Scorecard
    sf::Font font;
    font.loadFromFile("Movistar_Text_Regular.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString("Score: " + std::to_string(score));
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(650, 5);

    // Snake Body Block

    pmr::vector<sf::RectangleShape> rects;
    sf::RectangleShape rect({25, 25});
    rect.setFillColor(sf::Color::Blue);
    rect.setPosition({100, 100});
    rects.push_back(rect);

    sf::RectangleShape food({25, 25});
    food.setFillColor(sf::Color::Red);
    food.setPosition(foodPosX, foodPosY);
    sf::Event event;

    // Event Loop
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        // KeyPressed Events - Move up, down, left, right
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            heading = (heading!= "Down") ? positionChanger(x, y, 0, -0.1, "Up") : "Down";
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            heading = (heading != "Up") ? positionChanger(x, y, 0, 0.1, "Down") : "Up";
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            heading = (heading != "Right") ? positionChanger(x, y, -0.1, 0, "Left") : "Right";
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            heading = (heading != "Left") ? heading = positionChanger(x, y, 0.1, 0, "Right") : "Left";
        }

        // Detect collision
        if(rects.at(0).getGlobalBounds().intersects(food.getGlobalBounds())){
            // score += 1;
            text.setString("Score: " + std::to_string(++score));
            food.setPosition(rand() % 700, rand() % 500);
            // sf::RectangleShape rect1({25, 25});
            // rect1.setFillColor(sf::Color::Blue);
            // rect1.setPosition({rect.getPosition()});
            // window.clear();
            // window.draw(rect1);
        }
        rects.at(0).move(x, y);

        // Window Refresh
        window.clear();
        window.draw(food);
        window.draw(rects.at(0));
        window.draw(text);
        window.display();
    }
    return 0;
}



// if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
//     if (heading != "Down") {
//         positionChanger(x, y, 0, -0.1);
//         heading = "Up";
//     }
// }

// if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
//     if (heading != "Up") {
//         x = 0, y = 0.1;
//         heading = "Down";
//     }
// }
// if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
//     if (heading != "Right") {
//         x = -0.1, y = 0;
//         heading = "Left";
//     }
// }
// if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
//     if (heading != "Left") {
//         x = 0.1, y = 0;
//         heading = "Right";
//     }
// }
