#pragma once
#include <sil/sil.hpp>
#include <iostream>

void split()
{
    /*EX 9*/
    sil::Image image{"images/logo.png"};
    sil::Image image2{image.width(), image.height()};

    // En mettant la boucle sur y en premier ça vous évite de la dupliquer 3 fois
    for (int y{0}; y < image.height() - 1; y++)
    {
        for (int x{0}; x < image.width() - 21; x++)
        {
            // Le if ne sert à rien puisque la boucle garantit déjà que x a une valeur valide
            image2.pixel(x, y).b = image.pixel(x + 20, y).b;
        }
        for (int x{0}; x < image.width() - 1; x++)
        {
            image2.pixel(x, y).g = image.pixel(x, y).g;
        }
        for (int x{0}; x < image.width() - 1; x++)
        {
            if (x >= 20)
            {
                image2.pixel(x, y).r = image.pixel(x - 20, y).r;
            }
        }
    }

    image2.save("output/ex9.png");
}