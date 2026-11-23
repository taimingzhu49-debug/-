#include <SFML/Graphics.hpp>
#include "SceneController.h"
#include "Renderer.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 500), "光线密室");
    SceneController scene;
    Renderer renderer;
    scene.initLevel();

    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) window.close();
            scene.handleMouseEvent(e, sf::Mouse::getPosition(window));
        }
        scene.updateFrame();
        renderer.draw(window, scene.state);
        window.display();
    }
    return 0;
}
