![2667](https://user-images.githubusercontent.com/29946480/51955094-e7d11380-2485-11e9-8001-f70991234933.JPG)

--------------------------------------------------------------------------------------------------------

- return : 함수에서 탈출을 의미 

- break : 루프문 탈출을 의미. 

- continue : (continue 아래코드) 일부 코드를 실행하지 않고 건너뜀


---------------------------------------------------------------------------------------------------------

**Sort 함수**

```c
#include <algorithm>
```

1. 배열에서 이용

(arr,arr+5) //배열시작부터 배열+5까지 sort

2.vector에서 이용

```c
vector<int> V; 
```
(V.begin(),V.end()) //vector배열 시작부터 끝까지 sort




----------------------------------------------------------------------------------------------------------
## 아래에 맞은코드 있음!

왜틀린지.......

답잘나오는디ㅠㅠㅠㅠㅠㅠㅠㅠㅠ으아ㅏㅏㅏ
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
int num[30];  //=====>배열의 크기때매 틀림!!!!




void DFS(int curx, int cury, int N) {

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

				cnt++;

				DFS(i, j, N);

				num[danji] = cnt;

				danji++;
				

			}
		}
	}

	sort(num, num + danji);

	printf("%d\n", danji);

	for (int i = 0; i < danji; i++)
	{
		printf("%d\n", num[i]);
	}

	system("pause");
	return 0;
}
```


-----------------------------------------------------------------------------------------------------------------
# 맞았다!!!!!!!!!!!!!!!!>_<우헤헤헤헤헤헤헤헤헿ㅎㅎㅎ


```c
#include<cstdio>
#include<cstdlib>
#include<algorithm>     //sort알고리즘 이용



using namespace std;

int arr[30][30];
int check[30][30];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int cnt; //단지내 집의 갯수
int danji; //아파트 단지의 갯수
int num[1000];   //arr[][]의 배열의 크기의 범위가 25여도 단지의 갯수는 25개가 아닐수 있기때문에 주의!!(위에처럼 25로설정하면 안됨)




void DFS(int curx, int cury, int N){

	int nextx, nexty;

	
	check[curx][cury] = 1; //현재위치 방문표시
	for (int i = 0; i < 4; i++) //동서남북 체크
	{
		nextx = curx + dx[i];
		nexty = cury + dy[i];

		if (nextx < 0 || nextx > N || nexty < 0 || nexty > N)
			continue;     //만약 i = 0에서 범위 밖이면 for루프 i=1부터 다시 돌기
		
		else {
			
			if (check[nextx][nexty] == 0 && arr[nextx][nexty] == 1) { //방문전이고 집이있으면
				cnt++; //집의수 카운트
				DFS(nextx, nexty, N); // 그 부분부터 DFS탐색
				
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
			if (arr[i][j] == 1 && check[i][j] == 0) { //방문전이고 집이있으면
				
				cnt = 0; //단지내 집의갯수 초기화

				DFS(i, j, N); //DFS탐색

				cnt++; //현재위치인 집도 카운트
				
				num[danji] = cnt; //배열에 단지별 집의갯수 저장(0부터)

				danji++; //단지갯수 카운트
				
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
