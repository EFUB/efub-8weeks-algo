#include <bits/stdc++.h>

using namespace std;

int N, M;
char a[50][50] = {
    'W',
};

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

queue<pair<int, int>> q;

int finalMax = 0;

int bfs(int y, int x)
{

    int visited[50][50] = {
        0,
    };
    int max = 0;

    visited[y][x] = 1;
    q.push(make_pair(y, x));
    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;
            if (visited[ny][nx])
                continue;
            if (a[ny][nx] != 'L')
                continue;

            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }

    // 현 시작점에서 가장 먼 곳일때 최단 거리 찾기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (a[i][j] == 'L')
            {
                if (max < visited[i][j])
                    max = visited[i][j];
            }
        }
    }

    return max - 1;
}

void go()
{
    // 가능한 모든 시작점(육지)에서 모든 육지에 대한 최장거리를 찾기.

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (a[i][j] == 'L')
            {
                int temp = bfs(i, j);
                if (finalMax < temp)
                {
                    finalMax = temp;
                }
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c;
        }
    }

    go();

    cout << finalMax;
}
