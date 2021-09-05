#include <vector>
#include <stack>
#include <iostream>

using namespace std;

void printLevels(vector<int> vols, int till) {
    for (int i = 0; i < till; ++i)
        cout << vols[i] << " ";
    cout << "\n";
}

int senpistrap(vector<int> height) {
    int maxval = 0, minval = 0, result = 0;

    for (auto &h: height)
    {
        result -= h;
        maxval = max(maxval, h);
    }

    result += maxval * height.size();

    minval = 0;
    for (int i = 0; i < height.size() && height[i] != maxval; ++i)
    {
        minval = max(minval, height[i]);
        result -= maxval - minval;
    }

    minval = 0;
    for (int i = height.size() - 1; i > 0 && height[i] != maxval; --i)
    {
        minval = max(minval, height[i]);
        result -= maxval - minval;
    }

    return result;
}

// int surelytrap(vector<int> height)
// {
//     int result = 0, leftmax = 0, left2max = 0;
//     vector<int> levelVol((int)1e5, 0);

//     for (int k = 0; k<height.size(); ++k)
//     {
//         if (height[k] >= leftmax)
//         {
//             for (int i = 0; i < leftmax; ++i)
//             {
//                 result += levelVol[i];
//             }
//             // printLevels(levelVol, leftmax);
//             leftmax = height[k];
//             fill(levelVol.begin(), levelVol.begin() + leftmax, 0);
//             left2max = 0;
//         }
//         else
//         {
//             left2max = k != 0 && (height[k] > height[k - 1]) && (left2max < height[k]) ? height[k] : left2max;
//             for (int i = height[k]; i < leftmax; ++i)
//             {
//                 ++levelVol[i];
//             }
//             // printLevels(levelVol, leftmax);
//         }
//     }

//     // printLevels(levelVol, left2max);
//     cout << leftmax << ", " << left2max << "\n";
//     if (height[height.size() - 1] < leftmax)
//     {
//         for (int i = height.size() - 1; i > 0 && height[i] != left2max; --i) {
//             for (int j = height[i]; j < left2max; ++j)
//             {
//                 --levelVol[j];
//             }
//         }
//         // printLevels(levelVol, left2max);

//         for (int i = 0; i < left2max; ++i)
//         {
//             result += levelVol[i];
//         }
//     }

//     return result;
// }

int main()
{
    cout << senpistrap({5, 4, 1, 2}) << '\n';
    return 0;
}
