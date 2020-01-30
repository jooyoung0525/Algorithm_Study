/*
 << 퇴사 설계 >>
 
 1. 다음 상담일의 입장에서 봤을 때, 이전에 상담을 하고 온 경우와 안하고온 경우 두가지로 나뉠 수 있음
 
*/

#include<iostream>
#include<algorithm>

using namespace std;

int N;
struct info { int T, P; };
info plan[20];
int MMax = -10e9;

void DFS(int day, int money);

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> plan[i].T >> plan[i].P;
	}

	DFS(1, 0);
	cout << MMax << "\n";

	return 0;
}

void DFS(int day, int money)
{
	if (day == N + 1)
	{
		MMax = max(MMax, money);
		return;
	}


	//상담안한경우
	DFS(day + 1, money);

	//상담한경우
	if (day + plan[day].T <= N+1)  // 더한 날짜가 N+1이하일 경우에만
	{
		DFS(day + plan[day].T, money + plan[day].P);
	}

}
