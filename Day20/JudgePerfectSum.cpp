//LC633

#include <math.h>
#include <iostream>

using namespace std;

bool judgeSquareSum(int c)
{
    auto checkPerectSq = [](double n)
    {
        return ((int)sqrt(n)) * ((int)sqrt(n)) == n;
    };

    if (checkPerectSq(c))
        return true;

    int x = (int)(sqrt(c / 2));

    while (x > 0)
    {
        int y = c - x * x;
        if (checkPerectSq(y))
            return true;
        --x;
    }

    return false;
}

int main()
{
    cout << judgeSquareSum(74) << "\n";
}