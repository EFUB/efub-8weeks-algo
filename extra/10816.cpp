#include <bits/stdc++.h>

using namespace std;

int N, M;
map<int, int> m;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (m.find(num) != m.end())
        {
            m[num]++;
        }
        else
        {
            m.insert({num, 1});
            v.push_back(num); // 중복없이 저장
        }
    }

    sort(v.begin(), v.end());

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        if (binary_search(v.begin(), v.end(), num))
        {
            cout << m[num];
        }
        else
        {
            cout << 0;
        }

        if (i != M - 1)
        {
            cout << " ";
        }
    }
}