![11](https://user-images.githubusercontent.com/29946480/65238091-ef2d5600-db16-11e9-82a1-206be29c4422.JPG)
![22](https://user-images.githubusercontent.com/29946480/65238092-ef2d5600-db16-11e9-95b7-3dec38440906.JPG)
![33](https://user-images.githubusercontent.com/29946480/65238093-ef2d5600-db16-11e9-84d3-2a7dfe1a9ef4.JPG)


--------------------------------------------------------------------------------------------------
### 풀이1. (틀림 ==> 초기생각) //런타임에러 너무복잡하다!! 다시풀자!!

```c
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, L, R;
int map[55][55] = { 0 };
int visit[55][55] = { 0 };
int checkm[55][55] = { 0 };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct info { int x, y, people; };
queue<info>Q;
queue<info>D;
vector<int>V;

bool Check();
void Yeonhap();
void init();

void Move()
{
	while (!Q.empty())
	{
		int cx = Q.front().x;
		int cy = Q.front().y;
		int cp = Q.front().people;
		visit[cx][cy] = 1;
		V.push_back(cp);
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;

			if (visit[nx][ny] == 0)
			{
				if (abs(map[nx][ny] - cp) <= R && abs(map[nx][ny] - cp) >= L)
				{
					Q.push({ nx,ny,map[nx][ny] });
				}
			}
		}
	}

	Yeonhap();
	
}

int main()
{
	int count = 0;

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	while (!Check()) {
		Q.push({ 0,0,map[0][0] });
		Move();
		count++;
	}

	cout << count;

	//system("pause");
	return 0;
}

void init()
{
	while (!Q.empty())
	{
		Q.pop();
	}

	while (!V.empty())
	{
		V.pop_back();
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = 0;
		}
	}
}

bool Check()
{
	int c = 0;

	D.push({ 0,0,map[0][0] });

	while (!D.empty())
	{
		int cx = D.front().x;
		int cy = D.front().y;
		int cp = D.front().people;
		checkm[cx][cy] = 1;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;

			if (abs(map[nx][ny] - cp) <= R && abs(map[nx][ny] - cp) >= L)
			{
					D.push({ nx,ny,map[nx][ny] });	
			}
		}
	}
	while (!D.empty())
	{
		D.pop();
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (checkm[i][j] == 1) {
				c++;		
			}	
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			checkm[i][j] = 0;
		}
	}

	if (c > 1)
		return true;
	else
		return false;
}

void Yeonhap()
{
	int cnt = V.size();
	int hap = 0;
	int result = 0;

	while (!V.empty())
	{
		hap += V.back();
		V.pop_back();
	}

	result = hap / cnt;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == 1)
			{
				map[i][j] = result;
			}
		}
	}

	init();
}

```
