#include <bits/stdc++.h>

using namespace std;
int T, N, M, K;

int a[50][50];
int visited[50][50];

vector<int> dy = {-1, 0, 0, 1};
vector<int> dx = {0, 1, -1, 0};

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;
        if (a[ny][nx] == 0)
            continue;
        if (visited[ny][nx] == 1)
            continue;

        dfs(ny, nx);
    }
}

int go()
{
    int cnt = 0;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (a[y][x] == 1 && visited[y][x] == 0)
            {
                dfs(y, x);
                cnt++;
            }
        }
    }

    return cnt;
}
int main()
{
    // 입력
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> M >> N >> K;

        for (int j = 0; j < K; j++)
        {
            int X, Y;
            cin >> X >> Y;
            a[Y][X] = 1;
        }
        cout << go() << "\n";
        // 초기화
        memset(a, 0, sizeof(a));
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}