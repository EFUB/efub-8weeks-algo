#include <bits/stdc++.h>

using namespace std;

char a[] = {'a', 'e', 'i', 'o', 'u'};
void check(string s)
{
    // first
    bool first = false;
    for (int i = 0; i < 5; i++)
    {
        if (s.find(a[i]) != string::npos)
            first = true;
    }

    if (!first)
    {
        cout << "<" << s << "> is not acceptable." << '\n';
        return;
    }

    // 2nd
    if (s.length() >= 3)
    {
        string copy = s;

        for (int i = 0; i < copy.length(); i++)
        {
            bool isA = false;
            for (int j = 0; j < 5; j++)
            {
                if (copy[i] == a[j])
                {
                    isA = true;
                }
            }

            if (isA)
            {
                copy[i] = 'a';
            }
            else
            {
                copy[i] = 'b';
            }
        }

        if (copy.find("aaa") != string::npos || copy.find("bbb") != string::npos)
        {
            cout << "<" << s << "> is not acceptable." << '\n';
            return;
        }
    }

    // 3rd
    if (s.length() >= 2)
    {
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                if (s[i] != 'e' && s[i] != 'o')
                {
                    cout << "<" << s << "> is not acceptable." << '\n';
                    return;
                }
            }
        }
    }

    cout << "<" << s << "> is acceptable." << '\n';
    return;
}

int main()
{
    while (1)
    {
        string s;

        cin >> s;
        if (s == "end")
        {
            return 0;
        }
        check(s);
    }
}