/* 2910 */
#include </Users/mosuji/codingTest/bits/stdc++.h>
#include <iostream>
#include <stdio.h>


using namespace std;  
typedef pair<long,long> p;
vector<p> v;

/* pair 의 second 값을 기준으로 내림차순 정렬 */
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n,c;
    cin >> n >> c;

    /* pair로 수-빈도수 입력, 저장*/
    for(int i=0; i<n ;i++){
        bool isfound=false;
        long long num;
        cin >> num;

        for (auto& it : v) {
            if (it.first == num) {
                it.second++; isfound=true;
                break;
            }
        }
        if(isfound==false) v.push_back(make_pair(num,1));
    }
    
    /* 벡터 변환 -> 빈도수 기준 내림차순 정렬 */
    /* stable_sort 이용 */
    stable_sort(v.begin(),v.end(),compare);

    /* 출력 */
    for(auto& it: v){
        int num = it.second;
        for(int i=0;i<num;i++){
            cout << it.first <<" ";
        }
    }
    cout <<'\n';
}
