#include "RaySolver.h"

IntersectResult RaySolver::raySegmentIntersect(Vec2 origin, Vec2 dir, Vec2 p1, Vec2 p2) {
    // TODO[A]: 实现射线-线段求交算法
    // 输出：是否击中、t 参数、交点 point、线段法线 normal、入射方向 inDir
    return {};
}

Vec2 RaySolver::reflectDir(Vec2 inDir, Vec2 normal) {
    // TODO[A]: 反射公式：r = i - 2*(i·n)*n
    return Vec2(0,0);
}

Vec2 RaySolver::refractDir(Vec2 inDir, Vec2 normal, float n1, float n2) {
    // TODO[A]: 实现斯涅尔折射；如果发生全反射，返回反射方向
    return Vec2(0,0);
}

RayResult RaySolver::traceRay(Vec2 origin, Vec2 dir, const std::vector<OpticalElement>& elements, int depth) {
    RayResult res;
    res.path.push_back(origin);
    if (depth > MAX_DEPTH) return res;

    IntersectResult closest;
    OpticalElement hitObj;

    // TODO[A]:
    // 1. 遍历所有光学元件
    // 2. 根据元件类型（镜子/棱镜/接收器）拆成多条边线段
    // 3. 调用 raySegmentIntersect，筛选距离最近的有效交点

    if (!closest.hit) {
        return res;
    }
    res.path.push_back(closest.point);

    // TODO[A]: 分支处理碰撞物体
    // if 接收器：标记 hitReceiverId，终止追踪
    // else if 镜子：算出反射光，递归 traceRay
    // else if 棱镜：算出折射光，递归 traceRay

    return res;
}
