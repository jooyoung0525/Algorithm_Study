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
			if (visit[nx][ny] == -1) //방문안했고
			{
				if (Map[nx][ny] == 0)//다음이 공기이면
				{
					Map[nx][ny] = -1; //바깥공기표시
					visit[nx][ny] = 0; //방문표시
					Air.push({ nx,ny }); //퍼트림
				}
				else if (Map[nx][ny] == 1) //다음이 치즈이면
				{
					Cheeze.push({ nx,ny }); //치즈큐에 넣음
				}
			}
		}
	}
}

void Melt_cheeze()
{
	while (!Air.empty()) //큐 복사위해 초기화
	{
		Air.pop();
	}

	Air = Cheeze; //다음턴에서 현재 치즈가 녹아서 바깥공기가되므로 Air큐에 복사

	while (!Cheeze.empty())
	{
		int cx = Cheeze.front().x;
		int cy = Cheeze.front().y;
		Cheeze.pop();

		Map[cx][cy] = -1; //치즈가 공기가됨
		visit[cx][cy] = Count; //몇초에 녹았는지 방문배열에 표시
	}

	while (!Cheeze.empty()) //다음턴위해 초기화
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
			if (Map[i][j] == 1)return false; //치즈가있으면 false
		}
	}
	return true;//치즈가없으면 true
}

int before_Lasttime()
{
	int num = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) 
		{
			if (visit[i][j] == Count) //치즈가 녹은 시간에서 치즈의 갯수
				num++;
		}
	}
	return num;
}
