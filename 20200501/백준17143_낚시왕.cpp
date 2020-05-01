#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

struct info { int x, y, speed, dir, size; bool death; };
vector<info>Shark;
int R, C, M, Catch;
int Map[110][110];//상어벡터 인덱스이용해 움직이는 상어 정보저장
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,1,-1 };

void Fishing(int idx);
void Move();
int changeD(int cd);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	memset(Map, -1, sizeof(Map));

	cin >> R >> C >> M;
	for (int i = 0; i < M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		Shark.push_back({ r,c,s,d,z,false });
		Map[r][c] = i;
	}

	for (int i = 1; i <= C; i++)
	{
		Fishing(i);
		Move();
	}

	cout << Catch;

	return 0;
}


void Fishing(int idx)
{
	/*
	cout << "BEFORE" << endl;
	cout << "\n";
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}*/

	for (int i = 1; i <= R; i++)
	{
		if (Map[i][idx] >= 0)
		{
			int curidx = Map[i][idx];
			Catch += Shark[curidx].size;
			Shark[curidx].death = true;
			break;
		}
	}

}

void Move()
{
	memset(Map, -1, sizeof(Map));

	for (int i = 0; i < Shark.size(); i++)
	{
		if (Shark[i].death == true)continue;

		int cx = Shark[i].x;
		int cy = Shark[i].y;
		int speed = Shark[i].speed;
		int cdir = Shark[i].dir;
		int csize = Shark[i].size;

		//cout << cx << " " << cy << " " << speed << " " << cdir << " " << csize << endl;

		if ((cdir == 1 || cdir == 2) && speed >= R)
		{
			speed %= ((R - 1) * 2);
		}
		else if((cdir == 3 || cdir == 4) && speed >= C)
		{
			speed %= ((C - 1) * 2);
		}

		int nx = cx;
		int ny = cy;
		int nd = cdir;
		while (speed--)
		{
			if (nx + dx[nd] < 1 || nx + dx[nd]> R || ny + dy[nd]< 1 || ny + dy[nd]>C)
			{
				nd = changeD(nd);
			}
			nx += dx[nd];
			ny += dy[nd];

			//cout << "speed " << speed << "\n";
			//cout << "nx " << nx << " ny " << ny << " nd " << nd << "\n";
		}
		//cout << "nx " << nx << " ny " << ny << " nd " << nd << "\n";
		if (Map[nx][ny] == -1)
		{
			Map[nx][ny] = i;
			Shark[i].x = nx; Shark[i].y = ny; Shark[i].dir = nd;
		}
		else if(Map[nx][ny]>=0)
		{
			int cmpsize = Shark[Map[nx][ny]].size;
			if (cmpsize < csize)
			{
                Shark[Map[nx][ny]].death = true;
				Map[nx][ny] = i;
				Shark[i].x = nx; Shark[i].y = ny; Shark[i].dir = nd;
		

			}
			else
				Shark[i].death = true;
		}

		//cout << i << "\n";
	}
}

int changeD(int cd)
{
	if (cd == 1)return 2;
	else if (cd == 2)return 1;
	else if (cd == 3)return 4;
	else if (cd == 4)return 3;
}
