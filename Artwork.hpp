#pragma once
#include <string>

class Artwork {
public:
    Artwork() = delete; // disable default constructor. 
    Artwork(std::string artTitle,
            std::string artistFullName,
            int artworkId, 
            std::string artworkMedium,
            double artworkPrice,
            bool soldStatus = false);
    Artwork(const Artwork& other); // copy constructor
    Artwork(Artwork&& other); // move constructor
    void markAsSold();
    void printDetails();

    std::string title;
    std::string artistName;
    int id;
    std::string medium;
    double price;
    bool sold;
};