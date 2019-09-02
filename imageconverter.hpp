#ifndef IMAGECONVERTER_HPP
#define IMAGECONVERTER_HPP

#include <string>
#include <iostream>
#include "CImg.h"

using namespace cimg_library;

class ImageConverter
{
public:
    ImageConverter(std::string name);
    void saveEditedImage(std::string name, unsigned int bytes_per_pixel = 3);
    void printOriginalRGB(std::ostream &stream);
    void printEditedRGB(std::ostream &stream);
    void greyScaleByWeight();
    void greyScale();
    CImg<unsigned int> getEditedImg();
    CImg<unsigned int> getOriginalImg();

private:
    CImg<unsigned int> originalImg;
    CImg<unsigned int> editedImg;
};

#endif // IMAGECONVERTER_HPP
