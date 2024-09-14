#include <iostream>
#include <stdio.h>

using namespace std;

int modulo(long long A, long long B, long long C){
	if(B==1) return A%C;

	if(B%2==0) return (modulo(A,B/2,C)%C*modulo(A,B/2,C)%C)%C;
	else return (modulo(A,B/2,C)%C*modulo(A,(B/2) +1,C)%C)%C;
}

int main(){
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	long long A,B,C;
	cin >> A >> B >> C;
	
	cout << modulo(A,B,C) << '\n';
}
