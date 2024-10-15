#include <bits/stdc++.h>

using namespace std;

int R, C, K;

int a[5][5] = {
    0,
};

int visited[5][5] = {
    0,
};

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int result = 0;

void dfs(int y, int x, int cnt)
{
    if (cnt == K && y == 0 && x == C - 1)
    {
        result++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= R || nx >= C)
            continue;
        if (a[ny][nx] == 0)
            continue;
        if (visited[ny][nx] == 1)
            continue;

        visited[ny][nx] = 1;
        dfs(ny, nx, cnt + 1);
        visited[ny][nx] = 0; // 방문해제
    }
}

int main()
{

    cin >> R >> C >> K;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char c;
            cin >> c;

            // 갈 수 없는 곳은 0 있는 곳은 1
            if (c == 'T')
            {
                a[i][j] = 0;
            }
            else
            {
                a[i][j] = 1;
            }
        }
    }

    visited[R - 1][0] = 1;
    dfs(R - 1, 0, 1);
    cout << result;
}