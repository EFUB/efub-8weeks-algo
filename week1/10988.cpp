#include <bits/stdc++.h>

using namespace std;
int main()
{
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != str[str.length() - 1 - i])
        {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
    return 0;
}