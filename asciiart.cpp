#include "asciiart.hpp"

AsciiArt::AsciiArt()
{
    charList = "MNHQ$OC?7>!:-;. ";//Characters corresponding to pixel value in a range: 0-255
}

std::string AsciiArt::toAscii(CImg<unsigned int> img)
{
    std::string result = "";

    for(int y = 0; y < img.height(); y += Y_DIM)
    {
        for(int x = 0; x < img.width(); x += X_DIM)//Cycle through image with [X_DIM]x[Y_DIM] dimension
        {
            int avg = 0;
            for(unsigned int i = 0; i < Y_DIM; i++)//Cycle through [Y_DIM] dimension within image
            {
                for(unsigned int j = 0; j < X_DIM; j++)//Cycle through [X_DIM] dimension within image
                {
                    avg += *img.data((x + j), y + i, 0);
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

char AsciiArt::assignCharacter(int value)
{
    double per_item = 255.0 / charList.size();//Divide equally list for each character inside

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
