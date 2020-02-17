#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#define INF 987654321

using namespace std;

struct info{int x, y, cost; 
bool operator < (const info& a)const
{
	return a.cost<cost; //a.cost가 기준! 이렇게 리턴하면 a.cost가 작은순으로 우선순위큐에서 나옴
}
};
int map[150][150];
int cost[150][150];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
priority_queue<info>Q;

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cnt = 1;
	int N = 1;
	while (1)
	{
		memset(map, 0, sizeof(map));
		memset(cost, 0, sizeof(cost));

		cin >> N;
		
		if (N == 0)break;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
				cost[i][j] = INF;
			}
		}

		Q.push({ 0,0,map[0][0] });
		cost[0][0] = map[0][0];

		while (!Q.empty())
		{
			int cx = Q.top().x;
			int cy = Q.top().y;
			int c = Q.top().cost;
			Q.pop();


			for (int i = 0; i < 4; i++)
			{
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				int nc = c + map[nx][ny];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
				if (cost[nx][ny] > nc)
				{
					cost[nx][ny] = nc;
					Q.push({ nx,ny,nc });
				}
			}
		}
		int result = N - 1;
		cout << "Problem "<<cnt<<": " << cost[result][result] << "\n";
		cnt++;

	}
	return 0;
}
