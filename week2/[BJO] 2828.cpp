/* 2828 */

#include </Users/mosuji/codingTest/bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;  

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,j,ans=0;

    cin >> n >> m;
    int left=1, right=m;
    cin >> j;

    while(j--){
        int pos;
        cin >> pos;

        while(left > pos || right < pos){
            if(pos > right) right++, ans++, left++;
            if(pos < left) right--, ans++, left--;
        }
    }
    cout << ans << '\n';
}
