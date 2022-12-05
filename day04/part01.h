#ifndef DAY04_PART01_H_
#define DAY04_PART01_H_

namespace part01
{
    int DetectFullOverlap(int lLow, int lHigh, int rLow, int rHigh)
    {
        return (lLow <= rLow && lHigh >= rHigh) || (lLow >= rLow && lHigh <= rHigh);
    }
} // namespace part01

#endif // DAY04_PART01_H_