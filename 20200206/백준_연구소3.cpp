//큐에 시간도 같이 넣고, 큐에서빼면서 시간의 최댓값을 갱신 --> 빈방의갯수가 0이될때, 시간의 최댓값과,빈방갯수0된시간(time+1) 의 최댓값구해줌
//전체MMin과 구한 시간의 최댓값의 최솟값구함
//비활성인바이러스도 생각해줘야함!! (Lab이 비었을때와 같이 큐에넣어주고 방문처리해주되, Lab이 비었을때에만 빈방갯수카운트--해줌)


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct info { int x, y; };
int N, M;
int MMin = 99999999;
int emptyroom = 0;
int Lab[55][55];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<info>Virus;
vector<info>selecVirus;

void spreadV();
void Selectvirus(int cnt,int idx);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Lab[i][j];
			if (Lab[i][j] == 2)
			{
				Virus.push_back({ i,j });
			}
			else if (Lab[i][j] == 0)
				emptyroom++;

		}
	}

	if (emptyroom == 0) cout << 0 << "\n";

	else
	{
		Selectvirus(0,0);
		if (MMin == 99999999) cout << -1 << "\n";
		else cout << MMin << "\n";
	}
	
	return 0;
}

void Selectvirus(int cnt, int idx) //정답 //인덱스랑 카운트를 왜 파라미터 하나로넘겼었니!!!!!!!(이거때매 시간초과계속남) --> Selectvirus(int cnt)
{
	if (cnt == M)
	{
		spreadV();
		return;
	}

	for (int i = idx; i < Virus.size(); i++)
	{
		selecVirus.push_back({ Virus[i].x,Virus[i].y });
		Selectvirus(cnt + 1,i+1);
		selecVirus.pop_back();
	}
}

void spreadV()
{
	int ans = -9999999;
	int emptycnt = emptyroom;
	int maxt = 0;
	queue<pair<info, int>>Q;
	bool check[55][55] = { false };

	for (int i = 0; i < selecVirus.size(); i++)
	{
		check[selecVirus[i].x][selecVirus[i].y] = true;
		Q.push({ {selecVirus[i].x,selecVirus[i].y},0 });
	}

	while (!Q.empty())
	{
		int cx = Q.front().first.x;
		int cy = Q.front().first.y;
		int time = Q.front().second;
		Q.pop();

		maxt = max(maxt, time); //시간계속 최댓값으로 업데이트

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
			if (check[nx][ny] == false)
			{
				if (Lab[nx][ny] == 0)
				{
					check[nx][ny] = true;
					Q.push({ {nx,ny},time + 1 });
					emptycnt--;
					continue;
				}

				else if (Lab[nx][ny] == 2)
				{
					check[nx][ny] = true;
					Q.push({ {nx,ny},time + 1 });
					continue;
				}
			}
			if (emptycnt == 0) break;
		}

		if (emptycnt == 0)
		{
			maxt = max(maxt, time + 1);
			MMin = min(MMin, maxt);
			break;
		}
	}

}
