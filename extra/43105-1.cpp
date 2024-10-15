#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;

int solution(vector<vector<int>> triangle)
{
    n = triangle.size();
    vector<vector<int>> dp = triangle;
    dp[0][0] = triangle[0][0];
    dp[1][0] = triangle[0][0] + triangle[1][0];
    dp[1][1] = triangle[0][0] + triangle[1][1];

    for (int i = 2; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = max(dp[i - 1][j - 1] + triangle[i][j], dp[i - 1][j] + triangle[i][j]);
        }
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }

    int answer = dp[n - 1][0];
    for (int i = 1; i < n; i++)
    {
        answer = max(answer, dp[n - 1][i]);
    }

    return answer;
}