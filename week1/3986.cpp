#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cnt = 0;
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;

        // 짝수일때만 고려
        if (s.length() % 2 == 0)
        {
            stack<char> st;
            for (char i : s)
            {

                if (!st.empty() && st.top() == i)
                {
                    st.pop();
                }
                else
                {
                    st.push(i);
                }
            }

            if (st.empty())
            {
                cnt++;
            }
        }
    }

    cout << cnt;
}