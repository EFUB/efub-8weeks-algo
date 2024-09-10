#include <bits/stdc++.h>

using namespace std;

int combiCnt(map<string, int> m)
{
    int mul = 1;

    for (auto it : m)
    {
        mul *= (it.second + 1);
    }

    return mul - 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N;
    cin >> T;
    while (T--)
    {
        map<string, int> m;
        cin >> N;

        while (N--)
        {
            string a, b;
            cin >> a >> b;

            if (m.find(b) != m.end())
            {
                int temp = m[b];
                m.erase(b);
                m.insert({b, temp + 1});
            }
            else
            {
                m.insert({b, 1});
            }
        }

        cout << combiCnt(m) << "\n";
    }
}