#include <bits/stdc++.h>

using namespace std;
const int MAX = 10000000;
int a[MAX] = {0};
vector<int> arr[9];

int getException(int i, int n)
{
    int val = n;
    for (int j = 0; j < i - 1; j++)
    {
        val = val * 10 + n;
    }
    return val;
}

int solution(int N, int number)
{
    arr[1].push_back(N);
    a[N] = 1;

    for (int i = 2; i < 9; i++)
    {
        int exceptionVal = getException(i, N);
        if (exceptionVal < MAX)
        { // getException 값이 MAX 이하인지 확인
            arr[i].push_back(exceptionVal);
            a[exceptionVal] = i; // 배열에 접근하기 전 확인
        }
        long long temp1, temp2, temp3, temp4;
        for (int j = 1; j < i; j++)
        {
            for (int k = 0; k < arr[j].size(); k++)
            {
                for (int l = 0; l < arr[i - j].size(); l++)
                {
                    // 곱셈 연산
                    temp1 = arr[j][k] * arr[i - j][l];
                    if (temp1 > 0 && temp1 < MAX && a[temp1] == 0)
                    {
                        arr[i].push_back(temp1);
                        a[temp1] = i;
                    }

                    // 나눗셈 연산 (0으로 나누기 방지)
                    if (arr[i - j][l] != 0)
                    {
                        temp2 = arr[j][k] / arr[i - j][l];
                        if (temp2 > 0 && temp2 < MAX && a[temp2] == 0)
                        {
                            arr[i].push_back(temp2);
                            a[temp2] = i;
                        }
                    }

                    // 더하기 연산
                    temp3 = arr[j][k] + arr[i - j][l];
                    if (temp3 > 0 && temp3 < MAX && a[temp3] == 0)
                    {
                        arr[i].push_back(temp3);
                        a[temp3] = i;
                    }

                    // 빼기 연산
                    temp4 = arr[j][k] - arr[i - j][l];
                    if (temp4 > 0 && temp4 < MAX && a[temp4] == 0)
                    {
                        arr[i].push_back(temp4);
                        a[temp4] = i;
                    }
                }
            }
        }
    }

    int answer = a[number];
    if (answer == 0)
        return -1;
    return answer;
}
