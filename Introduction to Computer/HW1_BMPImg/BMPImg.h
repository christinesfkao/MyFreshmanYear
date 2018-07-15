#ifndef __BMPIMG_H__
#define __BMPIMG_H__

#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<fstream>

using namespace std;

static const int headerNum = 15;
static const int headerSize[headerNum] = {2,4,4,4,4,4,4,2,2,4,4,4,4,4,4};
static const string headerInfo[headerNum]
    = {"Identifier","FileSize","Reserved","BitmapDataOffset",
       "BitmapHeaderSize","Width","Height","Planes",
       "BitsPerPixel","Compression","BitmapDataSize","H_Resolution",
       "V_Resolution","UsedColors","ImportantColors"};

class BMPHead
{
private:
    char Identifier[2];
    unsigned int    FileSize;
    unsigned int    Reserved;
    unsigned int    BitmapDataOffset;
    unsigned int    BitmapHeaderSize;
    unsigned int    Width;
    unsigned int    Height;
    unsigned short  Planes;
    unsigned short  BitsPerPixel;
    unsigned int    Compression;
    unsigned int    BitmapDataSize;
    unsigned int    H_Resolution;
    unsigned int    V_Resolution;
    unsigned int    UsedColors;
    unsigned int    ImportantColors;

public:
    friend class BMPImg;
    void* pFlag(const int i)const
    // usage of this function will be demonstrated later
    // in other functions of class BMPImg
    // which is the reason why it is declared as a pointer function
	{  //return pointers of flags according to its order(int)
        switch(i)
		{
        default:
        case  0:    return (void*)Identifier; // return the char directly
        case  1:    return (void*)&FileSize;  // return the value save in the addresses of...
        case  2:    return (void*)&Reserved;
        case  3:    return (void*)&BitmapDataOffset;
        case  4:    return (void*)&BitmapHeaderSize;
        case  5:    return (void*)&Width;
        case  6:    return (void*)&Height;
        case  7:    return (void*)&Planes;
        case  8:    return (void*)&BitsPerPixel;
        case  9:    return (void*)&Compression;
        case 10:    return (void*)&BitmapDataSize;
        case 11:    return (void*)&H_Resolution;
        case 12:    return (void*)&V_Resolution;
        case 13:    return (void*)&UsedColors;
        case 14:    return (void*)&ImportantColors;
        }
    }
};

class BMPImg
{
private:
    BMPHead header;
public:
    unsigned char* data;
	// used for temporary data saving (RGB conversion)
    int getWidth()const{return header.Width;}
    int getHeight()const{return header.Height;}
    int getPxlNum()const{return header.Width * header.Height;}
    int getBytesPerPixel()const{return header.BitsPerPixel/8;} // 1 byte = 8 bits

    BMPImg(){} //empty default constructor
    BMPImg(const string& picPath)
	// constructor, offering name of the desired file
	{
		loadPic(picPath);
	}
    ~BMPImg(){delete [] data;}
	//destructor, deleting the dynamic-allocated locations for storing "data"

    bool loadPic(const string& picPath)
	{
		ifstream fin; //class object
		fin.open(picPath.c_str(), ios::in|ios::binary);

		for (int a = 0; a <= 14; a++)
			fin.read((char*)header.pFlag(a), headerSize[a]);

		data = new unsigned char [getBytesPerPixel() * getPxlNum()]; //size of pic known

        fin.read((char*)data,getBytesPerPixel() * getPxlNum() );

		fin.close();

		return true;
	}

    void printHeader()const
	{
        for(int i=0;i<headerNum;++i)
		{
            cout<< headerInfo[i]+":";

            if(i==0)
			{
                cout<< header.Identifier[0] << header.Identifier[1];
				// consecutively output the two "digits" of the char "Identifier"
				// i.e. "B", "M"
            }
			else
			{
                if(headerSize[i]==4)
                    cout<< *(  (unsigned int*)(header.pFlag(i))  );
                else // for cases 1, 2, 3, 5, 6, 7, ..., 15
                    cout<< *(  (unsigned short*)(header.pFlag(i))  );
            }
            cout<< endl;
        }
    }
    bool RGBtoY() // working with "data"
    {
		for (unsigned int i = 0; i < (getBytesPerPixel() * getPxlNum()); i++)
		{
			switch(i % 3)
			{// the order for storage is reversed
				case 0:	data[i] *= 0.114; //B
				case 1: data[i] *= 0.587; //G
				case 2: data[i] *= 0.299; //R
			}
		}

		for (unsigned int j = 0; j < (getBytesPerPixel() * getPxlNum()); j++)//Y=0.299R+0.587G+0.114B
		{
			if (j % 3 == 0)
			{
				data[j] = data[j] + data[j+1] + data[j+2];
				data[j+1] = data[j];
				data[j+2] = data[j];
			}
		}

		return true;
	}
    /*bool bpp24to16()
    {
        for (unsigned int a = 0; a < ; a++)
        {

        }
    }*/
     // bonus
    bool storePic(const string& outPath)
	{
		ofstream fout;
		fout.open(outPath.c_str(), ios::out|ios::binary);

		for (int a = 0; a <= 14; a++)
			fout.write((char*)header.pFlag(a), headerSize[a]);

        fout.write((char*)data, getBytesPerPixel() * getPxlNum());
		fout.close();

		return true;
	}
};

#endif // __BMPIMG_H__
