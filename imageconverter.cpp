#include "imageconverter.hpp"

ImageConverter::ImageConverter(std::string name)
{
    originalImg = CImg<unsigned int>(name.c_str());
    editedImg = CImg<unsigned int>(originalImg);//Copy of original image
}

void ImageConverter::saveEditedImage(std::string name, unsigned int bytes_per_pixel)
{
    editedImg.save_png(name.c_str(), bytes_per_pixel);
}

void ImageConverter::printOriginalRGB(std::ostream& stream)
{
    cimg_forXY(originalImg, x, y)
    {
        stream << "R[" << originalImg(x, y, 0) << "]";
        stream << " G[" << originalImg(x, y, 1) << "]";
        stream << " B[" << originalImg(x, y, 2) << "]";
        stream << std::endl;
    }
}

void ImageConverter::printEditedRGB(std::ostream &stream)
{
    cimg_forXY(editedImg, x, y)
    {
        stream << "R[" << (unsigned int)editedImg(x, y, 0) << "]";
        stream << " G[" << (unsigned int)editedImg(x, y, 1) << "]";
        stream << " B[" << (unsigned int)editedImg(x, y, 2) << "]";
        stream << std::endl;
    }
}

void ImageConverter::greyScaleByWeight()
{
    cimg_forXY(originalImg, x, y)
    {
        unsigned int r = originalImg(x, y, 0);
        unsigned int g = originalImg(x, y, 1);
        unsigned int b = originalImg(x, y, 2);
        unsigned int result = (unsigned int)(0.299 * r + 0.587 * g + 0.114 * b);

        editedImg(x, y, 0) = result;//Set the Red value
        editedImg(x, y, 1) = result;//Set the Green value
        editedImg(x, y, 2) = result;//Set the Blue value
    }
}

void ImageConverter::greyScale()
{
    cimg_forXY(originalImg, x, y)
    {
        unsigned int r = originalImg(x, y, 0, 0);//get Red value
        unsigned int g = originalImg(x, y, 0, 1);//get Green value
        unsigned int b = originalImg(x, y, 0, 2);//get Blue value
        unsigned int result = (unsigned int)(0.299 * r + 0.587 * g + 0.114 * b) / 3;

        editedImg(x, y, 0) = result;//Set the Red value
        editedImg(x, y, 1) = result;//Set the Green value
        editedImg(x, y, 2) = result;//Set the Blue value
    }
}

CImg<unsigned int> ImageConverter::getEditedImg()
{
    return editedImg;
}

CImg<unsigned int> ImageConverter::getOriginalImg()
{
    return originalImg;
}
