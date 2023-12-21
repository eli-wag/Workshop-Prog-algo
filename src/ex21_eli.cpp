#pragma once
#include <sil/sil.hpp>
#include <iostream>
#include <math.h>
#include <vector>

glm::vec3 color(std::vector<glm::vec3> &vector) // Le nom de la fonction n'est pas clair: en voyant juste "color" je ne sait pas ce que la fonction fait. L'appeler average_color aurait été mieux.
{

    vector[5].r = (vector[0].r + vector[2].r + vector[3].r + vector[4].r + vector[5].r + vector[6].r + vector[7].r + vector[8].r + vector[1].r) / 9;
    vector[5].g = (vector[0].g + vector[2].g + vector[3].g + vector[4].g + vector[5].g + vector[6].g + vector[7].g + vector[8].g + vector[1].g) / 9;
    vector[5].b = (vector[0].b + vector[2].b + vector[3].b + vector[4].b + vector[5].b + vector[6].b + vector[7].b + vector[8].b + vector[1].b) / 9;
    return vector[5];
}

void convolution()
{

    /*EX 21 il y'a deux pixels pas flou*/

    sil::Image image2{"images/logo.png"};
    sil::Image image{image2.width(), image2.height()};

    // std::vector<glm::vec3> stock{};

    for (int x{0}; x < image.width() - 2; x++)
    {
        for (int y{0}; y < image.height() - 2; y++)
        {
            std::vector<glm::vec3> trois_par_trois{};
            trois_par_trois.insert(trois_par_trois.end(), {image2.pixel(x, y),
                                                           image2.pixel(x + 1, y),
                                                           image2.pixel(x + 2, y),
                                                           image2.pixel(x + 2, y + 1), image2.pixel(x + 1, y + 1), // indice du central (1,1)= 5
                                                           image2.pixel(x, y + 1), image2.pixel(x, y + 2),
                                                           image2.pixel(x + 1, y + 2), image2.pixel(x + 2, y + 2)});
            image.pixel(x, y) = color(trois_par_trois);
        }
    }

    image.save("output/ex21.png");
}