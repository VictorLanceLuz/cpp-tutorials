#include "Gallery.hpp"
#include "Exhibition.hpp"

#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::fixed << std::setprecision(0);

    Artwork sunflowers("Sunflowers", "Vincent van Gogh", 1, "oil painting", 1200000);
    std::cout << "ID: " << sunflowers.id << ", Title: " << sunflowers.title << ", Artist: " << sunflowers.artistName 
    << ", Medium: " << sunflowers.medium << ", Price: " << sunflowers.price << std::endl;

    

    return 0;
}