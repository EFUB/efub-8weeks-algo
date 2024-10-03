#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    int h = triangle.size();
    for (int i = h - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            triangle[i][j] = max(triangle[i][j] + triangle[i + 1][j], triangle[i][j] + triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}