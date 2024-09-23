/* 1325 */

#include<iostream>
#include<deque>
#include <queue>
#include<string>
#include <math.h>
#include <vector>
#include <stack>
#include <algorithm>
 
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	int u,t;
	cin >> n >> m;
	vector<int> v[10001];
	for(int i=1; i<=m; i++){
		cin >> u >> t;
		v[u].push_back(t);
	}
	int vis[10001];
	int result[10001];
	int maxi = -1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			vis[j] = 0;
		}
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			int current = q.front();
			q.pop();
			vis[current] = 1;
			for(int z=0; z<v[current].size(); z++){
				int temp = v[current][z];
				if(vis[temp] == 0){
					q.push(temp);
					vis[temp] = 1;
					result[temp] += 1;
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(maxi < result[i]){
			maxi = result[i];
		}
	}
	for(int i=1; i<=n; i++){
		if(maxi == result[i]){
			cout<<i<<" ";
		}
	}
}
