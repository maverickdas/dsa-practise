#include <bits/stdc++.h>
using namespace std;

#define deb(...) std::cout << __func__ << "(" << __LINE__ << "): "; logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(std::string vars, Args&&... values) {
    std::cout << vars << " = ";
    std::string delim = "";
    (..., (std::cout << delim << values, delim = ", "));
}

int main()
{
    int val = 9;
    string v2 = "11";
    deb(val, v2);
    return 0;
}