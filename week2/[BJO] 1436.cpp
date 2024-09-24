/* 1436 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
vector<int> v;

bool isSixNum(int num){
    string s = to_string(num);
    if(s.find("666") == string::npos) return false;
    return true;
}

int findNum(int n){
    int i=666;
    while(v.size()!=n){
        if(isSixNum(i)==true) v.push_back(i);
        i++;
    }

    return v[n-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cout << findNum(n) << '\n';

    return 0;
}
