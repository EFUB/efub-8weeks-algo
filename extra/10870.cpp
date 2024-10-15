#include <bits/stdc++.h>

using namespace std;

int n;

int F[21] = {
    0,
};

void go()
{
    F[0] = 0;
    F[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }
}

int main()
{
    cin >> n;
    go();

    cout << F[n];
}