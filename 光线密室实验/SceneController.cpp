#include "SceneController.h"

void SceneController::initLevel() {
    state.lightSource = Vec2(80, 300);
    state.elements.clear();

    // TODO[B]: 在这里配置关卡，新增、修改镜子、接收器、棱镜初始参数
    state.elements.push_back({MIRROR, 1, Vec2(250, 200), 45.f, 80.f, 6.f});
    state.elements.push_back({RECEIVER, 2, Vec2(550, 200), 0.f, 30.f, 30.f});
}

Vec2 SceneController::screenToWorld(sf::Vector2i screenPos) {
    // TODO[B]: 屏幕坐标 -> 世界坐标转换；如果有相机偏移、缩放在这里处理
    return Vec2((float)screenPos.x, (float)screenPos.y);
}

int SceneController::pickElement(Vec2 worldPt) {
    // TODO[B]: 包围盒检测：判断 worldPt 是否落在元件范围内
    return -1;
}

void SceneController::dragElement(OpticalElement& elem, Vec2 worldPt) {
    // TODO[B]: 两种可选逻辑：
    // 1. 平移：elem.pos = worldPt
    // 2. 旋转：根据鼠标相对元件中心角度修改 elem.angle
}

void SceneController::updateFrame() {
    Vec2 lightDir(1, 0.1f);
    state.lastRay = solver.traceRay(state.lightSource, lightDir, state.elements);
    state.doorOpen = (state.lastRay.hitReceiverId != -1);
}

void SceneController::handleMouseEvent(const sf::Event& event, sf::Vector2i mousePos) {
    Vec2 wpt = screenToWorld(mousePos);
    if (event.type == sf::Event::MouseButtonPressed) {
        state.selectedId = pickElement(wpt);
    } else if (event.type == sf::Event::MouseMoved) {
        if (state.selectedId != -1) {
            for (auto& el : state.elements) {
                if (el.id == state.selectedId) {
                    dragElement(el, wpt);
                    break;
                }
            }
        }
    } else if (event.type == sf::Event::MouseButtonReleased) {
        state.selectedId = -1;
    }
}
