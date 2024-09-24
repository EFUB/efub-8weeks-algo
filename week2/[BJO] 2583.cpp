#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;  

/* 2583 */

int dy[4] = {-1, 0,1,0};
int dx[4] = {0,1,0,-1};
int m,n,k,ny,nx, ret=0,w=0, sy,sx,ey,ex;
int a[104][104];
bool visited[104][104];
vector<int> weight;

/* DFS */
void DFS(int y, int x){

    /* 방문 표시 */
    visited[y][x]=1; w++;

    for(int i=0;i<4;i++){

        /* 다음 위치 */
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny >=n || nx>=m || ny<0 || nx<0) continue;
        if(a[ny][nx]==0 && !visited[ny][nx]) DFS(ny,nx);
    }
    return;
}

/* 종이 붙이기 */
void attach(int sy,int sx, int ey, int ex){
    for(int i = sy; i<ey; i++){
        for(int j = sx; j<ex; j++){
            a[j][i]=1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    /* 입력 */
    cin >>m>>n>>k ;

    /* 색종이 붙이기 */
    for(int i=0; i<k; i++){
        cin >>sx>>sy>>ex>>ey;
        attach(sy,sx,ey,ex);
    }

    /* 종이가 붙어있지 않은 영역 구하기*/
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]==0 && !visited[i][j]){
                w=0;
                ret++; DFS(i,j); weight.push_back(w);
            }
        }
    }

    sort(weight.begin(), weight.end());

    cout << ret << '\n';
    for(int ans:weight){
        cout << ans << " ";
    }
    cout << '\n';
}
