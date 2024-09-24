/* 14502 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int,int> p;
vector<p> emptySpace;

int n,m, y, x, ny,nx, maximum;
int lab[12][12];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
bool visited[12][12];

/* dfs 로 바이러스 퍼뜨림 */
void DFS(int y, int x){

    /* 벽이 세워져 있지 않다면 방문 표시 : 감염 표시 */
    if(lab[y][x]!=1) visited[y][x]=1;

    for(int i=0; i<4; i++){
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
        if(lab[ny][nx]!=1 && !visited[ny][nx]) DFS(ny,nx);
    }
    return;
}

/* 안전 영역 계산 */
int calculateSafeArea(){
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && lab[i][j]==0) ans++;
        }
    }
    return ans;
}

/* 3개의 벽을 세우고 각 경우마다 DFS */
void combi(int start, vector<p> &b){
	if(b.size() == 3){

        /* 벽세우기 */
        for(p wall : b){
            lab[wall.first][wall.second]=1;
        }

        /* DFS */
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(lab[i][j]==2 && !visited[i][j]) DFS(i,j);
            }
        }

        /* 해당 회차의 안전 영역을 구함. */
        int safeArea = calculateSafeArea();

        /* 새롭게 계산안 안전 영역이 기존 최댓값보다 크다면 갱신 */
        if(safeArea > maximum) maximum = safeArea;

        /* 원복 */
        /* 새롭게 세운 벽을 지움 */
        for(p wall : b){
            lab[wall.first][wall.second]=0;
        }

        /* visited 배열 초기화 */
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                visited[i][j]=false;
            }
        }
		return;
	}

	for(int i= start +1; i<emptySpace.size(); i++){
	b.push_back(emptySpace[i]);
	combi(i,b);
	b.pop_back();
	}
	return;
}

void solution(){
    vector<p> b;
    combi(-1,b);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> lab[i][j];

            /* 벽을 추가로 세울 수 있는 공간을 넣음 */
            if(lab[i][j]==0) emptySpace.push_back({i,j});
        } 
    }

    solution();

    cout << maximum << '\n';

    return 0;
}
