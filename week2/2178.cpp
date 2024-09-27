#include <bits/stdc++.h>

using namespace std;

int N, M;
string a[101];
int cnt = 0;
int visited[101][101] = {
    0,
};
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

queue<pair<int, int>> q;

void bfs()
{
    // 최단거리 탐색
    //(1,1) ~(N,M)
    int y = 1;
    int x = 1;

    q.push(make_pair(y, x));
    visited[y][x] = 1;

    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 1 || nx < 1 || ny > N || nx > M)
                continue;
            if (visited[ny][nx] != 0)
                continue;
            if (a[ny][nx] == '0')
                continue;

            q.push(make_pair(ny, nx));
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        str = '0' + str;
        a[i + 1] = str;
    }

    bfs();

    cout << visited[N][M];
    return 0;
}