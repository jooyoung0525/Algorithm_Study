![algospot](https://user-images.githubusercontent.com/29946480/62697664-7c8b6f80-b9db-11e9-8fcc-e8b854086e2d.PNG)
---------------------------------------------------------------------------------------------------------------------
### Deque(덱)

- queue와 비슷하지만, queue와는 다르게 양쪽으로 push,pop가능
- BFS는 가중치가1일 경우에는 쉽게쓰이지만 문제와 같이 가중치 값이 서로 다를경우 deque를 써서 풀어야함
- 가중치 값에 따라서 앞에 push할지 뒤에 push할지 기준을 정한다음 풀어야함.
------------------------------------------------------------------------------------------------------------------------
```c
#include<cstdio>
#include<cstdlib>
#include<deque>
using namespace std;

int map[101][101] = { 0 };
int visit[101][101] = { 0 };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

deque<pair<pair<int, int>,int>> Q;

int BFS(int N, int M)
{
	int min = 100000;
	visit[0][0] = 1;
	Q.push_back({ {0,0},0 });

	while (!Q.empty())
	{
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int wall = Q.front().second;
				
		if (x == N - 1 && y == M - 1)
		{
			return wall;
		}
			

		Q.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
			if (visit[nx][ny] == 0) {
				if (map[nx][ny] == 0) {
					visit[nx][ny] = 1;
					Q.push_front({ {nx,ny},wall });
				}
				else {
					Q.push_back({ {nx,ny},wall+1 });
					visit[nx][ny] =  1;
				}
			}
		}

	}

}

int main()
{
	int N, M;

	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	
	printf("%d", BFS(N, M));

	return 0;
}
```
