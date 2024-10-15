#include <bits/stdc++.h>

using namespace std;
int a[30][30] = {
    0,
};

vector<vector<int>> solution(int n)
{
    int curr = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!a[i][j])
            {
                a[i][j] = curr;
                curr++;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (!a[j][n - i - 1])
            {
                a[j][n - i - 1] = curr;
                curr++;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (!a[n - i - 1][n - 1 - j])
            {
                a[n - i - 1][n - 1 - j] = curr;
                curr++;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (!a[n - 1 - j][i])
            {
                a[n - 1 - j][i] = curr;
                curr++;
            }
        }
    }
    vector<vector<int>> answer(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            answer[i][j] = a[i][j];
        }
    }
    return answer;
}