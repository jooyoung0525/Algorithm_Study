


**return : 함수를 끝내고 나감**

**break :반복문을 나가버림**

**continue:**

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
