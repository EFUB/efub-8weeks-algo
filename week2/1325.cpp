#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10001];
int visited[10001] = {
    0,
};

int cnt = 0;

vector<int> result;

void dfs(int here)
{
    visited[here] = 1;
    cnt++;

    for (int there : adj[here])
    {
        if (!visited[there])
        {
            dfs(there);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;

        adj[B].push_back(A);
    }

    int max = 0;
    for (int j = 1; j <= N; j++)
    {
        dfs(j);
        if (max < cnt)
        {
            result.clear();
            result.push_back(j);
            max = cnt;
        }
        else if (max == cnt)
        {
            result.push_back(j);
        }
        // 초기화
        cnt = 0;
        memset(visited, 0, sizeof(visited));
    }

    sort(result.begin(), result.end());

    for (int i = 0; i < result.size() - 1; i++)
    {
        cout << result[i] << " ";
    }
    cout << result[result.size() - 1];

    return 0;
}