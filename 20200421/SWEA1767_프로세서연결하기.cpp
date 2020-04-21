//시간초과.. 감시풀고 다시도전

#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;


struct info { int x, y; };
int T,N,Size;
int Map[20][20];
int Cpy[20][20];
vector<info>Core;
set<int>Result;
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };

void init_All();
void Select_method(int cnt, string method);
void draw_line(string method);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int q = 1; q <= T; q++) 
	{
		init_All();

		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> Map[i][j];
				if (i > 1 && j > 1 && i < N && j < N && Map[i][j] == 1)
				{
					Core.push_back({ i,j });
				}
			}
		}

		Size = Core.size();
		Select_method(0, "");

		set<int>::iterator iter;
		for (iter = Result.begin(); iter != Result.end(); iter++)
		{
			cout << '#' << q << ' ' << *iter << endl;
			break;
		}	
	}
	
	return 0;
}

void Select_method(int cnt, string method)
{
	
	if (cnt == Size)
	{
		draw_line(method);
		return;
	}

	for (int i = 1; i <= 4; i++) //0선택안함, 1~4방향
	{
		Select_method(cnt + 1, method + to_string(i));
	}
}

void draw_line(string method)
{
	memcpy(Cpy, Map, sizeof(Map));
	//cout << method << endl;
	int hap = 0;
	int cnt = Size;
	for (int i = 0; i < method.length(); i++)
	{
		int cx = Core[i].x;
		int cy = Core[i].y;
		int cd = method[i]-'0';
		
		if (cd == 1)
		{
			int nx = cx+dx[cd];
			int ny = cy+dy[cd];

			if (nx<1 || ny<1 || nx>N || ny>N|| Cpy[nx][ny]==1)return;
			while (Cpy[nx][ny] == 0)
			{
				Cpy[nx][ny] = 1;
				hap++;
				nx += dx[cd];
				ny += dy[cd];
				if (nx <= 0 || ny <= 0 || nx > N || ny > N)
				{
					cnt--;
					break;
				}
			}
			
			continue;
		}
		else if (cd == 2)
		{
			int nx = cx + dx[cd];
			int ny = cy + dy[cd];

			if (nx<1 || ny<1 || nx>N || ny>N || Cpy[nx][ny] == 1)return;
			while (Cpy[nx][ny] == 0)
			{
				Cpy[nx][ny] = 1;
				hap++;
				nx += dx[cd];
				ny += dy[cd];
				if (nx <= 0 || ny <= 0 || nx > N || ny > N)
				{
					cnt--;
					break;
				}
			}
			
			continue;
		}
		else if (cd == 3)
		{
			int nx = cx + dx[cd];
			int ny = cy + dy[cd];

			if (nx<1 || ny<1 || nx>N || ny>N || Cpy[nx][ny] == 1)return;
			while (Cpy[nx][ny] == 0)
			{
				Cpy[nx][ny] = 1;
				hap++;
				nx += dx[cd];
				ny += dy[cd];
				if (nx <= 0 || ny <= 0 || nx > N || ny > N)
				{
					cnt--;
					break;
				}
			}
			continue;
		}
		else if (cd == 4)
		{
			int nx = cx + dx[cd];
			int ny = cy + dy[cd];

			if (nx<1 || ny<1 || nx>N || ny>N || Cpy[nx][ny] == 1)return;
			while (Cpy[nx][ny] == 0)
			{
				Cpy[nx][ny] = 1;
				hap++;
				nx += dx[cd];
				ny += dy[cd];
				if (nx <= 0 || ny <= 0 || nx > N || ny > N)
				{
					cnt--;
					break;
				}
			}
			
			continue;
		}
	}
	
	if (hap > 0 && cnt == 0)
		Result.insert(hap);
	
}

void init_All()
{
	N = 0;
	memset(Map, 0, sizeof(Map));
	memset(Cpy, 0, sizeof(Cpy));
	Core.clear();
	Result.clear();
}
