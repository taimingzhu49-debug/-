#include "Renderer.h"
#include <SFML/Graphics.hpp>

void Renderer::clearBackground(sf::RenderWindow& win) {
    win.clear(sf::Color(30,30,30));
}

void Renderer::drawElement(sf::RenderWindow& win, const OpticalElement& elem, bool receiverLit) {
    // TODO[C]:
    // MIRROR：绘制长条镜面
    // PRISM：绘制三角形棱镜
    // RECEIVER：方框，receiverLit=true 时换成高亮颜色
}

void Renderer::drawLightPath(sf::RenderWindow& win, const std::vector<Vec2>& path) {
    if (path.size() < 2) return;
    // TODO[C]: 循环遍历 path，用 sf::VertexArray 绘制连续线段
    // 推荐黄色光路，可以加上透明度模拟发光效果
}

void Renderer::drawDoor(sf::RenderWindow& win, bool isOpen) {
    // TODO[C]: 绘制门图形；isOpen 为 true 时画开门状态，可以做渐变动画
}

void Renderer::draw(sf::RenderWindow& win, const SceneState& state) {
    clearBackground(win);
    drawDoor(win, state.doorOpen);

    for (auto& el : state.elements) {
        bool lit = state.lastRay.hitReceiverId == el.id && el.type == RECEIVER;
        drawElement(win, el, lit);
    }
    drawLightPath(win, state.lastRay.path);
}
