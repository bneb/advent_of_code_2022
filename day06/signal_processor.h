#ifndef DAY06_SIGNAL_PROCESSOR_H_
#define DAY06_SIGNAL_PROCESSOR_H_

#include <unordered_map>
#include <vector>

namespace signal_processor
{
    class SignalProcessor
    {
    private:
        std::vector<char> chars_;
        std::unordered_map<char, int> counter_;
        int n_;
        int t_;

        void Clean()
        {
            char old = chars_[t_];
            if (counter_[old] > 1)
            {
                counter_[old]--;
            }
            else
            {
                counter_.erase(old);
            }
        }

    public:
        SignalProcessor(const SignalProcessor &) = delete;
        SignalProcessor &operator=(const SignalProcessor &) = delete;
        ~SignalProcessor() = default;

        SignalProcessor(int n) : n_(n), t_(0) { chars_.reserve(4); }

        bool Listen(char c)
        {
            Clean();
            // Add new char and increment the time period.
            chars_[t_] = c;
            counter_[c]++;
            ++t_ %= n_;
            // Test if we have enougth different chars.
            return counter_.size() == n_;
        }
    };

} // namespace signal_processor

#endif // DAY06_SIGNAL_PROCESSOR_H_