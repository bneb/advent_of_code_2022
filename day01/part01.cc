// See https://adventofcode.com/2022/day/1 for the prompt.

#include <iostream>
#include <string.h>

int main(int argc, char** argv) {
    int64_t max_pack = 0;
    int64_t cur_pack = 0;
    std::string cal_str;

    while (std::cin) {
        if (std::getline(std::cin, cal_str) && cal_str.length() > 0) {
            // Accumulate cur_pack for consecutive cal_strs.
            cur_pack += std::stoi(cal_str);
        } else {
            // Upon a blank line or end of file, test cur_pack against the max.
            if (cur_pack > max_pack) {
                max_pack = cur_pack;
            }
            // Reset cur_pack after testing.
            cur_pack = 0;
        }
    }
    std::cout << "Max calories in any pack is " << max_pack << std::endl;
}
