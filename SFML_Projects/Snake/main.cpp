#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

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
    srand(time(0));
    int score = 0;
    string heading = "Right";

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
    text.setFillColor(sf::Color::White);
    text.setPosition(650, 5);

    // Snake Body Block
    sf::RectangleShape rect({25, 25});
    rect.setFillColor(sf::Color::Blue);
    rect.setPosition({100, 100});

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
        if(rect.getGlobalBounds().intersects(food.getGlobalBounds())){
            text.setString("Score: " + std::to_string(++score));
            food.setPosition(rand() % 700, rand() % 500);
        }
        rect.move(x, y);

        // Detect Collision of shape with window's borders. If true closes the window, if not clears the window
        detected_Collision(rect) ? window.close() : window.clear();

        // Window Refresh
        window.draw(food);
        window.draw(rect);
        window.draw(text);
        window.display();
    }
    return 0;
}



// int foodPosX = rand() % 700;
// int foodPosY = rand() % 500;

// food.setPosition(foodPosX, foodPosY);

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

// score += 1;

// window.clear();

