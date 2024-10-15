#include <bits/stdc++.h>

using namespace std;

int N, M;

int a[100][100] = {
    0,
};

int visited[100][100] = {
    0,
};

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int remain = 0;
int border = 0;
int last_border = 0;
int total_time = 0;

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;
        if (visited[ny][nx])
            continue;

        // 가장자리의 치즈라면 0으로 바꾸고 방문처리, 탐색은 이어서 X
        if (a[ny][nx] == 1)
        {
            a[ny][nx] = 0;
            visited[ny][nx] = 1;
            border++;
        }
        else
        {
            // 빈 공간이라면 이어서 탐색
            dfs(ny, nx);
        }
    }
}

void go()
{
    while (1)
    {
        if (remain == 0)
            break;

        dfs(0, 0);
        remain -= border;
        last_border = border;
        border = 0;
        total_time++;
        memset(visited, 0, sizeof(visited));
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int num;
            cin >> num;
            a[i][j] = num;
            if (num)
            {
                remain++;
            }
        }
    }

    go();

    cout << total_time << '\n';
    cout << last_border << '\n';
    return 0;
}