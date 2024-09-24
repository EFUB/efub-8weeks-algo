#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> split(const string& input, string delimiter){
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);
    while(end != string::npos){
        result.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    result.push_back(input.substr(start));
    return result;
}

string solution(string pettern, string s){
    /* pettern의 길이는 s보다 짧아야 함. */
	if(pettern.length()-1 > s.length()) return "NE";
    
	/* pettern을 *을 기준으로 p1과 p2로 쪼갬 */
	vector<string> petterns = split(pettern, "*");
	string p1 = petterns[0];
	string p2 = petterns[1];

	/* s의 p1과 p2의 길이만큼을 제외한 중간 부분을 p1과 p2에 더하여 문자열을 생성.*/
	int start = p1.length();
	int size = s.length() - p1.length() - p2.length();
	string centerS = s.substr(start,size);
	
	string createdS = p1 + centerS + p2;

	/* 만약 새롭게 만들어진 createdS와 s가 같다면 DA */
	if(s == createdS) return "DA";
	else return "NE";
}


int main(){
	int N;
	string pettern;
	vector<string> ans;
	cin >> N;
	cin >> pettern;
	cin.ignore();
	
	for(int i=0; i<N; i++){
		string s;
		getline(cin,s);
		ans.push_back(solution(pettern, s));
	}

	for(int i=0; i<N; i++){
		cout << ans[i] << "\n";
	}
}
