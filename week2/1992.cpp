#include <bits/stdc++.h>

using namespace std;

string a[64];
int N;
vector<char> v;

void go(pair<int, int> p, int size)
{
    int y, x;
    tie(y, x) = p;
    int key = a[y][x];

    if (size == 1)
    {
        v.push_back(char(key));
        return;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (key != a[y + i][x + j])
            {
                v.push_back('(');
                go({y, x}, size / 2);
                go({y, x + size / 2}, size / 2);
                go({y + size / 2, x}, size / 2);
                go({y + size / 2, x + size / 2}, size / 2);
                v.push_back(')');
                return;
            }
        }
    }

    // 모두 같다면
    v.push_back(char(key));
    return;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        a[i] = s;
    }

    go({0, 0}, N);

    for (char a : v)
    {
        cout << a;
    }
}