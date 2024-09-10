#include <bits/stdc++.h>

using namespace std;

map<int, string> m1;
map<string, int> m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        string key;
        cin >> key;

        m1.insert({i, key});
        m.insert({key, i});
    }

    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;

        // 숫자이면 벡터에서 참조
        if (int(s[0] - '0') < 10)
        {
            cout << m1[stoi(s)] << "\n";
        }
        else
        {
            // 문자열이면 맵에서 찾기
            cout << m[s] << "\n";
        }
    }
}