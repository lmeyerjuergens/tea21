// main.cpp

#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include "bmp.h"

auto main(int argc, char **argv) -> int {
    std::string filename{DEFAULT_BMP_FILE};
    
    CLI::App app{PROJECT_NAME};
    try {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-f,--file", filename, fmt::format("The filename for the Bitmap, default: {}", filename));
        app.parse(argc, argv);
    } catch (const CLI::ParseError &e) {
        return app.exit(e);
    }

    fmt::println("Hello, {}!", app.get_name());
    fmt::println("The filename to use: {}", filename);

    BMP bmp;
    bmp.read(filename);

    // Convert to grayscale
    bmp.convertToGrayscale();

    // Apply threshold filter
    bmp.applyThresholdFilter(150);

    // Generate ASCII art and save to a file
    bmp.generateAsciiArt("output_ascii_art.txt");

    return 0; /* exit gracefully*/
}
