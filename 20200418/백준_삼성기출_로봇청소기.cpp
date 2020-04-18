#include<iostream>
#include<queue>

using namespace std;

struct Robot { int x, y, d; };
int N, M;
int Map[55][55];
bool check[55][55];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int bx[] = { 1,0,-1,0 };
int by[] = { 0,-1,0,1 };

queue<Robot>Q;

int change(int d);
void Play();

int main()
{
	Robot R;
	cin >> N >> M;
	cin >> R.x >> R.y >> R.d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
		}
	}

	Q.push({ R.x,R.y,R.d });
	Play();

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (check[i][j] == 1)cnt++;
		}
	}

	cout << cnt << endl;
	return 0;
}

void Play()
{
	while (!Q.empty())
	{
		bool cant = false;

		int cx = Q.front().x;
		int cy = Q.front().y;
		int cd = Q.front().d;
		check[cx][cy] = true;
		
		Q.pop();

		int nd = cd;
		for (int i = 0; i < 4; i++)
		{
			nd = change(nd);
			int nx = cx + dx[nd];
			int ny = cy + dy[nd];
			

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
			if (Map[nx][ny] == 0 && !check[nx][ny])
			{
				cant = true;
				Q.push({ nx,ny,nd });
				break;
			}
			else if (Map[nx][ny] == 1) continue;		
		}

		if (!cant) {

			int backx = cx + bx[cd];
			int backy = cy + by[cd];

			if (backx < 0 || backy < 0 || backx >= N || backy >= M) continue;
			if (Map[backx][backy] == 0 )
			{
				Q.push({ backx,backy,cd });
			}
		}
	}
	
}

int change(int d)
{
	if (d == 0)return 3;
	else if (d == 1)return 0;
	else if (d == 2)return 1;
	else if (d == 3)return 2;
}
