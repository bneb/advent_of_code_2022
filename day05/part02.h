#ifndef DAY05_PART02_H_
#define DAY05_PART02_H_

namespace part02
{
    int DetectPartialOverlap(int lLow, int lHigh, int rLow, int rHigh)
    {
        return (lLow <= rLow && lHigh >= rLow) || (lLow <= rHigh && lHigh >= rHigh);
    }
} // namespace part02

#endif // DAY05_PART02_H_