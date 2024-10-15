#include <bits/stdc++.h>

using namespace std;
int M, N, K;

int a[100][100] = {
    0,
};

int visited[100][100] = {
    0,
};

int cnt = 0;
int temp_width = 0;
vector<int> width;

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};

void dfs(int y, int x)
{
    temp_width++;
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= M || nx >= N)
            continue;
        if (visited[ny][nx])
            continue;
        if (a[ny][nx])
            continue;

        dfs(ny, nx);
    }
}

void go()
{

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (a[i][j] == 0 && !visited[i][j])
            {
                dfs(i, j);
                width.push_back(temp_width);
                temp_width = 0;
                cnt++;
            }
        }
    }
}

void fill(int xl, int yl, int xr, int yr)
{

    for (int y = yl; y < yr; y++)
    {
        for (int x = xl; x < xr; x++)
        {
            a[y][x] = 1;
        }
    }
}
int main()
{
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++)
    {
        int xl, yl, xr, yr;
        cin >> xl >> yl >> xr >> yr;
        fill(xl, yl, xr, yr);
    }

    go();

    sort(width.begin(), width.end());
    cout << cnt << '\n';

    for (int i : width)
    {
        cout << i << " ";
    }

    return 0;
}