#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

long long modulo(long long num, long long n, long long length){
	if(num%n==0) return length;

	/* 자릿수를 증가시킴 */
	num = num*10+1; length++;
    
    /* (a + b) mod n = (a mod n + b mod n) mod n */
	num %= n;
	return modulo(num,n,length);
}

int main(){
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	vector <long long> ans;

	while(true){
		string s;
		getline(cin,s);
		if(s.empty()) break;
		long long n = stoi(s);
		long long num = 1, length = 1;
		ans.push_back(modulo(num,n,length));
	}

	for(long long a : ans){
		cout << a << '\n';
	}
}
