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

    // new objects for gallery
    Artwork theScream("The Scream", "Edvard Munch", 3, "tempera", 1500000);
    Artwork digitalDream("Digital Dream", "Alice Doe", 4, "digital art", 5000);

    Gallery gallery;
    gallery.addArtwork(std::move(sunflowers));
    gallery.addArtwork(std::move(theScream));
    gallery.addArtwork(std::move(digitalDream));
    gallery.displayGallery();

    // Exhibition
    Exhibition exhibition; 
    

    return 0;
}