//런타임에러남 큐가 오버플로우 된듯..
//무한반복 --> 큐 오버플로우 --> DFS로 구현해야할듯


#include<iostream>
#include<string>
#include<queue>
#include<cstring>

using namespace std;

struct info { int x, y, dir, order, time; };
int T,R,C;
int memory;
bool check[25][25][4][16];
char map[25][25];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
queue<info>Q;

string Play();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int q = 1; q <= T; q++)
	{
		memory = 0;
		while (!Q.empty())
		{
			Q.pop();
		}
		memset(map, '\0', sizeof(map));
		memset(check, '\0', sizeof(check));

		cin >> R >> C;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; i < C; j++)
			{
				cin>>map[i][j];
			}
		}
	
		Q.push({ 0,0,1,map[0][0],1});
		check[0][0][1][memory] = true;
		string ans = Play();

		cout<<ans<<"\n";
	}
	return 0;
}

string Play()
{
	while (!Q.empty())
	{
		int cx = Q.front().x;
		int cy = Q.front().y;
		int cd = Q.front().dir;
		char order = Q.front().order;
		int time = Q.front().time;
		Q.pop();

		if (time > 10000 || order == '.') return "NO";
		if (order == '@') return "YES";
		
		if (order == '0' || order == '1' || order == '2' || order == '3' || order == '4' || order == '5' || order == '6' || order == '7' || order == '8' || order == '9')
		{
			int nx = cx + dx[cd];
			int ny = cy + dy[cd];
			int nd = cd;
			memory = order - '0';

			if (check[nx][ny][nd][memory] == true)continue;
			check[nx][ny][nd][memory] = true;
			Q.push({ nx,ny,nd,map[nx][ny],time++ });
		}

		else if (order == '-')
		{
			int nx = cx + dx[cd];
			int ny = cy + dy[cd];
			int nd = cd;
			if (memory == 0) memory = 15;
			else memory--;

			if (check[nx][ny][nd][memory] == true)continue;
			check[nx][ny][nd][memory] = true;
			Q.push({ nx,ny,nd,map[nx][ny],time++ });
		}

		else if (order == '+')
		{
			int nx = cx + dx[cd];
			int ny = cy + dy[cd];
			int nd = cd;
			if (memory == 15) memory = 0;
			else memory++;

			if (check[nx][ny][nd][memory] == true)continue;
			check[nx][ny][nd][memory] = true;
			Q.push({ nx,ny,nd,map[nx][ny],time++ });
		}

		else if (order == '<')
		{
			int nd = 3;
			int nx = cx + dx[nd];
			int ny = cy + dy[nd];

			if (ny < 0) ny = C - 1;

			if (check[nx][ny][nd][memory] == true)continue;
			check[nx][ny][nd][memory] = true;
			Q.push({ nx,ny,nd,map[nx][ny],time++ });
		}

		else if (order == '>')
		{
			int nd = 1;
			int nx = cx + dx[nd];
			int ny = cy + dy[nd];

			if (ny >= C) ny = 0;

			if (check[nx][ny][nd][memory] == true)continue;
			check[nx][ny][nd][memory] = true;
			Q.push({ nx,ny,nd,map[nx][ny],time++ });
		}

		else if (order == '^')
		{
			int nd = 0;
			int nx = cx + dx[nd];
			int ny = cy + dy[nd];

			if (nx<0) nx = R-1;

			if (check[nx][ny][nd][memory] == true)continue;
			check[nx][ny][nd][memory] = true;
			Q.push({ nx,ny,nd,map[nx][ny],time++ });
		}
		else if (order == 'v')
		{
			int nd = 2;
			int nx = cx + dx[nd];
			int ny = cy + dy[nd];

			if (nx >= R) nx = 0;

			if (check[nx][ny][nd][memory] == true)continue;
			check[nx][ny][nd][memory] = true;
			Q.push({ nx,ny,nd,map[nx][ny],time++ });
		}

		else if (order == '_')
		{
			int nd = cd;

			if (memory == 0) nd = 1;
			else nd = 3;

			int nx = cx + dx[nd];
			int ny = cy + dy[nd];

			if (ny >= C) ny = 0;
			else if (ny < 0) ny = C - 1;

			if (check[nx][ny][nd][memory] == true)continue;
			check[nx][ny][nd][memory] = true;
			Q.push({ nx,ny,nd,map[nx][ny],time++ });
		}

		else if (order == '|')
		{
			int nd = cd;

			if (memory == 0) nd = 2;
			else nd = 0;

			int nx = cx + dx[nd];
			int ny = cy + dy[nd];

			if (nx >= R) nx = 0;
			else if (nx < 0) nx = R - 1;

			if (check[nx][ny][nd][memory] == true)continue;
			check[nx][ny][nd][memory] = true;
			Q.push({ nx,ny,nd,map[nx][ny],time++ });
		}

		else if (order == '?')
		{
			for (int k = 0; k < 4; k++)
			{
				int nx = cx + dx[k];
				int ny = cy + dy[k];

				if (ny >= C) ny = 0;
				else if (ny < 0) ny = C - 1;

				if (nx >= R) nx = 0;
				else if (nx < 0) nx = R - 1;

				if (check[nx][ny][k][memory] == true)continue;
				check[nx][ny][k][memory] = true;
				Q.push({ nx,ny,k,map[nx][ny],time++ });
			}
		}

	}
}
