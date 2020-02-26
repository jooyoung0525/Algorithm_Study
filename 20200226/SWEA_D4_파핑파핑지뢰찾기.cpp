/*
<<접근방법>>
1. 지뢰가없는 모든자리에 값을 구한다
2. 빈자리중 0인자리를 벡터에 넣는다 --> 0인자리는 8방향이자동으로 채워지기때문
3. 벡터사이즈만큼 좌표하나씩 Playclick을 실행한다(Playclick은 bfs로 8방향으로 퍼지는함수, 이때 다음칸도 0일경우 큐에넣어서 또 퍼트려야함)
4. 채워지지않은칸을 세서 결과값을 구한다

*/

#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int T, N;
int Clicknum = 0;
struct info { int x, y; };
vector<string>Map;
bool visit[350][350];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
vector<info>V;
queue<info>Q;

void FindBomb();
void Playclick(int x, int y);

int main()
{
	cin >> T;
	for (int q = 1; q <= T; q++)
	{
		//초기화
		memset(visit, false, sizeof(visit));
		Clicknum = 0;
		while (!Q.empty())
		{
			Q.pop();
		}
		Map.clear();
		V.clear();
		N = 0;

		//입력
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			string a;
			cin >> a;
			Map.push_back(a);
		}

		FindBomb();
	
		for (int i = 0; i < V.size(); i++)
		{
			int x = V[i].x; int y = V[i].y;
			if (visit[x][y] == true)continue;
			Playclick(x, y);
			Clicknum++;
		}
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visit[i][j] == false)Clicknum++;
			}
		}
		
		
		cout <<'#'<<q<<' '<<Clicknum << endl;
	}

	return 0;
}

void FindBomb()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int cnt = 0;
			if (Map[i][j] == '*')visit[i][j] = true;
			if (Map[i][j] == '.')
			{
				for (int k=0; k<8; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
					if (Map[nx][ny] == '*')
						cnt++;
				}
				Map[i][j] = cnt + '0';
				if (cnt == 0) V.push_back({ i,j });
			}
			
		}
	}
}

void Playclick(int x, int y)
{
	visit[x][y] = true;
	Q.push({ x,y });
	
	while (!Q.empty()) 
	{
		int cx = Q.front().x;
		int cy = Q.front().y;
		Q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;

			if (visit[nx][ny] == false && Map[nx][ny] != '*') {
				visit[nx][ny] = true;
				if (Map[nx][ny] == '0') Q.push({ nx,ny });
			}
		}
	}

}
