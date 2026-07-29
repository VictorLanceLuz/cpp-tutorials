#pragma once

#include "Artwork.hpp"
#include <vector>

class Gallery {
public:
    std::vector<Artwork> artworks;
    
    void addArtwork(Artwork&& art); // move
    void sellArtwork(int id);
    void displayGallery() const;

    Gallery() = default; // default constructor. 
    Gallery(const Gallery&) = delete; // remove the parameter 'other' for conciseness.

};