#include <vector>
#include <set>

using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    // Rabin - Carp algorithm - prime number array.
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    vector<int> sub(9, 1);
    int tmp = 1; // 3,4 = 3 + 1 - 0 = 4

    auto getSub = [](int i, int j)
    {
        return i + (j / 3) - i % 3;
    };

    for (int i = 0; i < 9; ++i)
    {
        if (board[0][i] == '.')
        {
            board[0][i] = '1';
        }
        else if (tmp % primes[board[0][i] - '0'] == 0)
        {
            return false;
        }
        else
        {
            tmp *= primes[board[0][i] - '0'];
            sub[getSub(0, i)] = primes[board[0][i] - '0'];
            board[0][i] = primes[board[0][i] - '0'] + '0';
        }
    }

    for (int i = 1; i < 9; ++i)
    {
        board[i][0] = board[i][0] == '.' ? '1' : primes[board[i][0] - '0'] + '0';
        for (int j = 1; j < 9; ++j)
        {
            if (board[i][j] == '.')
                continue;
            int num = board[i][j] - '0';
            if ((board[i][0] - '0') % primes[num] == 0 || (board[0][j] - '0') % primes[num] == 0 || sub[getSub(i, j)] % primes[num] == 0)
            {
                return false;
            }
            board[i][0] = (board[i][0] - '0') * primes[num] + '0';
            board[0][j] = (board[0][j] - '0') * primes[num] + '0';
            sub[getSub(i, j)] *= primes[num];
        }
    }

    return true;
}