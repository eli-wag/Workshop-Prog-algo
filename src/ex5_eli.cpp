#pragma once
#include <sil/sil.hpp>
#include <iostream>

void degrade()
{
    /*EX 5*/
    sil::Image image{300, 200};
    // TODO: modifier l'image
    for (int x{1}; x < image.width(); x++) // Si on ne fait rien quand x == 0, autant commencer la boucle à 1
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = image.pixel(x - 1, y).r + 1.f / image.width(); // Plutôt que de hardcoder une valeur 0.003, exprimez la en fonction des paramètres à disposition. Ainsi le code reste correct même si vous décidez de changer la taille de l'image finale.
            image.pixel(x, y).g = image.pixel(x - 1, y).g + 1.f / image.width();
            image.pixel(x, y).b = image.pixel(x - 1, y).b + 1.f / image.width();
        }
    }
    image.save("output/ex5.png");
}