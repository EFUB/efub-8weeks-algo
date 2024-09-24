/* 4659 */
#include </Users/mosuji/codingTest/bits/stdc++.h>

using namespace std;

bool isVowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
    else return false;
}


bool isAcceptable(string s){
    int vowel=0, same=0;

    for(int i=0; i<s.length(); i++){
        char c = s[i];

        /* 같은 글자가 반복되는가 */
        if(i+1 < s.length() && (c!='e'&& c!='o')&&c==s[i+1]) return false;

        /* 모음 포함 여부 */
        if(isVowel(c)==true) vowel++;

        /* 연속된 글자(모음 or 자음)가 나타나는가 */
        if(i+1 < s.length() && isVowel(c) == isVowel(s[i+1])){
            same++;
            if(same>=2) return false;
        } 
        else if(i+1 < s.length() && isVowel(c) != isVowel(s[i+1])) same=0;
    }

    if(vowel==0) return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    while(true){
        cin >> s;
        if(s=="end") break;
        if(isAcceptable(s)== true) cout << "<" << s << ">" << " is acceptable." << '\n';
        else cout << "<" << s << ">" << " is not acceptable." << '\n';
    }
}
