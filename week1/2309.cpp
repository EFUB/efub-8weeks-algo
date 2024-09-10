#include <bits/stdc++.h>

using namespace std;

vector<int> height(9);
int total = 0;

pair<int, int> combi()
{
    int gap = total - 100;
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (height[i] + height[j] == gap)
            {
                return make_pair(height[i], height[j]);
            }
        }
    }
}

void printAnswer()
{
    pair<int, int> fake = combi();

    for (int i : height)
    {

        if (i != fake.first && i != fake.second)
            cout << i << "\n";
    }
}

int main()
{
    int num;
    for (int i = 0; i < 9; i++)
    {
        cin >> num;
        height[i] = num;
        total += num;
    }

    sort(height.begin(), height.end());

    printAnswer();
}