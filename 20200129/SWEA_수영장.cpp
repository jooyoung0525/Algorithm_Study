#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;


int T;
int eachCost[5];
int Plan[13];
int MMin = 10e9;

void DFS(int idx, int cost);

int main()
{
	cin >> T;
	for (int q = 1; q <= T; q++)
	{
		//초기화
		memset(eachCost, 0, sizeof(eachCost));
		memset(Plan, 0, sizeof(Plan));
		MMin = 10e9;

		//입력
		for (int i = 0; i < 4; i++)
		{
			cin >> eachCost[i];
		}

		MMin = eachCost[3];// 조건 3. 1년 이용권을 최솟값으로 설정

		for (int i = 0; i < 12; i++)
		{
			cin >> Plan[i];
		}

		//DFS idx: 0 부터 탐색
		DFS(0, 0);

		//출력
		cout << MMin << endl;

	}

	return 0;
}

void DFS(int idx, int cost)
{
	if (idx >= 13) // 조건 2. 해당월이 13을 넘을경우 최솟값 구하기
	{
		MMin = min(MMin, cost);
		return;
	}

	if (Plan[idx] <= 0) // 조건 1. 이용횟수 없는 달 (계획수가 0인 경우) 
	{
		DFS(idx+1 , cost); //비용은 그대로 + 다음달로 넘김
	}

	else { // 조건 1. 이용횟수 있는 달 (계획수가 0보다 클 때) 

		DFS(idx + 1, cost + (eachCost[0] * Plan[idx])); // 조건 2. 1일 이용권
		DFS(idx + 1, cost + eachCost[1]);// 조건 2. 1달 이용권
	
		if (idx+3 <= 14) //11월,12월도 3달이용권 사용할 수 있음 ( '11( =12월 ,idx 0부터)+3 = 14월' 까지 이용가능)
		{
			DFS(idx + 3, cost + eachCost[2]); //  조건 2. 3달 이용권
		}
	}
}
