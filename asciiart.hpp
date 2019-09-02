#ifndef ASCIIART_HPP
#define ASCIIART_HPP

#include <iostream>
#include <CImg.h>
#include <string>

#define X_DIM 6
#define Y_DIM 10

using namespace cimg_library;

class AsciiArt
{
private:
    std::string charList;

public:
    AsciiArt();
    std::string toAscii(CImg<unsigned int> img);
    char assignCharacter(unsigned int value);
};

#endif // ASCIIART_HPP
