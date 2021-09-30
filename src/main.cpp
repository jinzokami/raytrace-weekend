#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>

#include "vec3.hpp"
#include "image.hpp"
#include "scene.hpp"
#include "ray.hpp"

void render_scene(Image& img, const Scene& scene)
{
    double aspect_ratio = img.width/img.height;
    //the range for x axis is -1 to 1
    //the range for y axis is -aspect_ratio/2 to aspect_ratio/2
    double top = aspect_ratio/2;
    double bottom = aspect_ratio/2;
    double left = -1;
    double right = 1;

    double viewplane_distance = 1;

    for (int y = 0; y < img.height; y++)
    {
        double a = y/double(img.height);
        double screen_y = a*top + (1-a)*bottom;
        for (int x = 0; x < img.width; x++)
        {
            double b = x/double(img.width);
            double screen_x = b*left + (1-b)*right;
            vec3 pixel_loc(screen_x, screen_y, viewplane_distance);

            vec3 dir = pixel_loc.normalize();
            img.pixels.emplace_back(int(abs(dir.x*255.0)), int(abs(dir.y*255.0)), int(abs(dir.z*255.0)), 0);
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