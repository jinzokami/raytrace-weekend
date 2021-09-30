#pragma once

#include <iostream>
#include <cstdio>
#include <vector>

struct Pixel {
    int r, g, b, d;
    Pixel(int r, int g, int b, int d);
};

struct Image {
    Image (int width, int height);
    int width, height;
    std::vector<Pixel> pixels;

    void to_ppm(std::string filename);
};