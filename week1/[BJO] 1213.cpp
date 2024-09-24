#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

/* 팰린드롬 만드는 함수 */
string makePalindrome(int size, map<char,int> m){
	string s;
    
    /* 처음과 마지막 index 부터 팰린드롬을 만들기 시작할 것 */
	int start=0,last=size-1;
    
    /* s 초기화 */
	for(int i=0;i<size;i++) s+='0'; 
    
	for(auto iter = m.begin(); iter!= m.end(); iter++){
        /* 알파벳 반복 횟수를 2로 나누어 앞과 뒤에서부터 절반씩 채움
        ex) 크기가 5인 배열에 A가 4번 등장한다면 AA0AA 로 만듦. */
		int num = iter->second;
	
		for(int i=start,j=last; i<start+num/2, j>last-num/2; i++,j--){
			s[i]=iter->first;
			s[j]=iter->first;
		}
        
        /* 현재 채워진 범위를 제외하고 나머지 자리를 채워야 함 */
		start +=num/2; last-=num/2;
    
        /* 만약 홀수번 등장하는 알파벳의 경우 배열의 가운데에 위치해야 함 */
		if(num%2==1)s[size/2]=iter->first;
		
	}
	return s;
}


void solution(string name){
	int even=0, odd=0;
	map<char, int> nameMap;

    /* 이름 정보를 map에 저장 : 알파벳별 횟수 저장 */
	for(int i=0; i<name.length(); i++) nameMap[name[i]]++;
	
    /* 만약 홀수번 등장하는 알파벳이 2개 이상일 경우, 팰린드롭 불가능 */
	for(auto iter = nameMap.begin() ; iter !=  nameMap.end(); iter++){
		int num = iter->second;
		if(num %2 == 0) even++;
		else odd++;

		if(odd >1){
			cout << "I'm Sorry Hansoo" << '\n';
			return;
		}
	}

    /* 팰린드롭을 만들 수 있는 경우 만들어서 출력 */
	cout << makePalindrome(name.length(), nameMap) <<'\n';

	return;
}

int main(){
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	string name;
	cin >> name;

	solution(name);
}
