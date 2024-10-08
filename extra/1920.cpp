#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> a;

int b_search(int target, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == target)
            return 1;

        if (a[mid] > target)
        {
            high = mid - 1;
        }
        else if (a[mid] < target)
        {
            low = mid + 1;
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        a.push_back(num);
    }

    sort(a.begin(), a.end());

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        cout << b_search(num, 0, a.size() - 1) << '\n';
    }
    return 0;
}