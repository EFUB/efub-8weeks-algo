#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	string reverse_s(s);
	reverse(reverse_s.begin(), reverse_s.end());

	if(s.compare(reverse_s)== 0) cout << 1 << endl;
	else cout << 0 << endl;
}
