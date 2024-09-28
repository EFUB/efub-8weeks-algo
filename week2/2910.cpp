#include <bits/stdc++.h>

using namespace std;

int N, C;

unordered_map<int, pair<int, int>> m;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.second.first == b.second.first)
        return a.second.second < b.second.second;

    return a.second.first > b.second.first;
}

int main()
{
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (m.find(num) != m.end())
        {
            m[num].first++;
        }
        else
        {
            m.insert({num, {1, i}});
        }
    }

    vector<pair<int, pair<int, int>>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].second.first; j++)
        {
            if (i == v.size() - 1 && j == v[i].second.first - 1)
            {
                cout << v[i].first;
            }
            else
            {
                cout << v[i].first << " ";
            }
        }
    }

    return 0;
}