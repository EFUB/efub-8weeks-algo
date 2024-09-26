#include <bits/stdc++.h>
using namespace std;

vector<int> child_list[50];
int visited[50] = {
    0,
};
int cnt = 0;

int dfs(int here)
{
    if (visited[here] == 0)
    {
        visited[here] = 1;

        for (int there : child_list[here])
        {
            if (!visited[there])
                dfs(there);
        }
        if (child_list[here].size() == 0)
        {
            cnt++;
        }
        if (child_list[here].size() == 1 && visited[child_list[here][0]] == 2)
        {
            cnt++;
        }
    }
    return cnt;
}

void removeChild(int remove)
{
    if (child_list[remove].size())
        for (int child : child_list[remove])
        {

            removeChild(child);
            child_list[child].clear();
        }

    return;
}

int main()
{
    int N;
    cin >> N;
    int root;
    for (int i = 0; i < N; i++)
    {
        int p;
        cin >> p;
        if (p != -1)
        {
            child_list[p].push_back(i);
        }
        else
        {
            root = i;
        }
    }
    int remove;
    cin >> remove;
    // 삭제한 노드는 이미 방문한 것으로 처리
    visited[remove] = 2;

    // 리프 노드 수 구하기
    cout << dfs(root);
}