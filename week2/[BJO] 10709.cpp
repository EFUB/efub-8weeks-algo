/* 10709 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int h,w;
char cloud[102][102];
int ans[102][102];

/* 구름 계산 */
int isCloud(int y, int x){

    /* 구름이 올 수 없는 경우 */
    if(cloud[y][x]=='.' && x==0) return -1;

    /* 구름이 존재할 수 있는 경우 : 현재 위치 또는 왼쪽 위치에 구름이 있는 경우 */
    for(int i=x; i>=0; i--){
        if(cloud[y][i]=='c') return x-i;
    }

    return -1;
}

void solution(){
    for(int i=0; i<h; i++){
        for(int j=0;j<w;j++) ans[i][j]= isCloud(i,j);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++) cin >> cloud[i][j];
    }

    solution();

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++) cout << ans[i][j] << " ";
        cout << '\n';
    }
}
