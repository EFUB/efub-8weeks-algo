#include <bits/stdc++.h>

using namespace std;

int getCount(int num)
{
    int two = 0;
    int five = 0;

    for (int i = 2; i <= num; i *= 2)
    {
        two += num / i;
    }
    for (int j = 5; j <= num; j *= 5)
    {
        five += num / j;
    }

    return min(two, five);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int num;
        cin >> num;
        cout << getCount(num) << '\n';
    }

    return 0;
}