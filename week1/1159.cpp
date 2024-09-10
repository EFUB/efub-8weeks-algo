#include <bits/stdc++.h>

using namespace std;

vector<int> v(26, 0);
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        int idx = name[0] - 'a';
        v[idx] = v[idx] + 1;
    }

    // 출력
    bool isPredaja = true;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] >= 5)
        {
            isPredaja = false;
            cout << char('a' + i);
        }
    }

    if (isPredaja == true)
    {
        cout << "PREDAJA";
    }
}