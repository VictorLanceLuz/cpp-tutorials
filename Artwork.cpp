#include "Artwork.hpp"
#include <iostream>

Artwork::Artwork(std::string artTitle, std::string artistFullName, int artworkId,
    std::string artworkMedium, double artworkPrice, bool soldStatus) 
    : title(artTitle), artistName(artistFullName), id(artworkId),
    medium(artworkMedium), price(artworkPrice), sold(soldStatus) 
{
}

void Artwork::markAsSold()
{
    sold = true;
}