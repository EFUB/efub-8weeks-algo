#include <bits/stdc++.h>

using namespace std;

map<string, int> m;

int solution(vector<vector<string>> clothes)
{
    int a = clothes.size();
    for (int i = 0; i < a; i++)
    {
        if (m.find(clothes[i][1]) != m.end())
        {
            m[clothes[i][1]]++;
        }
        else
        {
            m.insert({clothes[i][1], 1});
        }
    }
    int answer = 1;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        answer *= (it->second + 1);
    }

    return answer - 1;
}