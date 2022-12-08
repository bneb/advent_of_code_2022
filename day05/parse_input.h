#ifndef DAY05_PARSE_INPUT_H_
#define DAY05_PARSE_INPUT_H_

#include <map>
#include <memory>
#include <regex>
#include <utility>
#include <vector>

#include "crane.h"
#include "move.h"

namespace parse_input
{
    class InputParser
    {
    public:
        InputParser()
        {
            moves_ = std::make_unique<std::vector<move::Move>>();
            stacks_ = std::make_unique<std::map<int, std::vector<char>>>();
            stacks_complete_ = false;
        }

        // Parse a line of input describing the stack.
        void ParseStackLine(std::string line)
        {
            for (int i = 1; i < line.length(); i += 4)
            {
                char c = line.at(i);
                if ('A' <= c && c <= 'Z')
                    (*stacks_)[(i - 1) / 4 + 1].push_back(c);
            }
        }

        // Parse a line of input describing a Move.
        void ParseMove(std::string line)
        {
            std::regex pattern("^[^\\d]+(\\d+)[^\\d]+(\\d+)[^\\d]+(\\d+)$");
            std::smatch matches;
            std::regex_search(line, matches, pattern);
            const move::Move move = {std::stoi(matches[1]),
                                     std::stoi(matches[2]),
                                     std::stoi(matches[3])};
            moves_->push_back(move);
        }

        // Parse a line of input.
        void ParseLine(std::string line)
        {
            if (line.length() == 0)
                Finish();
            else if (stacks_complete_)
                ParseMove(line);
            else
                ParseStackLine(line);
        }

        crane::Crane CreateCrane()
        {
            return crane::Crane(std::move(stacks_), std::move(moves_));
        }

        const std::map<int, std::vector<char>> GetStack() { return *stacks_; }
        const std::vector<move::Move> GetMoves() { return *moves_; }

    private:
        std::unique_ptr<std::map<int, std::vector<char>>> stacks_;
        std::unique_ptr<std::vector<move::Move>> moves_;
        bool stacks_complete_;

        // Flips flag to start parsing moves. Reverses vectors.
        void Finish()
        {
            stacks_complete_ = true;
            for (auto [k, v] : *stacks_)
            {
                std::reverse(v.begin(), v.end());
                stacks_->insert_or_assign(k, v);
            }
        }
    };
} // namespace parse_input

#endif // DAY05_PARSE_INPUT_H_