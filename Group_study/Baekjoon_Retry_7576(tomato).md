
### 행, 열 주의!!!!!!제발~!!!
------------------------------------------------------------------------------------------------------------------------

# *max_element(시작점,시작점+끝점)

### → algorithm 선언 후 사용가능.

### → 행으로만 max값을 비교할 수 있음 ( 열끼리 max값 비교 불가 )

--------------------------------------------------------------------------------------------------------------------------
```c

#include<cstdio>
#include<cstdlib>
#include<queue>
#include<algorithm>


using namespace std;

queue<pair<int, int>>Q;

int tomato[1100][11000] = { 0 };
int visit[1100][1100] = { 0 };
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int result(int M, int N)
{
	int row_MAX[1500];
	int col_MAX;
	int cnt = 0;

// max_element쓰는법 잘알기!!!! 여기서 또 시간잡아먹음...

	for (int i = 0; i < N; i++)
	{
		row_MAX[i] = *max_element(visit[i], visit[i]+M);
		//printf("%d ", row_MAX[i]);
	}
	//printf("\n");
	
	col_MAX = *max_element(row_MAX, row_MAX + N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (tomato[i][j] == 0)
			{
				cnt++;
			}
			if (visit[i][j] == 0 && tomato[i][j] == 0)
				return -1;


		}
	}
	printf("\n");
	printf("%d\n", cnt);
	printf("\n");
	if (cnt <= 0)
		return 0;
	else
	{
		return col_MAX-1;
	}



}


void BFS(int M, int N)
{
	while (!Q.empty())
	{
		int X = Q.front().first;
		int Y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = X + dx[i];
			int ny = Y + dy[i];

			if (nx <= -1 || ny <= -1 || nx >= N || ny >= M) continue;
			if (visit[nx][ny] == 0)
			{
				if (tomato[nx][ny] == 0)
				{
					Q.push(make_pair(nx, ny));
					visit[nx][ny] = 1;
					visit[nx][ny] = visit[X][Y] + 1;
				}
				if (tomato[nx][ny] == -1) //토마토가 빈칸(-1값)은 visit도 빈칸(-1값)으로 ( 예외처리 쉽게 )
					visit[nx][ny] = -1;
			}


		}


	}


}

int main()
{
	int M, N, i, j;

	scanf("%d %d", &M, &N);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &tomato[i][j]);
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (tomato[i][j] == 1)
			{
				Q.push(make_pair(i, j)); //시작점은 BFS함수 실행전에 이 코드로 queue에 push함으로
				                         // 따로 BFS함수에서 시작점을 줄 필요가 없다.
							 // 시작점을 이렇게 먼저 push하는 이유는 모두 다 익은 토마토의 최소값을 구하기 위해.
				visit[i][j] = 1;
			}
			if (tomato[i][j] == -1)  //토마토가 빈칸은 visit도 빈칸으로 ( 예외처리 쉽게 )
				visit[i][j] = -1;
		}
	}



	BFS(M, N);
  
/*
  디버깅 
	printf("\n");

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}
	printf("\n");
  */
  
	printf("%d", result(M, N));
  
//	printf("\n");

	return 0;
}


```
