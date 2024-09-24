/* 4949 : 기본 스택 문제  */

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(void) {
	vector<string> ans = {};
	vector<char> stack;
	while (true) {
		int key = 1;
		stack.clear();
		string sentence;
		getline(cin, sentence);
		if (sentence[0] == '.') break;
		for (int i = 0; i < sentence.length()-1; i++) {
			if (sentence[i] == '(' || sentence[i] == '[') stack.push_back(sentence[i]);
			else if (sentence[i] == ')') {
				if (stack.size()>0&&stack.back() == '(') stack.pop_back();
				else { 
					key = -1;
					break; 
				}	
			}
			else if (sentence[i] == ']') {
				if (stack.size() > 0 && stack.back() == '[') stack.pop_back();
				else {
					key = -1;
					break; }
			}
		}
		if (stack.empty()==1&&key>0) ans.push_back("yes");
		else ans.push_back("no");
	}
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
	return 0;
}
