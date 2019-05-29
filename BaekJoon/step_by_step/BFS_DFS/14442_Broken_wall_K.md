![Capture](https://user-images.githubusercontent.com/29946480/58564610-8c454580-822d-11e9-8d0d-b161438456ae.PNG)
---------------------------------------------------------------------------------------
### ↓↓↓ 시간초과... 는 왜나는걸까.
--------------------------------------------------------------------------------------

```c
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

queue <pair<pair<int, int>,int>> Q;

int map[1000][1000];
int visit[1000][1000][10];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int N, M;

int BFS(int K) {

	visit[0][0][K] = 1;
	Q.push(make_pair(make_pair(0, 0), K));

	while (!Q.empty())
	{
		int X = Q.front().first.first;
		int Y = Q.front().first.second;
		int canbroken = Q.front().second;
		Q.pop();

		if (X == N - 1 && Y == M - 1)
			return visit[N-1][M-1][canbroken];

		for (int i = 0; i < 4; i++)
		{
			int nx = X + dx[i];
			int ny = Y + dy[i];

			if (nx<0 || ny<0 || nx > N - 1 || ny > M - 1)continue;
			if (map[nx][ny] == 0 && visit[nx][ny][canbroken] == 0)
			{
				Q.push(make_pair(make_pair(nx, ny),canbroken));
				visit[nx][ny][canbroken] = visit[X][Y][canbroken] + 1;
			}
			if (map[nx][ny] == 1 && canbroken > 0)
			{
				
				Q.push(make_pair(make_pair(nx, ny), canbroken-1));
				visit[nx][ny][canbroken-1] = visit[X][Y][canbroken] + 1;
			}
		}

	}
	return -1;
}

int main()
{
	int i, j, K;

	scanf("%d %d %d", &N, &M, &K);
	

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	

	int result = BFS(K);

	
	printf("%d",result);

	system("pause");
	return 0;
}
```
--------------------------------------------------------------------------------------------------------------
### 구조체를 이용하여 맞은 코드

- 아래의 코드에서 밑의 코드의 조건문을

if (map[nx][ny] == 0 && visit[nx][ny][broke] == 0) 
{
		visit[nx][ny][broke] = visit[curx][cury][broke] + 1;
		Q.push({ nx,ny,broke });
}
if (map[nx][ny] == 1 && nbroke <= K && visit[nx][ny][nbroke] == 0) 
{
		Q.push({ nx,ny,nbroke });
		visit[nx][ny][nbroke] = visit[curx][cury][broke] + 1;
}

아래와 같이 해주면 왜 메모리초과가날까....................
뭔차이지...

if(visit[nx][ny][broke] != 0 && visit[nx][ny][nbroke] != 0)continue;
if(map[nx][ny] == 0)
  ...
if(map[nx][ny] == 1 && nbroke <= K)
  ...
-------------------------------------------------------------------------------------------------------------
```c
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

int map[1001][1001];
int visit[1001][1001][11]; //런타임에러 방지 배열 한 개씩 더 지정해줌.
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int N, M, K;

struct point {       //구조체! 정확한 의미는 아직...
	int curx;
	int cury;
	int broke;
};

queue<point>Q;    //큐를 구조체로 묶어서 지정.

int BFS() {         //기준은 벽을 깨지 않았을때! 벽을 깰때마다 +1씩해줌!!

	//visit[1][1][0] = 1;
	Q.push({ 1,1,0 });
	for (int i = 0; i <= K; i++) visit[1][1][i] = 1; //이렇게 해도되고 위에 visit[1][1][0] = 1;이렇게 해줘도됨.

	while (!Q.empty()) {
	
		int curx = Q.front().curx;
		int cury = Q.front().cury;
		int broke = Q.front().broke;
		Q.pop();

		if (curx == N && cury == M)            //도착지점에 왔을때의 값을 출력.
			return visit[N][M][broke];

		for (int i = 0; i < 4; i++)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			int nbroke = broke + 1;   //벽을 깨야할 상황에서 이용

			if (nx < 1 || ny < 1 || nx > N || ny > M) continue; //범위 벗어나면 continue로 아래코드실행.

			if (map[nx][ny] == 0 && visit[nx][ny][broke] == 0) //만약 벽이 없고, 방문하지 않았다면
			{
				visit[nx][ny][broke] = visit[curx][cury][broke] + 1;
				Q.push({ nx,ny,broke });
			}
			if (map[nx][ny] == 1 && nbroke <= K && visit[nx][ny][nbroke] == 0) //벽이있고, 방문하지 않았고, 
			                                                                    //벽을 깰수 있는 수가 남아있다면
			{
				Q.push({ nx,ny,nbroke });
				visit[nx][ny][nbroke] = visit[curx][cury][broke] + 1;
			}
		}
	
	}

	return -1; //도착지점에 도달하지 못하면 -1리턴

}

int main() {

	int i, j;
	scanf("%d %d %d", &N, &M, &K);

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	printf("%d", BFS());
	
	return 0;
}
```
