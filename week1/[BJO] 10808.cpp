#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
int num[26]={0};
string all = "abcdefghijklmnopqrstuvwxyz";

void check_spelling(string c){
	if(all.find(c) != string::npos){
		int i = all.find(c);
		num[i]++;
	}
}

void solve(string s){
	for(int i=0; i<s.length(); i++){
		string str;
		str+=s[i];
		check_spelling(str);
	}

	for(int n : num){
		cout << n << " ";
	}
	cout << "\n";
}

int main(){
	string s;
	cin >> s;
	solve(s);
}
