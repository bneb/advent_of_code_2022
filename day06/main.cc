#include <iostream>
#include <string.h>
#include <unordered_set>

#include "signal_processor.h"

int main(int argc, char **argv)
{
    std::cout << "\\ Day06" << std::endl;

    signal_processor::SignalProcessor signal_processor(4);
    signal_processor::SignalProcessor message_processor(14);

    char c;
    int64_t index = 0;

    while (!std::feof(stdin))
    {
        c = std::getchar();
        index++;
        message_processor.Listen(c);
        if (signal_processor.Listen(c))
        {
            std::cout << " \\  Part01 --- Total points: " << index << std::endl;
            break;
        }
    }
    while (!std::feof(stdin))
    {
        c = std::getchar();
        index++;
        if (message_processor.Listen(c))
        {
            std::cout << "  \\ Part02 --- Total points: " << index << std::endl;
            return 0;
        }
    }
    return 1;
}