#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <AnimatedSprite.h>

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // create some shapes
    sf::CircleShape circle(100.0);
    circle.setPosition(100.0, 300.0);
    circle.setFillColor(sf::Color(100, 250, 50));

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(5);
    triangle.setPosition(600.0, 100.0);

    sf::Texture texture_grass;
    if (!texture_grass.loadFromFile("grass.png")) return 1;
    sf::Sprite grass;
    grass.setTexture(texture_grass);

    sf::Texture texture_guy;
    if(!texture_guy.loadFromFile("guy.png")) return 1;
    sf::Sprite guy;
    guy.setTexture(texture_guy);
    guy.setScale(2., 2.);
    guy.setTextureRect(sf::IntRect(0, 0, 120, 120)); //left, top, width, height
    guy.setPosition(400, 300);

    sf::Texture texture_wall;
    if(!texture_wall.loadFromFile("wall.png")) return 1;
    texture_wall.setRepeated(true);
    sf::Sprite wall;
    wall.setTexture(texture_wall);
    wall.setScale(0.3, 0.3);
    wall.setTextureRect(sf::IntRect(0, 0, 500, 500));

    AnimatedSprite hero("character.png");
    //hero.setScale(2., 2.);
    hero.setScale(-2., 2.);
    //hero.addAnimationFrame(sf::IntRect(  0, 0, 37, 37)); // 1 frame of animation
    //hero.addAnimationFrame(sf::IntRect( 50, 0, 37, 37)); // 1 frame of animation
    //hero.addAnimationFrame(sf::IntRect(100, 0, 37, 37)); // 1 frame of animation
    hero.addAnimationFrame(sf::IntRect(150, 0, 37, 37)); // 1 frame of animation
    hero.addAnimationFrame(sf::IntRect(200, 0, 37, 37)); // 1 frame of animation
    hero.addAnimationFrame(sf::IntRect(250, 0, 37, 37)); // 2 frame
    hero.addAnimationFrame(sf::IntRect(300, 0, 37, 37)); // 3 frame
    hero.addAnimationFrame(sf::IntRect(350, 0, 37, 37)); // 4 frame
    hero.setPosition(400, 400);

    std::vector<const sf::Drawable*> shapes = {
        &circle, &rectangle, &triangle, &guy, &grass, &wall, &hero
    };

    // run the program as long as the window is open
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //
        hero.step(elapsed);
        //hero.move(30*elapsed.asSeconds(), 0);
        hero.move(-30*elapsed.asSeconds(), 0);

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        for (auto& s: shapes)
            window.draw(*s);

        // end the current frame
        window.display();
    }

    return 0;
}
