#include "Gallery.hpp"
#include "Exhibition.hpp"

#include <iostream>
#include <iomanip>



int main() {
    std::cout << std::fixed << std::setprecision(0);

    Artwork sunflowers("Sunflowers", "Vincent van Gogh", 1, "oil painting", 1200000);
    sunflowers.printDetails();

    // copy object example
    Artwork starryNight("Starry Night", "Vincent van Gogh", 2, "oil painting", 1000000);
    Artwork galleryCopy(starryNight); // utilizing copy constructor  

    // move object example
    Artwork artworkForTransfer = std::move(starryNight);
    Artwork auctionTransfer(artworkForTransfer); 
    galleryCopy.printDetails();
    auctionTransfer.printDetails();
    starryNight.printDetails();

    return 0;
}