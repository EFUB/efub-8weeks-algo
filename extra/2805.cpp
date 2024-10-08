#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v;

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int start = 0;
    int end = v[N - 1]; // 가장 큰 나무
    int max = -1;

    while (start <= end)
    {
        long long sum = 0;
        int mid = (start + end) / 2;

        for (int i = 0; i < N; i++)
        {
            if (v[i] - mid > 0)
                sum += v[i] - mid; // 자른 나무 길이
        }

        if (sum >= M)
        {
            start = mid + 1;
            if (mid > max)
                max = mid;
        }
        else
            end = mid - 1;
    }

    cout << max;
}