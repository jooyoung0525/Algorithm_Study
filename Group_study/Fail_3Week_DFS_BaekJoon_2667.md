


-return : 함수에서 탈출을 의미 

-break : 루프문 탈출을 의미. 

[EX]

for문 밑에 또 다른 연산을 집어넣었을때 

1. return일 경우 밑에 연산을 수행하지 않음

2. break는 해당 for문을 중지하고 그 다음 연산을 수행

---------------------------------------------------------------------------------------------------------
```c
#include<cstdio>
#include<cstdlib>
#include<algorithm>



using namespace std;

int arr[30][30];
int check[30][30];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int cnt;
int danji;
int num[30];




void DFS(int curx, int cury, int N){

	int nextx, nexty;

	
	check[curx][cury] = 1;

	for (int i = 0; i < 4; i++)
	{
		nextx = curx + dx[i];
		nexty = cury + dy[i];

		if (nextx < 0 || nextx > N || nexty < 0 || nexty > N)
			continue;
		
		else {
			
			if (check[nextx][nexty] == 0 && arr[nextx][nexty] == 1) {
				cnt++;
				DFS(nextx, nexty, N);
				
			}
		}
		

	}


}

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &arr[i][j]);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && check[i][j] == 0) {
				cnt = 0;
				DFS(i, j, N);
				num[danji] = cnt;
				danji++;
				
			}
		}
	}

	sort(num,num+danji);

	printf("%d\n", danji);

	for (int i = 0; i < danji; i++)
	{
		printf("%d\n", num[i]);
	}

	system("pause");
	return 0;
}
```
