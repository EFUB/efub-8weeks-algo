#include <iostream>
#include <stdio.h>

using namespace std;

/* 시간당 주차되어있는 차의 수 : 초기에는 0대*/
int car_time[102]={0};

/* 시간당 주차되어있는 차의 수를 구함. */
void pay_time(int start, int end){
	for(int i=start; i<end; i++){
		car_time[i]++;
	}
}

int cal_pay(int A, int B, int C){
	int pay=0;
	for(int i=1;i<=101;i++){
		if(car_time[i]==1) pay +=A;
		else if(car_time[i]==2) pay+=B*2;
		else if(car_time[i]==3) pay +=C*3;
	}
	
	return pay;
}

int main(){
	int A,B,C;
	cin >> A >> B >> C;
	for(int i=0; i<3; i++){
		int start,end;
		cin >> start >> end;
		pay_time(start, end);
	}

	cout << cal_pay(A,B,C) <<"\n";

}
