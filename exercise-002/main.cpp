#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    auto count = 20;

    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-c,--count", count, fmt::format("Create a vector with a given size default: {}", count));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());
    fmt::print("Count: {}\n", count);

    std::srand(time(NULL));

    std::vector<int> data(count);
    for (int &num : data) {
        num = std::rand() % 100 + 1;
    }
    
    fmt::print("Random Numbers: ");
    for (const int &num : data) {
        fmt::print("{} ", num);
    }
    fmt::print("\n");

    auto start = std::chrono::system_clock::now();

    std::sort(data.begin(), data.end());

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    fmt::print("It took {} to sort Numbers\n", elapsed);

    fmt::print("Sorted Numbers: ");
    for (const int &num : data) {
        fmt::print("{} ", num);
    }

    return 0; /* exit gracefully*/
}
