#include <iostream>
#include <stdio.h>

using namespace std;

long long solution(long long N, long long M, long long *met){
	long long num=0;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
            
            /* 2개의 무기로 갑옷을 만들기 때문에, 0으로 표시된 재료는 제외한다. */
			if(met[i]+met[j]==M && met[i] !=0 && met[j] !=0){
				num++;
				met[i]=0; met[j]=0;
				break;
			}
		}
	}
	return num;
}

int main(){
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	long long N,M;
	cin >> N >> M;
	long long meterial[N];
	for(long long i=0; i<N; i++){
		cin >> meterial[i];
	}

	cout << solution(N,M,meterial) <<'\n';
}
