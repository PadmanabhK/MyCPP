#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>
#include <vector>

using namespace std;

string positionChanger(float &x, float &y, float x1, float y1, string dir){
    x = x1;
    y = y1;
    return dir;
}

bool detected_Collision(sf::RectangleShape &rect){
    return (rect.getPosition().x <= 0 || rect.getPosition().y <= 0 || rect.getPosition().x >= 800 || rect.getPosition().y >= 600);
}

int main(){
    std::vector<sf::RectangleShape> rectangles;
    srand(time(0));
    int score = 0;
    string heading = "Right";
    int i=0;

    int posX, posY;

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
    sf::RectangleShape rect({25, 25});
    rect.setFillColor(sf::Color::Blue);
    rect.setPosition({100, 100});

    sf::RectangleShape rect1({25, 25});
    rect1.setFillColor(sf::Color::Green);
    rect1.setPosition({75, 100});

    sf::RectangleShape rect2({25, 25});
    rect2.setFillColor(sf::Color::Red);
    rect2.setPosition({50, 100});

    rectangles.push_back(rect);
    rectangles.push_back(rect1);
    rectangles.push_back(rect2);

    // Food Block
    sf::CircleShape food(10);
    food.setFillColor(sf::Color::Red);
    food.setPosition(rand() % 700, rand() % 500);
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

        // Detect collision of Moving body and Foods
        if(rectangles.at(0).getGlobalBounds().intersects(food.getGlobalBounds())){
            text.setString("Score: " + std::to_string(++score));
            food.setPosition(rand() % 700, rand() % 500);
        }
        // for(auto& rect : rectangles){
        //     rect.move(x, y);
        // }
        for (int i=(rectangles.size()-1); i >= 1; i--) {
            rectangles.at(i).setPosition(rectangles.at(i-1).getPosition().x + 25, rectangles.at(i-1).getPosition().y);
        }
        rectangles.at(0).move(x, y);
        // Detect Collision of shape with window's borders. If true closes the window, if not clears the window
        detected_Collision(rectangles.at(0)) ? window.close() : window.clear();

        // Window Refresh
        window.draw(food);
        for(auto& rect: rectangles){
            window.draw(rect);
        }
        // window.draw(rect);
        window.draw(text);
        window.display();
    }
    return 0;
}
