#include <iostream>
#include <stdio.h>
#include <map>


using namespace std;

void solution(){
	int n, sum=1;
	map<string, int> wear;
	cin >> n;

	/* type별 의상 수를 증가시킴 */
	for(int i=0; i<n; i++){
		string w, type;
		cin >> w >> type;
		wear[type]++;
	}

	for(auto w : wear){
		sum *= w.second+1;
	}
	cout << sum-1 << '\n';
}


int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		solution();
	}
}
