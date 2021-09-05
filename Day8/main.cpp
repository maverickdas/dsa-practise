// LC73

#include <bits/stdc++.h>

using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{

    // to avoid using any external data structure
    // use the Row + Col of any 0 element
    vector<bool> dpRow(matrix.size(), false);
    vector<bool> dpCol(matrix[0].size(), false);

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] == 0)
            {
                dpRow[i] = true;
                dpCol[j] = true;
            }
        }
    }

    int maxlen = max(dpRow.size(), dpCol.size());

    for (int i = 0; i < maxlen; ++i)
    {
        if (i < dpRow.size() && dpRow[i])
        {
            for (int j = 0; j < matrix[0].size(); ++j)
                matrix[i][j] = 0;
        }

        if (i < dpCol.size() && dpCol[i])
        {
            for (int j = 0; j < matrix.size(); ++j)
                matrix[j][i] = 0;
        }
    }
}