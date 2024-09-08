#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int tall[9];

/* 벡터의 합 계산 */
int cal_sum(vector<int> &b){
	int sum=0;
	for(int i=0; i<b.size(); i++){
		sum +=b[i];
	}
	return sum;
}

/* 출력 */
void print(vector<int> b){
	sort(b.begin(),b.end());
    for(int i:b) cout << i << "\n";
}

/* 난쟁이 조합 구하기 */
void combi(int start, vector<int> &b){

	/*	7명 조합이 완성된 경우*/
	if(b.size()==7){
		if(cal_sum(b)==100){
			print(b);
			exit(0);
		}
		return;
	}

	for(int i = start+1; i<9; i++){
		b.push_back(tall[i]);
		combi(i,b);
		b.pop_back();
	}
	return;
}

int main(){
	vector<int> ans;
   /* 입력 */
	for(int i=0; i<9; i++){
		cin >> tall[i];
	}

	combi(-1,ans);

}
