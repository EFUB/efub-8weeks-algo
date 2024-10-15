#include <bits/stdc++.h>

using namespace std;

int K, N;
vector<int> v;
int max_len = 1;
long long sum = 0;

void b_search()
{
    long long low = 0;
    long long high = sum / N;
    // 다 합한 뒤 필요한 개수로 나눔  = 최대 길이
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        if (mid == 0)
        {
            return;
        }
        // 각 랜선을 최대 길이로 나눈 몫의 합이 N과 같거나 클때 까지 연산
        int cnt = 0;
        for (int i = 0; i < K; i++)
        {

            cnt += v[i] / mid;
        }

        if (cnt >= N)
        {
            if (max_len < mid)
                max_len = mid;
            low = mid + 1;
        }
        else if (cnt < N)
        {
            high = mid - 1;
        }
    }
}

int main()
{

    cin >> K >> N;
    for (int i = 0; i < K; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
        sum += a;
    }

    b_search();

    cout << max_len;

    return 0;
}