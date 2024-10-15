#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;

    string pattern;
    cin >> pattern;

    auto idx = pattern.find('*');

    string prefix = pattern.substr(0, idx);
    int prefixLen = prefix.length();
    string suffix = pattern.substr(idx + 1);
    int suffixLen = suffix.length();

    for (int i = 0; i < n; i++)
    {
        bool isDa = false;
        string str;
        cin >> str;

        if (str.length() >= prefixLen + suffixLen)
        {
            if (str.substr(0, prefixLen) == prefix)
            {
                if (str.substr(str.length() - suffixLen) == suffix)
                {
                    isDa = true;
                }
            }
        }

        if (isDa)
        {
            cout << "DA" << "\n";
        }
        else
        {
            cout << "NE" << "\n";
        }
    }
}