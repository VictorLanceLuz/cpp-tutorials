#include "Artwork.hpp"
#include <iostream>

Artwork::Artwork(std::string artTitle, std::string artistFullName, int artworkId,
    std::string artworkMedium, double artworkPrice, bool soldStatus) 
    : title(artTitle), artistName(artistFullName), id(artworkId),
    medium(artworkMedium), price(artworkPrice), sold(soldStatus) 
{
}

Artwork::Artwork(const Artwork &other)
    : title(other.title), artistName(other.artistName), id(other.id),
    medium(other.medium), price(other.price), sold(other.sold)
{
}

Artwork::Artwork(Artwork &&other)
{
}

void Artwork::markAsSold()
{
    sold = true;
}