#include <bits/stdc++.h>

using namespace std;

vector<string> v;

void go(string str)
{
    string num = "";
    for (char c : str)
    {
        if (c >= '0' && c <= '9')
        {
            // 숫자라면
            num += c;
        }
        else
        {
            // 문자라면
            if (num != "")
            {
                // 0제거
                while (num != "0" && num[0] == '0')
                {
                    num.erase(0, 1);
                }

                v.push_back(num);
            }
            num = "";
        }
    }

    // 마지막요소라면
    if (num != "")
    {
        // 0제거
        while (num != "0" && num[0] == '0')
        {
            num.erase(0, 1);
        }
        v.push_back(num);
    }
}

bool cmp(string a, string b)
{
    // 문자열 길이로 비교
    if (a.length() != b.length())
    {
        return a.length() < b.length();
    }
    else
    {
        // 길이 같을 시엔 그냥 비교
        return a < b;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        go(str);
    }

    sort(v.begin(), v.end(), cmp);

    for (string s : v)
    {
        cout << s << '\n';
    }
}