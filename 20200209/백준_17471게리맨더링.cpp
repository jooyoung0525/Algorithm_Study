/*
<<접근방법>>
1. 리스트로 각번호의 연결정점 저장
2. 조합으로 각 정점을 1~N-1개(시간줄이려면 N/2개골라도됨,,중복되니까) 고른다
3. 원하는 갯수만큼 정점을 고르고 A팀,B팀으로 나눔
4. 각 팀을 dfs돌려서 서로연결되었으면 결과값을 구함  
(이때 dfs를 돌리면 모든정점을 방문하게되니까 A팀dfs돌리고, A팀에 속하는 수만 dfs방문시 체크 ..
B팀dfs돌리고, B팀에 속하는 수만dfs체크 .. 각팀에 해당하는 체크가 안되있을경우 값계산안하고 리턴)

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>


#define MAX 987654321
using namespace std;

int N;
int MMin = MAX;
int score[15];
vector<int>Info[15];
bool check[15];
int visit[15];

void cangoing(vector<int>team,int cur,bool A);
void select(int cnt, int nowc, int idx);

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> score[i];
	}

	for (int i = 1; i <= N; i++)
	{
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			int a;
			cin >> a;
			Info[i].push_back(a);
		}
	}


	//조합으로 팀선택 (1 ~ N/2개까지)
	for (int i = 1; i <= N-1; i++)
	{
		select(i,0,1);
	}

	if (MMin == MAX) cout << -1 << "\n";
	else
		cout << MMin << "\n";

	return 0;

}

void select(int cnt, int nowc, int idx)
{
	
	if (cnt == nowc)
	{
		vector<int>A; vector<int>B;
		
		
		for (int i = 1; i <= N; i++)
		{
			if (check[i] == true) A.push_back(i);
			else B.push_back(i);
		}

		
		bool flagA = false; bool flagB = false;
		int hapA = 0; int hapB = 0;

		//각팀을 dfs돌려봄
		memset(visit, 0, sizeof(visit));
		visit[A[0]] = 1;
		cangoing(A, A[0],true);
		for (int i = 0; i < A.size(); i++)
		{
			if (visit[A[i]] == 0 || visit[A[i]] == 2) flagA = true;
		}

		
		visit[B[0]] = 2;
		cangoing(B, B[0],false);
		for (int i = 0; i < B.size(); i++)
		{
			if (visit[B[i]] == 0 || visit[B[i]] == 1) flagB = true;
		}



		if (!flagA && !flagB)
		{
			for (int i = 0; i < A.size(); i++)
			{
				hapA += score[A[i]];
			}
			for (int i = 0; i < B.size(); i++)
			{
				hapB += score[B[i]];
			}

			int result = abs(hapA - hapB);
			MMin = min(MMin, result);
		}
		
		return;
	}

	for (int i = idx; i <= N; i++)
	{
		
		check[i] = true;
		select(cnt, nowc + 1, i + 1);
		check[i] = false;
	}

}


void cangoing(vector<int>team,int cur,bool A)
{
	if (A == true) {

		for (int i = 0; i < Info[cur].size(); i++)
		{
			if (visit[Info[cur][i]] == 0 && check[Info[cur][i]] == true) {
				visit[Info[cur][i]] = 1;
				cangoing(team, Info[cur][i], A);
			}
		}
	}
	else
	{
		for (int i = 0; i < Info[cur].size(); i++)
		{
			if (visit[Info[cur][i]] == 0 && check[Info[cur][i]] == false) {
				visit[Info[cur][i]] = 2;
				cangoing(team, Info[cur][i], A);
			}
		}
	}
}
