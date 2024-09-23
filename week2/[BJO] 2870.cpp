/* 2870 */

#include </Users/mosuji/codingTest/bits/stdc++.h>

using namespace std;

vector<long long> v;

long long strToLong(string s){

    long long number=0;
    for(int i=s.length()-1, j=1; i>=0; i--,j*=10){
        long long n = s[i]-'0';
        number += j*n;
    }
   return number;
}

/* 숫자인지, 알파벳인지 */
bool isAlphabet(char c){
    if(c >='a' && c<='z') return true;
    else return false;
}

void solution(string s){
    string number;

    for(int i=0; i<s.length(); i++){
        char c = s[i];
        /* 숫자인 경우 */
        if(isAlphabet(c)==false){
            if(c=='0'){
                if(i==s.length()-1 || number!="" || (i+1<s.length() && isAlphabet(s[i+1])==true)) number+=c;
                else if(number=="") continue;
            }
            else number+=c;
        }

        /* 만들어진 숫자가 있고, 알파벳이 들어온 경우 */
        else if(number!="" && isAlphabet(c)==true){
            v.push_back(strToLong(number));
            number="";
        }

        if(i == s.length()-1 && number!=""){
            v.push_back(strToLong(number));
            number="";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        solution(s);
    }

    sort(v.begin(),v.end());
    for(long long n:v) cout << n << '\n';
}
