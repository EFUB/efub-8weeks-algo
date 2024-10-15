#include <bits/stdc++.h>

using namespace std;
vector<int> visited(200, 0);
vector<vector<int>> computer;
int N;

void dfs(int here)
{
    visited[here] = 1;
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == 0 && computer[here][i])
            dfs(i);
    }
}

int solution(int n, vector<vector<int>> computers)
{
    computer = computers;
    N = n;
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
            answer++;
        }
    }
    return answer;
}