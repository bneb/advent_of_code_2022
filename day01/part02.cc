// See https://adventofcode.com/2022/day/1 for the prompt.

#include <iostream>
#include <string.h>
#include <set>

int main(int argc, char** argv) {
    int64_t cur_pack = 0;
    std::string cal_str;
    int n_top_packs = 1;

    if (argc > 1) {
        n_top_packs = std::stoi(argv[1]);
    }

    std::set<int64_t, std::greater<int64_t>> cal_counts;

    while (std::cin) {
        if (std::getline(std::cin, cal_str) && cal_str.length() > 0) {
            // Accumulate cur_pack for consecutive cal_strs.
            cur_pack += std::stoi(cal_str);
        } else {
            // Upon a blank line or end of file, store pack calories
            cal_counts.insert(cur_pack);
            // and reset the cur_pack accumulator.
            cur_pack = 0;
        }
    }

    int64_t top_n_packs_sum = 0;
    std::cout << "The total calories in the top " << n_top_packs;
    for (auto cals : cal_counts) {
        if (n_top_packs <= 0) break;
        top_n_packs_sum += cals;
        n_top_packs--;
    }
    std::cout << " packs is " << top_n_packs_sum << std::endl;
}
