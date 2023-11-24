#ifndef TEA21_EXERCISE_004_BMP_H
#define TEA21_EXERCISE_004_BMP_H

#include <string>
#include <vector>  // Include vector header

class BMP {
public:
    BMP();
    ~BMP();
    bool read(const std::string& filename);
    bool write(const std::string& filename);
    void convertToGrayscale();
    void applyThresholdFilter(uint8_t threshold);
    void generateAsciiArt(const std::string& outputFilename);

private:
    struct BitmapFileHeader {
        char bfType[2] = {'X','X'};
        uint32_t bfSize = 0;
        uint32_t bfReserved = 0;
        uint32_t bfOffBits = 0;
        void print();
    };

    struct BitmapInfoHeader {
        uint32_t biSize = 0;
        int32_t biWidth = 0;
        int32_t biHeight = 0;
        uint16_t biPlanes = 0;
        uint16_t biBitCount = 0;
        uint32_t biCompression = 0;
        uint32_t biSizeImage = 0;
        int32_t biXPelsPerMeter = 0;
        int32_t biYPelsPerMeter = 0;
        uint32_t biClrUsed = 0;
        uint32_t biClrImportant = 0;
    };

    struct RGBA {
        uint8_t red = 0;
        uint8_t green = 0;
        uint8_t blue = 0;
        uint8_t alpha = 0;
    };

    BitmapFileHeader m_fileHeader;
    BitmapInfoHeader m_infoHeader;

    // Add the declaration of m_pixels
    std::vector<std::vector<uint8_t>> m_pixels;
};

#endif
