#include <bits/stdc++.h>

using namespace std;

vector<int> v(100, 0);

void fillVec(int start, int end)
{
    for (int i = start; i < end; i++)
    {
        v[i] = v[i] + 1;
    }
}

int getAnswer(int A, int B, int C)
{
    int sum = 0;
    for (int i : v)
    {
        if (i == 1)
        {
            sum += A;
        }
        else if (i == 2)
        {
            sum += B * 2;
        }
        else if (i == 3)
        {
            sum += C * 3;
        }
    }

    return sum;
}

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    for (int i = 0; i < 3; i++)
    {
        int start, end;
        cin >> start >> end;
        fillVec(start, end);
    }

    cout << getAnswer(A, B, C);
}