/* 9012 */
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
vector<string> ans;

string VPS(string s){
    stack<char> st;

    /* 첫 원소는 우선 스택에 넣음 */
    st.push(s[0]);

    for(int i=1; i<s.length(); i++){

        /* 이번 문자가 스택의 top과 다르다면 pop */
        if(st.size() !=0 && st.top() != s[i] && s[i]==')') st.pop();

        /* 이번 문자가 스택의 top과 같다면 push */
        else if(st.size() ==0 || st.top() == s[i]) st.push(s[i]);
    }

    /* for 문이 끝났을 때 VPS 라면 스택에는 원소가 없음. */
    if(st.size()==0) return "YES";
    
    /* 스택에 남아있는 원소가 있다면 VPS가 아님, */
    return "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; string s;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> s;
        ans.push_back(VPS(s));
    }

    for(string a : ans) cout << a << '\n';
    cout << '\n';
    
    return 0;
}
