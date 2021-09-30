#include <vector>

#include "vec3.hpp"
#include "image.hpp"

//type: can be 0(sphere), 1(box), 2(plane)
//pos: coords in 3d
//arg: arg.x is radius(sphere) or width(box), arg.y is height(box), arg.z is depth(box)

struct SceneObject {
    int type = 0;
    vec3 pos;
    vec3 arg;

    SceneObject(int type, double x, double y, double z);

    SceneObject(int type, double x, double y, double z, double arg1, double arg2, double arg3);
};

struct Scene {
    std::vector<SceneObject> objs;

    Scene();

    void add_object(SceneObject obj);
};
