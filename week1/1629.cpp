#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        int a = 1;
        int result = 1;

        while (true)
        {
            if (a % n == 0)
            {
                cout << result << "\n";
                break;
            }
            else
            {
                a = 10 * a + 1;
                a %= n;
                result++;
            }
        }
    }

    return 0;
}
