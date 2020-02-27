/*
<< 접근 방법 >>
1. 바깥공기를 BFS이용해 -1로 만듦(치즈안의 공기와 다르게 만들라고)
2. BFS돌릴때, 다음위치가 치즈이면 공기와 맞닿은 치즈이니까 치즈큐에 넣어줌 (다음턴에선 공기가됨)
3. 치즈큐를 공기큐에 복사 (다음턴에서 공기가되므로)
4. 치즈큐에 담긴 좌표를 공기로 바꿔주고
5. 치즈가 없어질때까지 계속 반복
*/

#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

struct info { int x, y; };
int N, M, Count;
int Map[110][110];
int visit[110][110];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<info>Air;
queue<info>Cheeze;


void Spread_Air();
void Melt_cheeze();
bool stop();
int before_Lasttime();

int main()
{
	memset(visit, -1, sizeof(visit));

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
		}
	}

	Air.push({ 0,0 });
	Map[0][0] = -1;

	while (1)
	{
		Count++;
		Spread_Air();
		Melt_cheeze();
		if (stop())break;
	}

	cout << Count << endl;
	int Ans = before_Lasttime();
	cout << Ans << endl;
	return 0;
}

void Spread_Air()
{
	while (!Air.empty())
	{
		int cx = Air.front().x;
		int cy = Air.front().y;
		Air.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
			if (visit[nx][ny] == -1)
			{
				if (Map[nx][ny] == 0)
				{
					Map[nx][ny] = -1;
					visit[nx][ny] = 0;
					Air.push({ nx,ny });
				}
				else if (Map[nx][ny] == 1)
				{
					Cheeze.push({ nx,ny });
				}
			}
		}
	}
}

void Melt_cheeze()
{
	while (!Air.empty())
	{
		Air.pop();
	}

	Air = Cheeze;

	while (!Cheeze.empty())
	{
		int cx = Cheeze.front().x;
		int cy = Cheeze.front().y;
		Cheeze.pop();

		Map[cx][cy] = -1;
		visit[cx][cy] = Count;
	}

	while (!Cheeze.empty())
	{
		Cheeze.pop();
	}
}

bool stop()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Map[i][j] == 1)return false;
		}
	}
	return true;
}

int before_Lasttime()
{
	int num = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] == Count)
				num++;
		}
	}
	return num;
}
