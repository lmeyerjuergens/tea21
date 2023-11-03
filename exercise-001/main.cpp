#include <fmt/chrono.h>
#include <fmt/format.h>

#include <iostream>
#include <random>

#include "CLI/CLI.hpp"
#include "config.h"


// .bss segment
int bss;
int bss2;

// .data segment
int data = 4711;
int data2 = 1174;

// .rodata segment
const int rodata = 42;
const int rodata2 = 24;

auto main(int argc, char **argv) -> int
{
   
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    
    fmt::print("Value of variable bss {} address of variable bss {}\n", bss, fmt::ptr(&bss));
    fmt::print("Value of variable data {} address of variable data {}\n", data, fmt::ptr(&data));
    fmt::print("Value of variable rodata {} address of variable rodata {}\n", rodata, fmt::ptr(&rodata));
    fmt::print("Value of variable bss {} address of variable bss {}\n", bss2, fmt::ptr(&bss2));
    fmt::print("Value of variable data {} address of variable data {}\n", data2, fmt::ptr(&data2));
    fmt::print("Value of variable rodata {} address of variable rodata {}\n", rodata2, fmt::ptr(&rodata2));

    return 0; /* exit gracefully*/
}
