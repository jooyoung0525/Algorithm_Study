# BFS (Breath-First-Search  넓이우선탐색)
-----------------------------------------------------------------------------------------------------------------------------

### 개념

- **DFS** : 현재 정점에서 갈 수 있는 점들까지 들어가면서 탐색 ==> 한 방향을 파고들며 탐색
- **BFS** : 현재 정점에 연결된 가까운 점들부터 탐색 ==> 주변을 넓게넓게 탐색

### 방법

- **DFS** : 스택 또는 재귀함수로 구현
- **BFS** : 큐를 이용해서 구현

-----------------------------------------------------------------------------------------------------------------------------

## [Stack Library] --> 선입후출
	
```c 
#include<stack>
usind namespace std;

stack <int> S;      //int형의 이름S인 stack생성

S.push(값);         //S인 stack에 값을 넣음 (리턴되지 않음)

S.pop()            //S인 stack에 있는 top값을 삭제 (리턴되지 않음)

S.top()            //S인 stack의 top값을 리턴 (삭제되지 않고 리턴만)

S.size()           //S인 stack에 있는 구성요소 개수 리턴

S.empty()          //S가 비었으면 1리턴, 아니면 0 리턴.


```

## [Queue Library] --> 선입선출
	
```c 
#include<queue>
usind namespace std;

queue <int> Q;      //int형의 이름Q인 queue생성

Q.push(값);         //Q인 queue에 값을 넣음 (리턴되지 않음)

Q.pop()            //Q인 queue에 있는 front값을 삭제 (리턴되지 않음)

Q.front()          //Q인 queue의 front값을 리턴 (삭제되지 않고 리턴만)

Q.back()            //Q인 queue의 back값을 리턴 (삭제되지 않고 리턴만)

Q.size()           //Q의 크기 리턴, queue에 있는 구성요소 개수 리턴

Q.empty()          //Q가 비었으면 1리턴, 아니면 0 리턴.


```

	
	
-----------------------------------------------------------------------------------------------------------------------------

![2178](https://user-images.githubusercontent.com/29946480/51797612-e1565800-2249-11e9-9881-c0d5b151bdc6.JPG)

-------------------------------------------------------------------------------------------------------------------------
### 두번째시도 -  stack이용하려함 (실패)

--> stack에다가 현재위치 넣고, check배열에 현재위치 1 

```c
#include<cstdio>
#include<cstdlib>
#include<stack>

using namespace std;

int miro[100][100] = {};
int check[100][100] = {};
int nextx, nexty;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int total;

stack <pair<int, int>> S;

void DFS(int curx, int cury, int N, int M)
{
	S.push(make_pair(curx, cury));
	check[curx][cury] = 1;
	S.pop();

	while (!S.empty()) {

		for (int i = 0; i < 4; i++)
		{
			nextx = curx + dx[i];
			nexty = cury + dy[i];
			if (nextx > -1 || nextx < N || nexty > -1 || nexty < M) {

				S.push(make_pair(nextx, nexty));
			}
		}

		curx = S.top().first;
		cury = S.top().second;
		
		DFS(curx, cury, N, M);

		//S.pop();
	}

}

int main()
{

	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &miro[i][j]);
		}
	}

	DFS(0, 0, N, M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (check[i][j] == 1)
				total += check[i][j];

		}
	}


	printf("%d", total);

	system("pause");
	return 0;
}
```
-------------------------------------------------------------------------------------------------------------------
# 최단거리 찾는 문제는 BFS가 유리!!!

### BFS,Queue이용해서 다시 품. 맞았다!!!!!!!!!!>_<

```c
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

int miro[110][110];
int visited[110][110];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

queue <pair<int,int>> Q; //두개 값을 한번에 queue에 집어 넣음


void BFS(int curx, int cury, int N, int M)
{
	if (curx >= N && cury >= M ) return; //curx와 cury가 N과M에 도달하면 함수 종료.

	Q.push(make_pair(curx, cury)); //Q에 현재위치 넣음
	visited[curx][cury] = 1; //현재위치 방문
	
	while (!Q.empty()) { //Q가 빌때까지 반복

 		int X = Q.front().first;  //Q의 첫번째의 첫번째값 X에저장
		int Y = Q.front().second; //Q의 첫번째의 두번째값 y에 저장
		Q.pop(); //X,Y에 값을 저장했으니 Q에 들어있는 값을 뺀다.

		for (int i = 0; i < 4; i++) //상하좌우 반복
		{
			int nX = X + dx[i]; //상하좌우설정
			int nY = Y + dy[i]; //상하좌우설정

			if (nX <= 0 || nX > N || nY <= 0 || nY > M) continue; // 미로의 범위를 벗어나면 아래코드 
			                                                      // 실행하지않고 for문다시시작

			if (visited[nX][nY] == 0 && miro[nX][nY] == 1) // 방문하지 않았고, 미로가 갈수있는길이면
			{
				Q.push(make_pair(nX, nY));  //다음값 Q에 넣고
				visited[nX][nY] = 1;        //방문처리
				visited[nX][nY] = visited[X][Y] + 1;  //★현재 방문위치 = 이전방문한위치 + 1★ 
				
			}


		}
	}
	



}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%1d", &miro[i][j]); //한자리로 입력받고
		}
	}

	BFS(1, 1, N, M); //BFS돌림

	printf("%d", visited[N][M]); //마지막에 출구의 값을 

	system("pause");
	return 0; 
}
```
