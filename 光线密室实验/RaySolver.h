#ifndef RAYSOLVER_H
#define RAYSOLVER_H
#include "Vec2.h"
#include <vector>

enum ElemType { MIRROR, PRISM, RECEIVER };

struct OpticalElement {
    ElemType type;
    int id;
    Vec2 pos;
    float angle;
    float w, h;
};

struct RayResult {
    std::vector<Vec2> path;
    int hitReceiverId = -1;
};

struct IntersectResult {
    bool hit = false;
    float t;
    Vec2 point;
    Vec2 normal;
    Vec2 inDir;
};

class RaySolver {
public:
    static IntersectResult raySegmentIntersect(Vec2 origin, Vec2 dir, Vec2 p1, Vec2 p2);
    static Vec2 reflectDir(Vec2 inDir, Vec2 normal);
    static Vec2 refractDir(Vec2 inDir, Vec2 normal, float n1, float n2);
    RayResult traceRay(Vec2 origin, Vec2 dir, const std::vector<OpticalElement>& elements, int depth = 0);
private:
    const int MAX_DEPTH = 8;
};
#endif
