#include <bits/stdc++.h>

using namespace std;
int N, M, J;

int sum = 0;
pair<int, int> bucket;

pair<int, int> go(int loc)
{

    int temp = 0;

    if (loc < bucket.first)
    {
        temp = bucket.first - loc;
        sum += temp;
        bucket.first = loc;
        bucket.second = bucket.second - temp;
    }
    else if (loc > bucket.second)
    {

        temp = loc - bucket.second;
        sum += temp;
        bucket.first = bucket.first + temp;
        bucket.second = loc;
    }

    return bucket;
}
int main()
{
    cin >> N >> M;
    cin >> J;
    bucket = {1, M};
    for (int i = 0; i < J; i++)
    {
        int loc;
        cin >> loc;
        bucket = go(loc);
    }

    cout << sum;
}