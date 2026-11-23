#ifndef SCENECONTROLLER_H
#define SCENECONTROLLER_H
#include "RaySolver.h"
#include "Vec2.h"
#include <SFML/Window.hpp>

struct SceneState {
    Vec2 lightSource;
    std::vector<OpticalElement> elements;
    int selectedId = -1;
    bool doorOpen = false;
    RayResult lastRay;
};

class SceneController {
public:
    SceneState state;

    void initLevel();
    Vec2 screenToWorld(sf::Vector2i screenPos);
    int pickElement(Vec2 worldPt);
    void dragElement(OpticalElement& elem, Vec2 worldPt);
    void updateFrame();
    void handleMouseEvent(const sf::Event& event, sf::Vector2i mousePos);
private:
    RaySolver solver;
};
#endif
