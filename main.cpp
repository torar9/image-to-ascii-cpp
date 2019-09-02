#include <iostream>
#include <string>
#include <fstream>
#include "CImg.h"
#include "imageconverter.hpp"
#include "asciiart.hpp"

using namespace std;
using namespace cimg_library;

int main()
{
    ImageConverter con("example.png");//place in debug folder
    con.greyScaleByWeight();
    con.saveEditedImage("result.png");

    AsciiArt ascii;
    string result = ascii.toAscii(con.getEditedImg());

    ofstream out("result.txt");
    out << result;
    out.close();

    return 0;
}