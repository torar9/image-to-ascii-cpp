#include "asciiart.hpp"

AsciiArt::AsciiArt()
{
    charList = " .'`^\",:;Il!i><~+_-?][}{1)(|\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";//Characters correspondign to pixel value 0-255
    //charList = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
}

std::string AsciiArt::toAscii(CImg<unsigned int> img)
{
    std::string result = "";

    for(unsigned int y = 0; y < img.height(); y += Y_DIM)//
    {
        for(unsigned int x = 0; x < img.width(); x += X_DIM)
        {
            unsigned int avg = 0;
            for(int i = 0; i < Y_DIM; i++)//Cycle through [Y_DIM] dimension within image
            {
                for(int j = 0; j < X_DIM; j++)//Cycle through [X_DIM] dimension within image
                {
                    avg += *img.data(x + j, y + i, 0);
                }
            }
            avg /= (Y_DIM * X_DIM);//Average pixel value
            char chart = assignCharacter(avg);//Get corresponding character for average value of pixels inside [X_DIM]:[Y_DIM] dimension within image
            result += chart;
        }
        result += '\n';
    }

    return result;
}

char AsciiArt::assignCharacter(unsigned int value)
{
    double per_item = (double)255 / charList.size();//Divide equally list for each character inside

    for(unsigned int i = 0; i < charList.size(); i++)
    {
        if((i * per_item) >= value)
        {
            //std::cout << "i: " << i << " |value: " << value << " |char_size: " << charList.size() << " |per_item: " << per_item << " char: " << charList.at(i) << std::endl;
            return charList.at(i);
        }
    }

    return ' ';
}
