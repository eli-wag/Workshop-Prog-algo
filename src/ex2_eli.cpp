#pragma once
#include <sil/sil.hpp>
#include <iostream>

void echangeCanaux()
{
    /*EX 2*/
    sil::Image image{"images/logo.png"};
    float x{}; // Pas besoin de créer un vec3 si vous n'utilisez que la composante R de ce vec3
    // TODO: modifier l'image
    for (glm::vec3 &color : image.pixels())
    {

        x = color.r;
        color.r = color.b;
        color.b = x;
    }
    image.save("output/ex2.png");
}