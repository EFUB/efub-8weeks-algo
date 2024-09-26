#include <bits/stdc++.h>

using namespace std;

int MAX = 10000666;
vector<int> a;

int main()
{
    for (int i = 666; i < MAX; i++)
    {
        string str = to_string(i);
        if (str.find("666") != string::npos)
        {
            a.push_back(stoi(str));
        }
    }

    int N;
    cin >> N;
    cout << a[N - 1];
    return 0;
}