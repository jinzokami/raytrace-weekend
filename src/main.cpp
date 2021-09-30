#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>

#include "vec3.hpp"
#include "image.hpp"

//type: can be 0(sphere), 1(box), 2(plane)
//pos: coords in 3d
//arg: arg.x is radius(sphere) or width(box), arg.y is height(box), arg.z is depth(box)

struct SceneObject {
    int type = 0;
    vec3 pos;
    vec3 arg;

    SceneObject(int type, double x, double y, double z){
        this->pos = vec3(x, y, z);
    };

    SceneObject(int type, double x, double y, double z, double arg1, double arg2, double arg3){
        this->pos = vec3(x, y, z);
        this->arg = vec3(arg1, arg2, arg3);
    };
};

struct Scene {
    std::vector<SceneObject> objs;

    void add_object(SceneObject obj) {
        this->objs.emplace_back(obj);
    }
};

Pixel eye_cancer(int x, int y)
{
    return Pixel(x%256, y%256, 0, 0);
}

void render_scene(Image& img, const Scene& scene)
{
    for (int y = 0; y < img.height; y++)
    {
        for (int x = 0; x < img.width; x++)
        {
            img.pixels.emplace_back(eye_cancer(x, y));
        }
    }
}

int main (int argc, char** argv)
{
    Image img(atoi(argv[2]), atoi(argv[3]));
    Scene scene;
    render_scene(img, scene);

    std::string out_name = "";
    out_name.append(argv[1]);
    out_name.append(".ppm");
    img.to_ppm(out_name);
    
    return 0;
}