#include <bits/stdc++.h>

using namespace std;

int A[301] = {
    0,
};

int DP[301] = {
    0,
};

int answer = 0;
int n;

void go()
{
    DP[1] = A[1];
    DP[2] = A[1] + A[2];
    DP[3] = max(A[1] + A[3], A[2] + A[3]);
    for (int i = 4; i <= n; i++)
    {
        DP[i] = max(DP[i - 2] + A[i], DP[i - 3] + A[i - 1] + A[i]);
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        A[i] = a;
    }

    go();

    cout << DP[n];
}