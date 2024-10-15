#include <bits/stdc++.h>

using namespace std;

int a = 0;
int b = 0;

int sum[3] = {
    0,
};

int present = 0;
string change_time = "00:00";

pair<int, string> v[100];
vector<int> state;

int calculator(string a, string b)
{
    int asec = stoi(a.substr(0, 2)) * 60 + stoi(a.substr(3, 2));
    int bsec = stoi(b.substr(0, 2)) * 60 + stoi(b.substr(3, 2));
    return abs(asec - bsec);
}

string to_formatted_string(int num)
{
    if (num < 10)
    {
        return '0' + to_string(num);
    }
    else
    {
        return to_string(num);
    }
}

string format(int sum)
{
    if (sum == 0)
        return "00:00";
    int min = sum / 60;
    int sec = sum % 60;

    return to_formatted_string(min) + ':' + to_formatted_string(sec);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        pair<int, string> p;
        cin >> p.first >> p.second;
        v[i] = p;
    }

    for (pair<int, string> p : v)
    {
        if (p.first == 1)
        {
            a++;
        }
        else if (p.first == 2)
        {
            b++;
        }

        if (a > b)
        {
            state.push_back(1);
        }
        else if (b > a)
        {
            state.push_back(2);
        }
        else
        {
            state.push_back(0);
        }
    }

    // state가 1->0 || 2->0으로 바뀔때 저장
    // stack 1-> 1 / 2->2 일떈 누적
    for (int i = 0; i < state.size(); i++)
    {
        if (present != state[i])
        {
            sum[present] += calculator(v[i].second, change_time);
            change_time = v[i].second;
            present = state[i];
        }

        // 마지막 요소
        if (i == state.size() - 1)
        {
            sum[present] += calculator("48:00", change_time);
        }
    }

    cout << format(sum[1]) << '\n';
    cout << format(sum[2]);

    return 0;
}