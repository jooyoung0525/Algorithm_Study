# DFS (Depth-First-Search  깊이우선탐색)
-----------------------------------------------------------------------------------------------------------------------------

### 개념

1. DFS : 현재 정점에서 갈 수 있는 점들까지 들어가면서 탐색
2. BFS : 현재 정점에 연결된 가까운 점들부터 탐색

### 방법

1. DFS : 스택 또는 재귀함수로 구현
2. BFS : 큐를 이용해서 구현

-----------------------------------------------------------------------------------------------------------------------------

## Stack Library
	
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

	
	


![2178](https://user-images.githubusercontent.com/29946480/51797612-e1565800-2249-11e9-9881-c0d5b151bdc6.JPG)

-----------------------------------------------------------------------------------------------------------------------------
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
