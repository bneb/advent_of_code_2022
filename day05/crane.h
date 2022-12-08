#ifndef DAY05_CRANE_H_
#define DAY05_CRANE_H_

#include <map>
#include <memory>
#include <vector>

#include "move.h"

namespace crane
{
    class Crane
    {
    public:
        Crane(std::unique_ptr<std::map<int, std::vector<char>>> stacks,
              std::unique_ptr<std::vector<move::Move>> moves)
            : stacks_(std::move(stacks)), moves_(std::move(moves)) {}

        void Move(move::Move move)
        {
            std::vector<char> tmp;
            char c;
            for (int i = 0; i < move.quantity; i++)
            {
                c = stacks_->at(move.from).back();
                stacks_->at(move.from).pop_back();
                tmp.push_back(c);
            }
            std::reverse(tmp.begin(), tmp.end());
            (*stacks_)[move.to].insert(
                (*stacks_)[move.to].end(), tmp.begin(), tmp.end());
        }

        void MoveAll()
        {
            for (auto move : *moves_)
                Move(move);
        }

        std::string GetTopCrates()
        {
            std::vector<char> tops;
            for (auto [k, v] : *stacks_)
            {
                tops.push_back(v.back());
            }
            return std::string(tops.begin(), tops.end());
        }

        const std::map<int, std::vector<char>> GetStacks()
        {
            return *stacks_;
        }

    private:
        std::unique_ptr<std::map<int, std::vector<char>>> stacks_;
        std::unique_ptr<std::vector<move::Move>> moves_;
    };
}

#endif // DAY05_CRANE_H_