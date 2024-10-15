#include <bits/stdc++.h>

using namespace std;

vector<int> adj[20001];
vector<int> visited(20001, 0);
queue<int> q;

int solution(int n, vector<vector<int>> edge)
{
    for (int i = 0; i < edge.size(); i++)
    {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }

    q.push(1);
    visited[1] = 1;
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (int there : adj[here])
        {
            if (!visited[there])
            {
                q.push(there);
                visited[there] = visited[here] + 1;
            }
        }
    }

    sort(visited.begin(), visited.end(), greater<>());
    int max = visited[0];
    int answer = 0;

    for (int i : visited)
    {
        if (i == max)
        {
            answer++;
        }
        else
        {
            return answer;
        }
    }

    return answer;
}