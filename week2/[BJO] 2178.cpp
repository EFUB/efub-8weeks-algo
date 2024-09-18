#include </Users/mosuji/codingTest/bits/stdc++.h>
#include <iostream>
#include <stdio.h>

using namespace std;  

int dy[4] = {-1, 0,1,0};
int dx[4] = {0,1,0,-1};
int m,n,y,x,ny,nx,ey,ex;
int a[104][104];
int visited[104][104];


/* 2178 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    cin >> n >> m;
    ey=n-1; ex=m-1;


    for(int i=0; i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            a[i][j]=s[j]-'0';
        }
    }

    queue<pair<int,int>> q;
    visited[0][0] = 1;
    q.push({0,0});
    while(q.size()){
        tie(y,x) = q.front(); q.pop();
        for(int i=0; i<4 ;i++){
            ny = y+dy[i];
            nx = x+dx[i];
            if(ny<0 || nx <0 || ny>=n || nx >= m || a[ny][nx]==0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx]= visited[y][x]+1;
            q.push({ny,nx});
        }
    }

    cout << visited[ey][ex]<< '\n';
}
