#include<iostream>
#include<vector>
#include<cstring>
#include<set>
#include<algorithm>

using namespace std;

struct info { int d1, d2; };
int T,N;
int Map[30][30];
int mmax = -1;

void Make_D(int sx, int sy);
void Make_square(int sx, int sy, int d1, int d2);

int main()
{
	cin >> T;
	for (int q = 1; q <= T; q++) 
	{
		//초기화
		memset(Map, 0, sizeof(Map));
		N = 0; mmax = -1;

		//입력
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> Map[i][j];
			}
		}

		//d1,d2값구하기
		for (int i = 1; i <= N - 2; i++)
		{
			for (int j = 2; j <= N - 1; j++) //시작점
			{
				Make_D(i, j);
			}
		}

		//출력
		cout << '#'<<q<<' '<<mmax << endl;
	}
	return 0;
}


void Make_D(int sx, int sy)
{
	vector<info>D;

	for (int d1 = 1; d1 < sy; d1++)
	{
		if (sx + d1 > N || sy - d1 < 1)continue;
		for (int d2 = 1; d2 <= N - sy; d2++)
		{
			if (sx + d2 > N || sy + d2 > N)continue;
			if (sx + d2 + d1 > N || sy + d2 - d1 < 1)continue;
			if (sx + d1 + d2 > N || sy - d1 + d2 > N)continue;
			D.push_back({ d1,d2 });
		}
	}


	for (int i = 0; i < D.size(); i++)
	{
		int d1 = D[i].d1; 
		int d2 = D[i].d2;
	
		Make_square(sx, sy, d1, d2);
	}
}

void Make_square(int sx, int sy, int d1, int d2)
{
	set<int>S;
	bool check[30][30] = { false };
	bool stop = false;
	int cnt = 0;

	for (int i = 0; i <= d1; i++)
	{
		check[sx + i][sy - i] = true;
		check[sx + d2 + i][sy + d2 - i] = true;
	}

	for (int i = 0; i <= d2; i++)
	{
		check[sx + i][sy + i] = true;
		check[sx+d1+i][sy-d1+i]=true;
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (check[i][j])
			{
				if (S.find(Map[i][j]) != S.end())
				{
					stop = true;
					break;
				}
				else
				{
					S.insert(Map[i][j]);
				}
			}
		}
		if (stop)break;
	}

	if (stop)return;

	int ans = S.size();
	mmax = max(mmax, ans);
}
