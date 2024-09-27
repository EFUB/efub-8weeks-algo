#include <bits/stdc++.h>

using namespace std;

int N;
int a[100][100] = {
    0,
};
int visited[100][100] = {
    0,
};

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};

int limit = 0;

vector<int> result;

void dfs(int y, int x)
{
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= N)
            continue;
        if (visited[ny][nx])
            continue;
        if (a[ny][nx] <= limit)
            continue;

        dfs(ny, nx);
    }
}

void go()
{
    // 가능한 높이 = 1~100
    for (int k = 0; k < 101; k++)
    {
        limit = k;
        int cnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (a[i][j] > limit && visited[i][j] == 0)
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        result.push_back(cnt);
    }
}

int main()
{
    // 입력
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int height;
            cin >> height;
            a[i][j] = height;
        }
    }

    // 높이 별 카운트 세기
    go();

    // 최댓값 찾기
    sort(result.begin(), result.end(), greater<>());
    cout << result[0];

    return 0;
}