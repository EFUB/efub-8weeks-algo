#include <bits/stdc++.h>

using namespace std;

vector<int> v(100001, 0);

int main()
{
    int N, M;
    cin >> N;
    cin >> M;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v[num] = 1;
    }

    int cnt = 0;
    for (int i = 1; i < 100001; i++)
    {
        if (v[i] == 1)
        {
            int gap = M - i;
            if (gap != i && gap > 0 && gap < 100001)
            {
                if (v[gap] == 1)
                {
                    cnt++;
                    v[i] = 0;
                    v[gap] = 0;
                }
            }
        }
    }

    cout << cnt;
}