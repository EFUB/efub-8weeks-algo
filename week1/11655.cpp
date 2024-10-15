#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    for (int i : s)
    {
        if (i <= 'Z' && i >= 'A')
        {
            // 대문자
            cout << char('A' + (i - 'A' + 13) % 26);
        }
        else if (
            i <= 'z' && i >= 'a')
        {
            // 소문자
            cout << char('a' + (i - 'a' + 13) % 26);
        }
        else
        {
            cout << char(i);
        }
    }
}