#include <bits/stdc++.h>

using namespace std;

int a[5][5] = {
    0,
};

vector<pair<int, int>> v(26, {0, 0});

int cnt = 0;
int answer = 0;

bool check(int y, int x)
{
    // 당장 바뀐 부분만 체크
    bool w = true;
    bool h = true;
    bool c1 = true;
    bool c2 = true;

    // 가로, 세로, 대각선
    for (int i = 0; i < 5; i++)
    {
        if (a[y][i] != 1)
            w = false;

        if (a[i][x] != 1)
            h = false;

        if (y == x)
        {
            if (a[i][i] != 1)
                c1 = false;
        }
        else
        {
            c1 = false;
        }

        if (y + x == 4)
        {
            if (a[4 - i][i] != 1)
                c2 = false;
        }
        else
        {
            c2 = false;
        }
    }

    if (w)
        cnt++;
    if (h)
        cnt++;
    if (c1)
        cnt++;
    if (c2)
        cnt++;

    if (cnt >= 3)
        return true;

    return false;
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int num;
            cin >> num;
            v[num] = {i, j};
        }
    }

    for (int i = 0; i < 25; i++)
    {
        int num, y, x;
        cin >> num;
        tie(y, x) = v[num];
        a[y][x] = 1;
        if (check(y, x))
        {
            if (answer == 0)
                answer = i + 1;
        }
    }

    cout << answer;
    return 0;
}