// hackhack windows.h, do not try at home
#include <stdint.h>
#include "cmdlib.h"
typedef int LONG;
typedef unsigned long ULONG;
typedef unsigned char BYTE;
typedef uint32_t DWORD;
typedef unsigned short WORD;

// __attribute__((packed)) on non-Intel arch may cause some unexpected error, plz be informed.

typedef struct tagBITMAPFILEHEADER
{
    WORD    bfType; // 2  /* Magic identifier */
    DWORD   bfSize; // 4  /* File size in bytes */
    WORD    bfReserved1; // 2
    WORD    bfReserved2; // 2
    DWORD   bfOffBits; // 4 /* Offset to image data, bytes */ 
} __attribute__((packed)) BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER
{
    DWORD    biSize; // 4 /* Header size in bytes */
    LONG     biWidth; // 4 /* Width of image */
    LONG     biHeight; // 4 /* Height of image */
    WORD     biPlanes; // 2 /* Number of colour planes */
    WORD     biBitCount; // 2 /* Bits per pixel */
    DWORD    biCompression; // 4 /* Compression type */
    DWORD    biSizeImage; // 4 /* Image size in bytes */
    LONG     biXPelsPerMeter; // 4
    LONG     biYPelsPerMeter; // 4 /* Pixels per meter */
    DWORD    biClrUsed; // 4 /* Number of colours */ 
    DWORD    biClrImportant; // 4 /* Important colours */ 
} __attribute__((packed)) BITMAPINFOHEADER;

typedef struct tagRGBQUAD
{
    unsigned char    rgbBlue;   
    unsigned char    rgbGreen;
    unsigned char    rgbRed;  
    unsigned char    rgbReserved;
} RGBQUAD;
// for biBitCount is 16/24/32, it may be useless

typedef struct tagRGBTRIPLE {
        BYTE    rgbtBlue;
        BYTE    rgbtGreen;
        BYTE    rgbtRed;
} RGBTRIPLE;

typedef struct
{
        BYTE    b;
        BYTE    g;
        BYTE    r;
} RGB_data; // RGB TYPE, plz also make sure the order