![로봇](https://user-images.githubusercontent.com/29946480/65130686-e23a3500-da38-11e9-94b1-447d804459ed.JPG)

--------------------------------------------------------------------------------------------------------------
## 풀이1. [원래 내가 생각해서 푼거 --> 틀림]

```c
#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

int N, M;
int map[55][55] = {0};
int visit[55][55] = {0};
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int bx[] = { 1,0,-1,0 };
int by[] = { 0,-1,0,1 };

void Back(int x, int y, int dir);

void Clean(int x, int y, int dir)
{
	visit[x][y] = 1;
	int k = 4;
	int d =dir;
	int cnt = 0;
	for(int i = 0; i < 4; i++){

		(dir == 0) ? (dir = 3) : dir-=1 ; //dir로 돌려주면 for문 돌때, dir값이 처음값으로 초기화됨
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue;
		
		if (map[nx][ny] == 0 && visit[nx][ny] == 0)
		{
			Clean(nx, ny, dir); //리턴이빠짐
		}
		cnt++;
	}
	(dir == 0) ? (dir = 3) : dir-=1 ; //따로 후진배열 만드는 방법은 원래방향 그대로쓰면됨!!!
	int backx = x + bx[dir];
	int backy = y + by[dir];
	if (cnt == 4 && map[backx][backy] != 1)
	{
		Clean(backx, backy, dir);
		//visit[backx][backy] = 0;
	}
	return;
}

int main()
{
	int r, c, d;
	int count = 0;
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	Clean(r, c, d);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] == 1)
				count++;
		}
	}
	
	cout << count;

	//system("pause");
	return 0;
}

```

------------------------------------------------------------------------------------------------------

## 풀이2. (dfs풀이 참고해서 해결...)
### ------> return; 이용이랑 재귀 아직도 헷갈림ㅠㅠ

```c
#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

int N, M;
int map[55][55] = {0};
int visit[55][55] = {0};
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
//int bx[] = { 1,0,-1,0 };
//int by[] = { 0,-1,0,1 };

void back(int x, int y, int dir);

void Clean(int x, int y, int dir)
{
	int d = dir;
	
	for(int i = 0; i < 4; i++){ // 4방향 돌면서 탐색

		d = (d + 3) % 4; //기준 방향 왼쪽부터 탐색
		                 // 0 북 1 동 2 남 3 서 ==> 왼쪽방향부터 돌면 3 2 1 0 순서
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M)continue; //범위를 넘지않고
		//if (map[nx][ny] == 1)continue;
		
		if (map[nx][ny] == 0 && visit[nx][ny] == 0) //왼쪽방향에 청소하지 않은 공간이 존재하면
		{
			visit[nx][ny] = 1; //1번.현재위치 청소
			Clean(nx, ny, d); //현재위치 부터 다시 탐색
			return; //이거 꼭 써줘야함!!! 그래야 재귀함수가 끝남
		}
	}
	
	back(x, y, dir); //4방향 모두 청소가 되어있거나 벽인경우 후진
  //return; 있어도 맞고 없어도 맞음
}

int main()
{
	int r, c, d;
	int count = 0;
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	visit[r][c] = 1; //시작위치 청소
	Clean(r, c, d);  //시작위치,방향 기준으로 탐색
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] == 1) //방문했으면 청소한곳이니까 센다.
				count++;
		}
	}
	
	cout << count;

	system("pause");
	return 0;
}


void back(int x, int y, int dir)
{
	//후진이 가능한 경우 == > 벽이아니고 청소가 이미 되었거나, 청소가 되지 않았을경우.

	int d = (dir + 2) % 4; //후진방향 설정 
	                       //0 북 1 동 2 남 3 서 ==> 후진방향 2 3 0 1 순서
	int backx = x + dx[d];
	int backy = y + dy[d];

	if (map[backx][backy] == 1) //후진한곳이 벽이면
	{
		return; //작동을 멈춘다
	}
	else //후진한곳이 벽이아니면
		Clean(backx, backy, dir); //다시 탐색해본다. (이때, 방향은 후진 이전 원래방향대로!)
}
```
-------------------------------------------------------------------------------------------------------

### 풀이 2. BFS
###==> break; continue; return; 제대로 안쓰면 답안나옴 ㅠㅠ

```c
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>

using namespace std;

struct info { int x, y, d; };

queue<info>Q;
int N, M;
int map[55][55] = { 0 };
int visit[55][55] = { 0 };
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int bx[] = { 1,0,-1,0 };
int by[] = { 0,-1,0,1};

int changedir(int dir)
{
	if (dir == 0)return 3;
	else if (dir == 1)return 0;
	else if (dir == 2)return 1;
	else if (dir == 3)return 2;
}

void Clean()
{
	while (!Q.empty()) 
	{
		bool flag = false;
		int cx = Q.front().x;
		int cy = Q.front().y;
		int dir = Q.front().d;
		int nd = dir;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			
			nd = changedir(nd);
			int nx = cx + dx[nd];
			int ny = cy + dy[nd];
			
			
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
			if (map[nx][ny] == 0 && visit[nx][ny] == 0)
			{
				Q.push({ nx,ny,nd });
				visit[nx][ny] = 1;
				flag = true;
				break;
			}
			
		}
		if (!flag) {

			int backx = cx -dx[dir];
			int backy = cy -dy[dir];
			if (backx < 0 || backx >= N || backy < 0 || backy >= M)continue;
			if (map[backx][backy] == 0)
			{
				Q.push({ backx,backy,dir });
				continue;
			}
			else
				return;
			
		}
	}
}

int main()
{
	int r, c, d;
	int count = 0;
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}


	Q.push({ r,c,d });
	visit[r][c] = 1;
	Clean();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] == 1)
				count++;
		}
		
	}

	cout << count;

	system("pause");
	return 0;
}
```
