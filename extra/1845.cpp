#include <bits/stdc++.h>
using namespace std;

map<int, int> m;

int solution(vector<int> nums)
{
    for (int num : nums)
    {
        if (m.find(num) != m.end())
        {
            m[num]++;
        }
        else
        {
            m.insert({num, 1});
        }
    }

    // 가져갈 포켓몬 수
    int total = nums.size() / 2;

    int answer = m.size();
    if (answer > total)
        return total;
    return answer;
}