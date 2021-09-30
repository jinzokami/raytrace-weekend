#include "image.hpp"

Pixel::Pixel(int r, int g, int b, int d) 
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->d = d;
}

Image::Image (int width, int height)
{
    this->width = width;
    this->height = height;
    std::vector<Pixel> pixels = std::vector<Pixel>();
    pixels.reserve(width*height);
}

void Image::to_ppm(std::string filename)
{
    std::string ppm_str;
    char nl[128];
    sprintf(nl, "%d %d\n\0", width, height);
    ppm_str = "P3\n";
    ppm_str.append(nl);

    for (int pixel = 0; pixel < pixels.size(); pixel++)
    {
        sprintf(nl, "%d %d %d\n\0", pixels[pixel].r, pixels[pixel].g, pixels[pixel].b);
        ppm_str.append(nl);
    }

    FILE* file;
    fopen_s(&file, filename.c_str(), "w");
    fputs(ppm_str.c_str(), file);
    fclose(file);
}