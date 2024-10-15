#include <bits/stdc++.h>

using namespace std;

vector<int> alphabet(26, 0);

int main()
{
    string str;
    cin >> str;

    for (char i : str)
    {
        int idx = i - 'a';
        alphabet[idx] = alphabet[idx] + 1;
    }

    // 출력
    for (int i : alphabet)
    {
        cout << i << " ";
    }
}