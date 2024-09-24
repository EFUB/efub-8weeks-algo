#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

string all = "abcdefghijklmnopqrstuvwxyz";
int num[26]={0};

/* 성의 첫 문자별 사람 수 체크*/
void check_name(string name){
	string s;
	s+=name[0];

	int i = all.find(s);
	num[i]++;
}

/* 선발 가능한 성 구하기 */
void select_member(){
	vector<char> member;
	for(int i=0;i<26;i++){
		if(num[i]>=5) member.push_back(all[i]);
	}

	if(member.size()==0) cout << "PREDAJA";
	else{
		for(char c:member) cout << c;
	}
	cout <<"\n";
}


int main(){
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		string name;
		cin >> name;
		check_name(name);
	}
	select_member();

}
