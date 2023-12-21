//EX 17 : tramage

// Vous pouvez lire ce super article sur le tramage (a.k.a. dithering en anglais).

// Sur l'image ci-dessus j'ai utilisé de l'ordered dithering avec une matrice de
// Bayer 4x4 (a.k.a. de niveau 1). Tout est expliqué dans l'article ci-dessus !
// (Plus précisément, j'ai repris la matrice et le code depuis cet autre article.)

#include <iostream>
#include <sil/sil.hpp>
#include "random.hpp"
#include <math.h>

int main()
{
    // sil::Image image{"images/logo.png"};
    sil::Image image{"images/photo.jpg"};
    image.save("output/ex19_tramage.png");
    for (int x{0}; x < image.width() - 1; x++) //on parcourt la taille de l'image2
    {
        for (int y{0}; y < image.height() - 1; y++)
        {
            if (image.pixel(x, y) != glm::vec3{0.0} || image.pixel(x, y) != glm::vec3{1.0})
            {
                float nuance_gris = (image.pixel(x, y).r + image.pixel(x, y).g + image.pixel(x, y).b) / 3;

                int index = random_int(0, 10); //on choisit un nombre random entre 0 et 10 inclus. Il definira l'index a choisir dans le tableau de propabilite de la nouvelle couleur du pixel.

                if (nuance_gris < 0.1 && nuance_gris > 0.0) //si le nuance de gris est de 0.1 alors il va y aoir plus de chance que le pixel noir ou blanc soit noir => on lui donne presque 90% de chance
                {
                    // Autre manière d'obtenir blanc avec 9% de chance:
                    // Cette méthode a l'avantage de pouvoir choisir n'importe quelle probabilité facilement, sans avoir à faire des tableaux "probabilite" à rallonge ^^
                    bool const should_be_white{random_float(0.f, 100.f) < 9};
                    if(should_be_white)
                        image.pixel(x, y) = glm::vec3{1.f};
                    else
                        image.pixel(x, y) = glm::vec3{0.f};
                }
                if (nuance_gris < 0.2 && nuance_gris >= 0.1)
                {
                    std::vector<float> probabilite{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0}; // environ 18% de chance que le pixel soit blanc
                    image.pixel(x, y) = glm::vec3{probabilite[index]};
                }
                if (nuance_gris < 0.3 && nuance_gris >= 0.2)
                {
                    std::vector<float> probabilite{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0}; // environ 25% de chance que le pixel soit blanc
                    image.pixel(x, y) = glm::vec3{probabilite[index]};
                }
                if (nuance_gris < 0.4 && nuance_gris >= 0.3)
                {
                    std::vector<float> probabilite{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0}; //environ 34% de chance que le pixel soit blanc
                    image.pixel(x, y) = glm::vec3{probabilite[index]};
                }
                if (nuance_gris < 0.5 && nuance_gris >= 0.4)
                {
                    std::vector<float> probabilite{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0}; // environ 43% de chance que le pixel soit blanc
                    image.pixel(x, y) = glm::vec3{probabilite[index]};
                }
                if (nuance_gris < 0.6 && nuance_gris >= 0.5)
                {
                    std::vector<float> probabilite{0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}; // environ 52% de chance que le pixel soit blanc
                    image.pixel(x, y) = glm::vec3{probabilite[index]};
                }
                if (nuance_gris < 0.7 && nuance_gris >= 0.6)
                {
                    std::vector<float> probabilite{0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}; // environ 61% de chance que le pixel soit blanc
                    image.pixel(x, y) = glm::vec3{probabilite[index]};
                }
                if (nuance_gris < 0.8 && nuance_gris >= 0.7)
                {
                    std::vector<float> probabilite{0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}; // environ 70% de chance que le pixel soit blanc
                    image.pixel(x, y) = glm::vec3{probabilite[index]};
                }
                if (nuance_gris < 0.9 && nuance_gris >= 0.8)
                {
                    std::vector<float> probabilite{0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}; // environ 79% de chance que le pixel soit blanc
                    image.pixel(x, y) = glm::vec3{probabilite[index]};
                }
                if (nuance_gris < 1.0 && nuance_gris >= 0.9)
                {
                    std::vector<float> probabilite{0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}; // environ 88% de chance que le pixel soit blanc
                    image.pixel(x, y) = glm::vec3{probabilite[index]};
                }
            }
        }
    }
    // image.save("output/ex19_tramage_logo.png");
    image.save("output/ex19_tramage_photo.jpg");
    return 0;
}