#pragma once
#include <sil/sil.hpp>
#include <iostream>
#include <math.h>
#include "random.hpp"
#include <cstdlib> // std::rand & std::srand
#include <ctime>   // std::time

float brightness(glm::vec3 const&color) // TRES IMPORTANT Quand on passe par & sans const, ça indique qu'on souhaite modifier la variable d'origine. Si ce n'est pas le cas, il faut utiliser const&, ou rien du tout (aka passage par copie). Pour les petits objets (int, float, double, bool, etc.) on préférera la copie, et pour les gros objets (std::vector, std::string, etc.) la const&
{
    return color.r + color.b + color.g;
}

void triPixels()
{

    /*EX 25*/
    sil::Image image{"images/logo.png"};

    sil::Image minirectangle{30, 2};

    for (int l{0}; l < 50; l++)
    {

        int const randomx{random_int(0, image.width() - 1)};
        int const randomy{random_int(0, image.height() - 1)};

        for (int x{0}; x < minirectangle.width(); x++)
        {
            for (int y{0}; y < minirectangle.height(); y++)
            {
                if (randomx + x < image.width() && randomy + y < image.height())
                {
                    minirectangle.pixel(x, y) = image.pixel(randomx + x, randomy + y);
                }
                glm::vec3 color1 = image.pixel(x, y);

                glm::vec3 color2 = image.pixel(x + 1, y);

                std::sort(minirectangle.pixels().begin(), minirectangle.pixels().end(), [](glm::vec3 &color1, glm::vec3 &color2)
                          { return brightness(color1) < brightness(color2); });
            }
        }
        for (int i{0}; i < 15; i++)
        {

            int const randomxLogo{random_int(randomx, randomx + 50)};
            int const randomyLogo{random_int(randomy, randomy + 25)};
            for (int x{0}; x < minirectangle.width(); x++)
            {
                for (int y{0}; y < minirectangle.height(); y++)
                {
                    if (randomxLogo + x < image.width() && randomyLogo + y < image.height())
                    {
                        std::swap(image.pixel(randomxLogo + x, randomyLogo + y), minirectangle.pixel(x, y));
                    }
                }
            }
        }
    }

    image.save("output/ex25.png");
}