#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>

#include "vec3.hpp"

struct Pixel {
    int r, g, b, d;
};

struct Image {
    Image (int width, int height) : width(width), height(height) 
    {
        std::vector<Pixel> pixels = std::vector<Pixel>();
        pixels.reserve(width*height);
    }
    int width, height;
    std::vector<Pixel> pixels;

    void to_ppm(std::string filename)
    {
        std::string ppm_str;
        char nl[128];
        sprintf(nl, "%d %d\n\0", this->width, this->height);
        ppm_str = "P3\n";
        ppm_str.append(nl);

        for (int pixel = 0; pixel < this->pixels.size(); pixel++)
        {
            sprintf(nl, "%d %d %d\n\0", this->pixels[pixel].r, this->pixels[pixel].g, this->pixels[pixel].b);
            ppm_str.append(nl);
        }

        FILE* file;
        fopen_s(&file, filename.c_str(), "w");
        fputs(ppm_str.c_str(), file);
        fclose(file);
    }
};
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

    void add_object(SceneObject obj);
};

void eye_cancer(Image& img)
{
    for (int i = 0; i < img.height; i++)
    {
        for (int j = 0; j < img.width; j++)
        {
            img.pixels.emplace_back(Pixel{rand()%128+128, rand()%128+128, rand()%128+128});
        }
    }
}

void render_scene(Image& img, const Scene& scene)
{

}

int main (int argc, char** argv)
{
    Image img(atoi(argv[2]), atoi(argv[3]));
    eye_cancer(img);
    std::string out_name = "";
    out_name.append(argv[1]);
    out_name.append(".ppm");
    img.to_ppm(out_name);
    return 0;
}