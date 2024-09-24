#include <iostream>
#include <stdio.h>

using namespace std;  

int dy[4] = {-1, 0,1,0};
int dx[4] = {0,1,0,-1};
int n,ny,nx, ret=0, ans=1;
int a[104][104];
bool visited[104][104];

void DFS(int y, int x, int h){

    /* 방문 표시 */
    visited[y][x]=1;

    for(int i=0;i<4;i++){

        /* 다음 위치 */
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny >=n || nx>=n || ny<0 || nx<0) continue;
        if(a[ny][nx]>h && !visited[ny][nx]) DFS(ny,nx,h);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    cin >> n ;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }

    /* max 높이부터 min 높이까지 BFS를 돌림 */
    for(int i=100; i>=1; i--){
        ret=0;
        for(int y=0;y<n;y++){
            for(int x=0;x<n;x++){
                if(a[y][x]>i && !visited[y][x]){
                    ret++; DFS(y,x,i);
                }
            }
        }

        /* 새로 계산한 ret이 기존 ans보다 크다면, ans 갱신 */
        if(ret > ans) ans = ret;

        /* visited 배열 초기화 */
        for(int y=0;y<n;y++){
            for(int x=0;x<n;x++){
                visited[y][x]=0;
            }
        }
    }
    
    cout << ans << '\n';
}
