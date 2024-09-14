#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
int main(){
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 

	int N,M;
	cin >> N >> M;

	map<string, int> monsterDictionary;
	string monsterDic[N];
	string ans[M];

	for(int i=0; i<N; i++){
		cin >> monsterDic[i];
		monsterDictionary.insert({monsterDic[i],i+1});
	}

	for(int i=0; i<M; i++){
		string monsterName;
		cin >> monsterName;

		/* 입력으로 숫자가 들어왔다면, */
		if(monsterName[0] >='0' && monsterName[0]<='9') ans[i] = monsterDic[stoi(monsterName)-1];

		/* 입력으로 몬스터의 이름이 들어왔다면 */
		else ans[i] = to_string(monsterDictionary[monsterName]);
	}

	/* 출력 */
	for(int i=0; i<M; i++) cout << ans[i] <<"\n";
}
