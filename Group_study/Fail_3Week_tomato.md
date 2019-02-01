
# C/C++ 입력 꿀팁

### 1. cin이 편할 떄

   ***※ 주의) cin 은 using namespace std; 써 줘야함***

- 1 0 1 0 1 1 이렇게 숫자 사이에 공백있을때! --> 알아서 공백 인식해서 입력받음

- Cin 으로 입력받으면 입력받은 변수타입으로 알아서 맞춰 

    ***ex) scanf(" %d",&a); scanf처럼 공백을 입력해서 안받아도됨***

- cin으로 101011통으로 입력받으면 하나의 변수에 101011이 통으로 들어가기 때문에 루프돌면서 한개씩 잘라줘야함.



### 2. scanf가 편할 때

- 101011를 한개씩 입력 받아야 할 떄!     -->     ***scanf("%1d",&a);***

------------------------------------------------------------------------------------------------------------------

# system("pause"); 안써도 되는법!

1. 메뉴의 프로젝트 -> '프로젝트이름'속성

2. 구성속성 -> 링커 -> 시스템 -> 하위시스템 -> 콘솔선택

------------------------------------------------------------------------------------------------------------------
# 처음 시도 - 실패

```c
#include<cstdio>
#include<cstdlib>
#include<queue>
#include <iostream>

using namespace std;

int tomato[1100][1100] = { 0 , };
int visited[1100][1100] = { 0, };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };


queue<pair<int,int>> Q;

void BFS (int curx, int cury, int M, int N )
{
	
	Q.push(make_pair(curx, cury));
	visited[curx][cury] = 1;

	while (!Q.empty())
	{
		int X = Q.front().first;
		int Y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = X + dx[i];
			int ny = Y + dy[i];

			if (nx <= -1 || nx > M || ny <= -1 || ny > N) continue;

			if (visited[nx][ny] == 0 && tomato[nx][ny] == 0)
			{
					Q.push(make_pair(nx, ny));
					visited[nx][ny] = 1;
					visited[nx][ny] = visited[X][Y] + 1;

			}

			
		}


	}

	
}

int main()
{
	int M, N;
	//scanf("%d %d", &M, &N);
	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			//scanf("%d ", &tomato[i][j]);
			cin >> tomato[i][j];
		}
	}

	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (tomato[i][j] == 1)
			{
				BFS(i, j, M, N);
			}
		}
	}

	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
	
	//system("pause");
	return 0;
}
```
----------------------------------------------------------------------------------------------------------------------
# 두번째 시도 - 예외처리 빼고 성공! 

**(토마토가 모두 익지 못하면 -1, 모두 익어있는 상태면 0 출력)**

```c
#include<cstdio>
#include<cstdlib>
#include<queue>
#include <iostream>
#include<algorithm>

using namespace std;

int tomato[1100][1100] = { 0 , };
int visited[1100][1100] = { 0, };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };



queue<pair<int,int>> Q;

void BFS (int curx, int cury, int M, int N )
{
	
	//Q.push(make_pair(curx, cury));
	//visited[curx][cury] = 1;

	while (!Q.empty())
	{
		int X = Q.front().first;
		int Y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = X + dx[i];
			int ny = Y + dy[i];

			if (nx <= -1 || nx > M || ny <= -1 || ny > N) continue;

			if (visited[nx][ny] == 0 && tomato[nx][ny] == 0)
			{
					Q.push(make_pair(nx, ny));
					visited[nx][ny] = 1;
					visited[nx][ny] = visited[X][Y] + 1;

			}

			
		}


	}

	
}

int main()
{
	int M, N;
	int MAX[1000];
	//scanf("%d %d", &M, &N);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			//scanf("%d ", &tomato[i][j]);
			cin >> tomato[i][j];
		}
	}

	

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (tomato[i][j] == 1)
			{
				Q.push(make_pair(i, j));
				visited[i][j] = 1;
			}
			
		}
	}

	BFS(0, 0, M, N);
	
	
	
	for (int i = 0; i < M; i++) {
		
		MAX[i] = *max_element(visited[i], visited[i]+N);
		
	}

	int MAX2 = *max_element(MAX, MAX + N);

	printf("%d\n", MAX2-1);
	
	

	//system("pause");
	return 0;
}
```
