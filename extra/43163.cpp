#include <bits/stdc++.h>

using namespace std;

queue<string> q;
map<string, int> visited;

int solution(string begin, string target, vector<string> words)
{
    for (string i : words)
    {
        visited.insert({i, 0});
    }
    int wordlen = begin.length();

    q.push(begin);
    while (!q.empty())
    {
        begin = q.front();
        q.pop();

        if (begin == target)
            break;
        for (int i = 0; i < words.size(); i++)
        {
            int cnt = 0;
            for (int j = 0; j < wordlen; j++)
            {
                if (begin[j] != words[i][j])
                    cnt++;
            }
            if (cnt == 1 && !visited[words[i]])
            {
                q.push(words[i]);
                visited[words[i]] = visited[begin] + 1;
            }
        }
    }
    return visited[target];
}