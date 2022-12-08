#include <iostream>
#include <string.h>

#include "part01.h"
#include "part02.h"
#include "parse_input.h"

int main(int argc, char **argv)
{
    std::cout << "\\ Day05" << std::endl;

    std::string input_str;
    parse_input::InputParser parser;

    while (std::cin)
    {
        if (std::getline(std::cin, input_str))
        {
            parser.ParseLine(input_str);
        }
    }

    auto crane = parser.CreateCrane();
    crane.MoveAll();
    auto part1_result = crane.GetTopCrates();
    std::cout << " \\  Part01 - Top crates: " << part1_result << std::endl;
    // std::cout << "  \\ Part02 -  " << "ok" << std::endl;
}