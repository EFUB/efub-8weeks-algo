#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int h, m, s;
        cin >> h >> m >> s;

        // 시침: 1시간 30도 / 1분 0.5도 / 1초 0.008333
        double a = 30 * h + m * (0.5) + s * 0.008333333;

        // 분침: 1분 6도 / 1초 0.1도
        double b = m * 6 + s * 0.1;

        // 초침: 1초 6도
        double c = 6 * s;

        double temp1 = abs(a - b);
        double temp2 = abs(a - c);
        double temp3 = abs(b - c);

        if (temp1 > 180)
            temp1 = 360 - temp1;
        if (temp2 > 180)
            temp2 = 360 - temp2;
        if (temp3 > 180)
            temp3 = 360 - temp3;

        double answer = min({temp1, temp2, temp3});

        cout << fixed << setprecision(6) << answer << '\n';
    }
}