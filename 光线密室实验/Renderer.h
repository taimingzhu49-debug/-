#ifndef RENDERER_H
#define RENDERER_H
#include "SceneController.h"
#include <SFML/Graphics.hpp>

class Renderer {
public:
    void draw(sf::RenderWindow& win, const SceneState& state);
private:
    void clearBackground(sf::RenderWindow& win);
    void drawElement(sf::RenderWindow& win, const OpticalElement& elem, bool receiverLit);
    void drawLightPath(sf::RenderWindow& win, const std::vector<Vec2>& path);
    void drawDoor(sf::RenderWindow& win, bool isOpen);
};
#endif
