#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Graphics/ResourceLoader.h"
#include "Logic/Galaxy.h"


void updateWindowTitle(sf::RenderWindow& window, sf::Clock& clock, int& frameCount)
{
    static sf::Time previousTime = clock.getElapsedTime();
    sf::Time currentTime = clock.getElapsedTime();
    sf::Time elapsedTime = currentTime - previousTime;

    if (elapsedTime >= sf::seconds(1.0f))
    {
        int fps = frameCount / elapsedTime.asSeconds();
        std::string title = "SFML Window (FPS: " + std::to_string(fps) + ")";
        window.setTitle(title);

        frameCount = 0;
        previousTime = currentTime;
    }

    frameCount++;
}
int main()
{
    Galaxy galaxy;
    // Create a star entity
    Entity starEntity;
    starEntity.addComponent(RenderComponent());
    galaxy.addStar(starEntity);

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Window");

    // Load the animation shipFrames
    std::vector<sf::Texture> shipFrames = ResourceLoader::loadTextures("assets/ships/terron7");
    std::vector<sf::Texture> starFrames = ResourceLoader::loadTextures("assets/stars/StarBlue", "StarBlue_");

    sf::Texture bg = ResourceLoader::loadTexture("assets/backgrounds/bg04.png");


    // Create the animated shipSprite
    sf::Sprite shipSprite;
    shipSprite.setTexture(shipFrames[0]);
    shipSprite.setPosition(200.f, 200.f);

    // Create bg sprite
    sf::Sprite bgSprite;
    bgSprite.setTexture(bg);
    bgSprite.setPosition(0.0f, 0.0f);

    // Create star sprite
    sf::Sprite starSprite;
    starSprite.setTexture(starFrames[0]);
    starSprite.setPosition(300.0f, 100.0f);



    int frameIndex = 0;
    int frameIndexStar = 0;
    sf::Clock clock;
    sf::Time frameTime = sf::seconds(0.05f);
    int frameCount = 0;

    sf::Event event;

    while (window.isOpen())
    {

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update the animated shipSprite
        if (clock.getElapsedTime() >= frameTime)
        {
            galaxy.update();
            frameIndex = (frameIndex + 1) % shipFrames.size();
            frameIndexStar = (frameIndexStar + 1) % starFrames.size();
            shipSprite.setTexture(shipFrames[frameIndex]);
            starSprite.setTexture(starFrames[frameIndexStar]);
            clock.restart();
        }
        // Update the window title with FPS counter
        updateWindowTitle(window, clock, frameCount);

        window.clear();
        window.draw(bgSprite);
        window.draw(starSprite);
        window.draw(shipSprite);

        window.display();


    }

    return 0;
}

//int main() {
//    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML Window", sf::Style::Default);
//    sf::String buffer;
//    sf::CircleShape circleShape(50);
//    circleShape.setFillColor(sf::Color::Red);
//    circleShape.setOutlineColor(sf::Color::White);
//    circleShape.setOutlineThickness(3);
//
//    sf::RectangleShape rectShape(sf::Vector2f(50,50));
//    rectShape.setFillColor(sf::Color::Green);
//    while (window.isOpen()) {
//        // Handle events
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            switch (event.type) {
//                case sf::Event::EventType::Closed:
//                    window.close();
//                    break;
//                default:
//                    break;
//            }
//        }
//
//        //Update scene
//
//        //Render cycle
//        window.clear( sf::Color::Black);
//
//        // render objects
//        window.draw(circleShape);
//        window.draw(rectShape);
//
//        window.display();
//
//    }
//
//    return 0;
//}
