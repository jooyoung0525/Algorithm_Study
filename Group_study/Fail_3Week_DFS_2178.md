# DFS (Depth-First-Search  깊이우선탐색)
-----------------------------------------------------------------------------------------------------------------------------

### 개념

- **DFS** : 현재 정점에서 갈 수 있는 점들까지 들어가면서 탐색
- **BFS** : 현재 정점에 연결된 가까운 점들부터 탐색

### 방법

- **DFS** : 스택 또는 재귀함수로 구현
- **BFS** : 큐를 이용해서 구현

-----------------------------------------------------------------------------------------------------------------------------

## [Stack Library]
	
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

	
	
-----------------------------------------------------------------------------------------------------------------------------

![2178](https://user-images.githubusercontent.com/29946480/51797612-e1565800-2249-11e9-9881-c0d5b151bdc6.JPG)

-----------------------------------------------------------------------------------------------------------------------------

### 첫번째 시도(실패)

```c
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;

int miro[100][100];
//stack <pair<int,int>> S;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int check = 0;

void DFS(int curx,int cury,int N, int M)
{
	if (miro[curx][cury] != 0)
		check++;
	else
	{
		for (int i = 0; i < 4; i++) {
			int nextx = curx + dx[i];
			int nexty = cury + dy[i];
			if( nextx > 0 || nexty > 0 || nextx < N ||nexty < M )
				DFS(nextx,nexty,N,M);
		}
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

	DFS(0,0,N,M);

	printf("%d", check);

	system("pause");
	return 0;
}
```
-----------------------------------------------------------------------------------------------------------------------------

### 두번째시도 -  stack이용하려함 (실패)

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
