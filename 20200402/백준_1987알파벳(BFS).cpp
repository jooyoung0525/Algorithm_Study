#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct info2 { int num; string S; };
struct info { int x, y; char c; };

char map[30][30];
info2 Result[25][25];

int R, C;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

queue<info>Q;

int BFS();
bool Check(string now, char next);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;

	string initS = "";
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			Result[i][j] = { 0,initS };
		}
	}


	Q.push({ 0,0, map[0][0]});
	Result[0][0] = { 1,Result[0][0].S+map[0][0]};

	cout << Result[0][0].S << endl;
	cout << BFS() << endl;
	

	return 0;
}

int BFS()
{
	while (!Q.empty())
	{
		int cx = Q.front().x;
		int cy = Q.front().y;
		char now = Q.front().c;
		
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			char next = map[nx][ny];
			
			if (nx < 0 || ny < 0 || nx >= R || ny >= C)continue;
			if (Result[nx][ny].num==0)
			{
				if (Check(Result[cx][cy].S, next)) {
					Q.push({ nx,ny,next });
					Result[nx][ny].num = Result[cx][cy].num + 1;
					Result[nx][ny].S = Result[cx][cy].S + next;
				}
			}
		}
	}
	cout << endl;
	
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << Result[i][j].S<<" ";
			
		}
		cout << endl;
	}
	cout << endl;
	int MMax = -1;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout<< Result[i][j].num;
			if (MMax < Result[i][j].num) MMax = Result[i][j].num;
		}
		cout << endl;
	}
	
	return MMax;
}


bool Check(string now, char next)
{
	for (int i = 0; i < now.length(); i++)
	{
		if (now[i] == next) return false;
	}

	return true;
}

