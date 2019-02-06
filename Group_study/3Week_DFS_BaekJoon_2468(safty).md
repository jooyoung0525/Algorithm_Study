--------------------------------------------------------------------------------------------------------------------

# 헤헤헤 한시간 반만에 풀었다!!! 단지문제풀고 푸니까 쉽게느껴졌다 기분짱좋~~~~

```c
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

#define N_MAX 100

int rain[N_MAX][N_MAX];
int visited[N_MAX][N_MAX];
int ans[N_MAX];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int cnt;

void DFS(int curx, int cury, int i, int N)
{
	visited[curx][cury] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = curx + dx[i];
		int ny = cury + dy[i];

		if (nx <= -1 || nx >= N || ny <= -1 || ny >= N) continue;
		
		if (visited[nx][ny] == 0 && rain[nx][ny] >= 0) {
			DFS(nx, ny, i, N);
		}
	}
}


int main()
{
	int N;
	int rain_MAX[N_MAX];
	int rain_MIN[N_MAX];
	

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> rain[i][j];
		}
	}


	for (int i = 0; i < N; i++)
		rain_MAX[i] = *max_element(rain[i], rain[i] + N);

	int rain_MAX2 = *max_element(rain_MAX, rain_MAX + N);

	//printf("%d\n", rain_MAX2);

	for (int i = 0; i < N; i++)
		rain_MIN[i] = *min_element(rain[i], rain[i] + N);

	int rain_MIN2 = *min_element(rain_MIN, rain_MIN + N);

	//printf("%d\n", rain_MIN2);

	for (int i = 0; i < rain_MAX2; i++)
	{
		
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (rain[j][k] == i)
				{
					rain[j][k] = -1;
				}
				visited[j][k] = 0;
			}
			
		}
		cnt = 0;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				
				if (visited[j][k] == 0 && rain[j][k] >= 0) {
					DFS(j, k, i, N);
					cnt++;
					ans[i] = cnt;
				}
			}
		}
	}


	
	/*
	for (int i = rain_MIN2; i < rain_MAX2; i++)
	{
		printf("%d %d\n",i, ans[i]);
	}*/

	int ans_MAX = *max_element(ans, ans + rain_MAX2);

	printf("%d\n", ans_MAX);

	system("pause");
	return 0;
}
```
