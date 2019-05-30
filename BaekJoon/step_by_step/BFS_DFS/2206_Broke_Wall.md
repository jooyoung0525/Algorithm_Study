
### 이해가 잘 안가는 문제...
### 벽을 부수었는지 안부수었는지의 정보도 방문했는지의 정보와 함께 저장하여 푸는 문제!
### 목수의 미로탈출문제와 비슷하지만 목수의 미로탈출 문제에서 왜 처음과 끝점을 각각 BFS돌려서 합친다음 최솟값을 구하는지 아직도 궁금...
----------------------------------------------------------------------------------------------------------------------------
![wall](https://user-images.githubusercontent.com/29946480/58548562-d9afbb80-8209-11e9-8e74-343ef71b8944.PNG)
-----------------------------------------------------------------------------------------------------------------------------
## 풀이 1. 
### 벽을 부수었는지 안부수었는지정보를 방문을했는지에 대한 배열에 추가해서 3차원배열로 푸는 방식
------------------------------------------------------------------------------------------------------------------------------

```c
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;    //queue 쓰기 위해 꼭 필요

queue<pair<pair<int,int>,int>>Q;

int map[1000][1000];
int visit[1000][1000][3] = { 0 }; //map배열 방문확인 + 벽 깼는지 유무확인
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };


int BFS(int N, int M,int canbroken) {     //int형 함수 이용해서 void보다 코드길이 줄일 수 있다

	visit[0][0][canbroken] = 1;      //초기값 방문체크
	Q.push(make_pair(make_pair(0, 0), canbroken));  //queue에 초기값 넣어줌

	while (!Q.empty())   
	{

		int curx = Q.front().first.first;
		int cury = Q.front().first.second;
		int isbroken = Q.front().second;
    Q.pop();
    
		printf("%d %d %d\n", curx, cury, isbroken);  //큐에 알맞은 값이 들어가는지 디버깅 (확인 차)

		if (curx == N-1 && cury == M - 1)      //만약에 현재 좌표가 마지막지점까지 도착했다면 정답 리턴
			return visit[curx][cury][isbroken];

		for (int i = 0; i < 4; i++)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];

			if (nx < 0 || ny < 0 || nx > N-1 || ny > M-1)continue;

			if (map[nx][ny] == 0 && visit[nx][ny][isbroken] == 0)
			{
				Q.push(make_pair(make_pair(nx, ny), isbroken));
				visit[nx][ny][isbroken] = visit[curx][cury][isbroken] + 1;
			}
			

/*
			if (map[nx][ny] == 1 && isbroken == 1)    // 벽이 있고, 벽을 깰 수 있는 상태이면
			{
				Q.push(make_pair(make_pair(nx, ny), isbroken-1)); //다음 좌표와 벽을 깬 상태를 Q에 넣어줌
				visit[nx][ny][isbroken-1] = visit[curx][cury][isbroken] + 1; // 벽을 깬 상태의 (nx,ny)좌표의 방문은 벽을                                                                                               //깨지 않은 현재 위치좌표 + 1
			}
*/                      
//                      ==> 처음 내 방식대로 푼거 밑에 코드 추가..!

		}

	}
	return -1; //만약 도착좌표에 도달하지 않았을 경우 -1 반환

}



int main() {

	int N, M, i, j;
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%1d",&map[i][j]); //스페이스바 이용하지 않는 입력 사용할때 
		}
	}

	int result = BFS(N,M,1);

	printf("%d", result);
	//system("pause");

	return 0; 
}
```
```c
/*

if (map[nx][ny] == 1 && isbroken == 1)
{
		isbroken--;   //isbroken은 while문 안의 변수이기 때문에 여기서 0으로 만들어준다면 꼭 밑에서 다시 원상태로 돌려놔야함!!!
		Q.push(make_pair(make_pair(nx, ny), isbroken));
		visit[nx][ny][isbroken] = visit[curx][cury][isbroken+1] + 1;
		isbroken++;
}
*/
```
-----------------------------------------------------------------------------------------------------------------------------------
## 풀이2. 
### 시작점 BFS돌리고 끝점 BFS돌려서 각 배열의 합에 대한 배열의 최솟값을 구해서 푸는 방식 (목수의 미로탈출)

### ※ 벽이 여러개일 경우 이 방식으로 풀지 못할 것 같음..
-----------------------------------------------------------------------------------------------------------------------------------
```c
#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 1000; // MAX상수 지정
int N, M;
int Graph[MAX][MAX];
int dirx[] = { -1,1,0,0 };
int diry[] = { 0,0,1,-1 };
int visited1[MAX][MAX] = { 0 }; // 시작점기준 방문유무 배열생성
int visited2[MAX][MAX] = { 0 }; // 도착점기준 방문유무 배열생성
int total[MAX][MAX] = { 0 };  

void BFS1(int curX, int curY); //시작점기준 BFS
void BFS2(int curX, int curY); //도착점기준 BFS

int main() {

	//Please Enter Your Code Here
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &Graph[i][j]);
		}
	}

	int cnt = (N) * (M); //전체배열의 갯수, 나중에 시작점부터 도착점까지의 방문 유무를 알아보기위해 설정.
	
	BFS1(0, 0);
	BFS2(N-1, M - 1);

	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited1[i][j] == 0)
				visited1[i][j] = 10000;

			else if (visited2[i][j] == 0)
				visited2[i][j] = 10000;

			total[i][j] = visited1[i][j] + visited2[i][j]; //시작점 기준 방문유무 + 도착점 기준 방문유무

		}

	}




	int min1 = total[0][0]; //시작점의 total배열을 기준으로

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (total[i][j] < min1)
				min1 = total[i][j];   //total배열의 최솟값 찾기.
			
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (total[i][j] > 2000)
				cnt--; //만약 total배열의 값이 2000보다 크면 (시작점기준,도착점기준 두 배열 모두 BFS의 방문이 없었을 경우)
				       //cnt--해줌
		}
	}
	
	if (cnt == 0) 
		printf("-1");
	else
		printf("%d", min1 - 1);

	return 0;
}

void BFS1(int curX, int curY)
{
	queue< pair<int, int> >Q;

	Q.push(make_pair(curX, curY));
	visited1[curX][curY] = 1;

	while (!Q.empty())
	{
		int X = Q.front().first;
		int Y = Q.front().second;
		Q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nextx = X + dirx[k];
			int nexty = Y + diry[k];
			if (nextx<0 || nextx > N - 1 || nexty <0 || nexty > M - 1) continue;
			if (visited1[nextx][nexty] == 0)
			{
				if (Graph[nextx][nexty] == 0) Q.push(make_pair(nextx, nexty));
				visited1[nextx][nexty] = visited1[X][Y] + 1;//방문을 하지 않았으면 그래프의 값이 0이 아니더라도 합을 구함..

			}
		}



	}

}

void BFS2(int curX, int curY)
{
	queue< pair<int, int> >Q;

	Q.push(make_pair(curX, curY));
	visited2[curX][curY] = 1;

	while (!Q.empty())
	{
		int X = Q.front().first;
		int Y = Q.front().second;
		Q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nextx = X + dirx[k];
			int nexty = Y + diry[k];
			if (nextx<0 || nextx > N - 1 || nexty <0 || nexty > M - 1) continue;
			if (visited2[nextx][nexty] == 0)
			{
				if (Graph[nextx][nexty] == 0) Q.push(make_pair(nextx, nexty));
				visited2[nextx][nexty] = visited2[X][Y] + 1;

			}
		}



	}

}
```
