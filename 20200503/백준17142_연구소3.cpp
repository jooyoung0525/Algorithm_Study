#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

struct info { int x, y, time; };
int Empty;
int MMin = 987654321;
int N, M;
int Map[55][55];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<info>Virus;

void Select(int idx, int cnt, string a);
void SpreadV(string a);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 0)Empty++;
			else if (Map[i][j] == 2) Virus.push_back({ i,j,0 });
		}
	}
	
	if (Empty == 0) cout << 0;
	else
	{
		Select(0, 0, "");

		if (MMin == 987654321)cout << -1;
		else
			cout << MMin;
	}

	return 0;
}

void Select(int idx, int cnt, string a)
{
	if (cnt == M)
	{
		SpreadV(a);
		return;
	}

	for (int i = idx; i < Virus.size(); i++)
	{
		Select(i + 1, cnt + 1, a + to_string(i));
	}
}

void SpreadV(string a)
{
	int check[55][55];
	memset(check, -1, sizeof(check));

	int Stop = Empty;
	queue<info>Q;
	
	for (int i = 0; i < a.length(); i++)
	{
		int idx = a[i] - '0';
		Q.push({ Virus[idx].x,Virus[idx].y,0 });
		check[Virus[idx].x][Virus[idx].y] = 0;
		Map[Virus[idx].x][Virus[idx].y] = -2;
	}

	while (!Q.empty())
	{
		int cx = Q.front().x;
		int cy = Q.front().y;
		int time = Q.front().time;
		Q.pop();
		
		if (Stop == 0)
		{
			int mmax = -1;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					//cout << check[i][j] << " ";
					if (mmax < check[i][j])
						mmax = check[i][j];
				}
				//cout << "\n";
			}

			// << mmax << endl;
			MMin = min(MMin, mmax);

			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
			if (Map[nx][ny] == 0 && check[nx][ny]== -1)
			{
				check[nx][ny] = check[cx][cy]+1;
				Q.push({ nx,ny,time + 1 });
				Stop--;
			}

			else if (Map[nx][ny] == 2 && check[nx][ny]==-1)
			{
				check[nx][ny] = check[cx][cy]+1;
				Q.push({ nx,ny,time + 1 });
			}
		}
	}


	for (int i = 0; i < a.length(); i++)
	{
		int idx = a[i] - '0';
		Map[Virus[idx].x][Virus[idx].y] = 2;
	}
}
