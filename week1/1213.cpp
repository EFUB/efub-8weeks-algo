#include <bits/stdc++.h>

using namespace std;

vector<int> v(26, 0);

string getAnswer()
{
    string pre = "";

    char center;
    int centerCnt = 0;
    for (int i = 0; i < 26; i++)
    {
        while (v[i] > 1)
        {
            v[i] = v[i] - 2;
            pre.push_back('A' + i);
        }
        if (v[i] == 1)
        {
            center = 'A' + i;
            centerCnt++;
        }
    }

    string suf = pre;
    reverse(suf.begin(), suf.end());

    if (centerCnt > 1)
    {
        return "I'm Sorry Hansoo";
    }
    else if (centerCnt == 1)
    {
        return pre + center + suf;
    }
    else
    {
        return pre + suf;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    for (char i : s)
    {
        int idx = int(i - 'A');
        v[idx] = v[idx] + 1;
    }

    cout << getAnswer();
}