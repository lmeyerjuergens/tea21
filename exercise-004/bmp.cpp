#include <fmt/chrono.h>
#include <fmt/format.h>
#include "CLI/CLI.hpp"
#include "bmp.h"

template<typename T>
static void read_value(std::fstream& file, T* value);

BMP::BMP() {
    fmt::println("BMP CTOR");
}

BMP::~BMP() {
    fmt::println("BMP DTOR");
}

bool BMP::read(const std::string& filename) {
    auto ret = false;
    std::fstream input_file(filename, std::ios::binary | std::ios::in);
    if (!input_file.is_open()) {
        fmt::print("Unable to open the file: {}\n", filename);
        return ret;
    }

    // Read the Bitmap File Info Header
    read_value(input_file, &m_fileHeader.bfType);
    read_value(input_file, &m_fileHeader.bfSize);
    read_value(input_file, &m_fileHeader.bfReserved);
    read_value(input_file, &m_fileHeader.bfOffBits);

    // Read the Bitmap Info Header
    read_value(input_file, &m_infoHeader.biSize);
    read_value(input_file, &m_infoHeader.biWidth);
    read_value(input_file, &m_infoHeader.biHeight);
    read_value(input_file, &m_infoHeader.biPlanes);
    read_value(input_file, &m_infoHeader.biBitCount);
    read_value(input_file, &m_infoHeader.biCompression);
    read_value(input_file, &m_infoHeader.biSizeImage);
    read_value(input_file, &m_infoHeader.biXPelsPerMeter);
    read_value(input_file, &m_infoHeader.biYPelsPerMeter);
    read_value(input_file, &m_infoHeader.biClrUsed);
    read_value(input_file, &m_infoHeader.biClrImportant);

    // Read pixel data
    m_pixels.resize(m_infoHeader.biHeight, std::vector<uint8_t>(m_infoHeader.biWidth * 3));
    fmt::println("Height: {}, Width: {}", m_infoHeader.biHeight, m_infoHeader.biWidth);
    for (int i = 0; i < m_infoHeader.biHeight+1; ++i) {
        for (int j = 0; j < m_infoHeader.biWidth+1; ++j) {
            read_value(input_file, &m_pixels[i][j * 3]);
            read_value(input_file, &m_pixels[i][j * 3 + 1]);
            read_value(input_file, &m_pixels[i][j * 3 + 2]);
        }
    }

    m_fileHeader.print();
    return true;
}

bool BMP::write(const std::string& filename) {
    auto ret = false;
    // Implementieren Sie die Funktion, um eine BMP-Datei zu schreiben
    return ret;
}

void BMP::BitmapFileHeader::print() {
    fmt::println("======= The Bitmap File Info Header =======");
    fmt::println("  > The start: {}{}", bfType[0], bfType[1]);
    fmt::println("  > The size in bytes: {}", bfSize);
    fmt::println("  > The offset in bits: {}", bfOffBits);
}

template<typename T>
static void read_value(std::fstream& file, T* value) {
    file.read(reinterpret_cast<char*>(value), sizeof(T));
}

void BMP::convertToGrayscale() {
    for (int i = 0; i < m_infoHeader.biHeight; ++i) {
        for (int j = 0; j < m_infoHeader.biWidth; ++j) {
            uint8_t grayValue = static_cast<uint8_t>(
                (m_pixels[i][j * 3] + m_pixels[i][j * 3 + 1] + m_pixels[i][j * 3 + 2]) / 3);
            m_pixels[i][j * 3] = grayValue;
            m_pixels[i][j * 3 + 1] = grayValue;
            m_pixels[i][j * 3 + 2] = grayValue;
        }
    }
}

void BMP::applyThresholdFilter(uint8_t threshold) {
    for (int i = 0; i < m_infoHeader.biHeight; ++i) {
        for (int j = 0; j < m_infoHeader.biWidth; ++j) {
            uint8_t grayValue = m_pixels[i][j * 3];
            uint8_t binaryValue = (grayValue > threshold) ? 255 : 0;
            m_pixels[i][j * 3] = binaryValue;
            m_pixels[i][j * 3 + 1] = binaryValue;
            m_pixels[i][j * 3 + 2] = binaryValue;
        }
    }
}

void BMP::generateAsciiArt(const std::string& outputFilename) {
    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open the output file: " << outputFilename << std::endl;
        return;
    }

    for (int i = m_infoHeader.biHeight - 1; i >= 0; --i) {
        for (int j = 0; j < m_infoHeader.biWidth; ++j) {
            char asciiChar = (m_pixels[i][j * 3] > 128) ? '#' : ' ';
            outputFile << asciiChar;
        }
        // Füge einen Zeilenumbruch am Ende jeder Zeile hinzu
        outputFile << '\n';
    }

    std::cout << "ASCII art has been generated and saved to: " << outputFilename << std::endl;
}











