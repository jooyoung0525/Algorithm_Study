//슬라이딩윈도우 알고리즘

#include<iostream>
#include<deque>
#include<cstdio>

using namespace std;

int N, L;
int A[5000010] = { 0 };
struct info { int idx, value; };
deque<info>DQ;


int main()
{
	
	scanf("%d %d", &N, &L);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i]);
	}
	for (int i = 1; i <=N; i++)
	{
		if (!DQ.empty() && DQ.front().idx <= i - L)
			DQ.pop_front();
		while (!DQ.empty() && DQ.back().value > A[i])
		{
			DQ.pop_back();
		}
		DQ.push_back({ i,A[i] });
		cout << DQ.front().value << " ";
	}
	return 0;
}
