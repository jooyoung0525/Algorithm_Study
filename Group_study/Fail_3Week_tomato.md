
![kakaotalk_20190130_184832342](https://user-images.githubusercontent.com/29946480/51972858-ba08c080-24bf-11e9-8c4d-d873052f0f53.jpg)

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
