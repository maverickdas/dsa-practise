//LC84

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int> heights) {
    stack<int> s;
    int n = heights.size();
    int min_on_left[n], min_on_right[n];

    for (int i=0; i<n; i++) {
        int h = heights[i];
        while (!s.empty() && h <= heights[s.top()])
            s.pop();
        if (s.empty())
            min_on_left[i] = -1;
        else
            min_on_left[i] = s.top();
        s.push(i);
    }
    while (!s.empty()) s.pop();

    for (int i=n-1; i>=0; i--) {
        int h = heights[i];
        while (!s.empty() && h <= heights[s.top()])
            s.pop();
        if (s.empty())
            min_on_right[i] = n;
        else
            min_on_right[i] = s.top();
        s.push(i);
    }
    int max_area = 0;
    for (int i=0; i<n; i++) {
        int width = min_on_right[i] - min_on_left[i] - 1;
        max_area = max(max_area, width * heights[i]);

    }
    return max_area;
}

int senpilargestRectangleArea(vector<int> heights)
{
    heights.push_back(0);
    heights.insert(heights.begin(), 0);

    stack<int> s;
    int result = 0, endIndex;

    for (int i = 0; i < heights.size(); ++i)
    {
        endIndex = s.empty() ? 0 : s.top();
        while (!s.empty() && heights[s.top()] >= heights[i])
        {
            result = max(result, heights[s.top()] * (endIndex + 1 - s.top()));
            s.pop();
        }
        s.push(i);
    }

    return result;
}

int sssLargestRectangleArea(vector<int> heights)
{
    // heights.push_back(0);
    stack<int> s;
    int n = heights.size();
    int maxArea = 0;
    for (int i = 0; i < n; ++i)
    {

        while (!s.empty() && heights[s.top()] > heights[i])
        {
            int top = s.top();
            s.pop();
            int last = s.empty() ? -1 : s.top();
            maxArea = max(maxArea, heights[top] * (i - last - 1));
        }

        s.push(i);
    }

    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        int last = s.empty() ? -1 : s.top();
        maxArea = max(maxArea, heights[top] * (n - last - 1));
    }

    return maxArea;
}

int main()
{
    cout << senpilargestRectangleArea({2,1,5,6,2,3}) << '\n';
    return 0;
}