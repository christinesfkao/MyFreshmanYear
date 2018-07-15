#include<iostream>
#include<string>
#include<fstream>

#include "BMPImg.h"

using namespace std;

int main()
{
    BMPImg img;
    img.loadPic("liver.bmp");
    img.storePic("result1.bmp");
    img.RGBtoY();
    img.storePic("result2.bmp");
    return 0;
}
