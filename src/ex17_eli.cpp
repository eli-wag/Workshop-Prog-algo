#pragma once
#include <sil/sil.hpp>
#include <iostream>
#include <math.h>
#include <complex>

void fractale()
{
    /*Ex 17*/

    sil::Image image{500, 500};

    for (size_t x = 0; x < image.width(); x++)
    {
        for (size_t y = 0; y < image.height(); y++)
        {
            float x_to_two = x / static_cast<float>(image.width()) * 4 - 2; // On préférer utiliser static_cast pour changer le type d'une variable.
            float y_to_two = y / static_cast<float>(image.height()) * 4 - 2;

            std::complex<float> c{x_to_two, y_to_two};
            std::complex<float> z{0, 0};

            int count{0};

            while (count <= 50)
            {
                z = z * z + c;

                if (std::abs(z) > 2)
                {

                    image.pixel(x, y) = glm::vec3{0};

                    break;
                }
                else
                {
                    image.pixel(x, y) = glm::vec3{1};
                }

                count++;
            }
        }
    }
    image.save("output/ex17.png");
}