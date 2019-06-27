```c
#include<cstdio>
#include<cstdlib>

int N, M;
int map[1000][1000];


int main() {

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	int ans = 0;
	int hap;

	for (int i = 0; i < 4; i++)
	{
		ans += map[0][i];    //처음에 비교할 기준 값. 테트로미노 중 하나 임의로 선정해 합한 값.
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
		
			if (j + 3 < M)
			{ 
				hap = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3]; //기준
				if (ans < hap)
					ans = hap;
			}
			if (i + 3 < N)
			{
				hap = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
				if (ans < hap)
					ans = hap;
			}
			if (j + 1 < M && i + 1 < N)
			{
				hap = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1];
				if (ans < hap)
					ans = hap;
			}
			if (i + 2 < N && j + 1 < M)
			{
				hap = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
				if (ans < hap)
					ans = hap;
				hap = map[i + 2][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
				if (ans < hap)
					ans = hap;
				hap = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
				if (ans < hap)
					ans = hap;
				hap = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 2][j];
				if (ans < hap)
					ans = hap;
				hap = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
				if (ans < hap)
					ans = hap;
				hap = map[i + 1][j] + map[i + 1][j + 1] + map[i][j + 1] + map[i + 2][j];
				if (ans < hap)
					ans = hap;
				hap = map[i][j] + map[i + 1][j + 1] + map[i + 1][j] + map[i + 2][j];
				if (ans < hap)
					ans = hap;
				hap = map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1];
				if (ans < hap)
					ans = hap;

			}
			if (i + 1 < N && j + 2 < M)
			{
				hap = map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2] + map[i][j + 2];
				if (ans < hap)
					ans = hap;
				hap = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i+1][j + 2];
				if (ans < hap)
					ans = hap;
				hap = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i+1][j];
				if (ans < hap)
					ans = hap;
				hap = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i+1][j + 2];
				if (ans < hap)
					ans = hap;
				hap = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
				if (ans < hap)
					ans = hap;
				hap = map[i + 1][j] + map[i + 1][j + 1] + map[i][j + 1] + map[i][j + 2];
				if (ans < hap)
					ans = hap;
				hap = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
				if (ans < hap)
					ans = hap;
				hap = map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2] + map[i][j + 1];
				if (ans < hap)
					ans = hap;
			}
		
		}
	}
	
	printf("%d", ans);

	system("pause");
	return 0;
}
```
