/*
<< 접근 방법 >>
1. BFS로 바깥공기 -1로 만들어줌
2. BFS에서 다음이 치즈일때 Map++ (공기와 치즈의 변이 몇개가 닿았는지 알기위해)
3. Find_cheeze함수에서 Map이 바깥공기(-1)이고, confirm(바깥공기의 다음위치--> 산화가 안된치즈)true 이면 Air큐에 push
   ** 이때, confirm함수에서 치즈 카운트해준거 다시 1값으로 초기화해준다(다음카운트를위해)
4. Find_cheeze함수에서 Map이 3이상이면(치즈이고, 2변 이상이 공기와 닿은거니까) 산화처리(바깥공기 -1, visit방문처리)해주고 Air큐에 push
5. 치즈가 없어질때까지 반복
*/

#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

struct info { int x, y; };
int N, M,Count;
int Map[110][110];
bool visit[110][110];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<info>Air;

bool stop();
bool confirm(int x, int y);
void Spread_Air();
void Find_cheeze();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

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
	visit[0][0] = true;

	while (1)
	{
		Count++;
		Spread_Air();
		Find_cheeze();
		if (stop())break;
	}

	cout << Count << endl;
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
			if (visit[nx][ny] == false) //방문안했고,
			{
				if (Map[nx][ny] == 0) //다음위치가 공기이면, 
				{
					visit[nx][ny] = true; //방문처리
					Map[nx][ny] = -1; //바깥공기 처리
					Air.push({ nx,ny });
				}

				else if (Map[nx][ny] > 0) //다음위치가 양수이면(치즈)
				{
					Map[nx][ny]++; //카운트 올려줌(치즈의 4변중 몇개가 공기와 맞닿았는지 알기위해)
				}
			}
		}
	}

	while (!Air.empty()) //초기화 
	{
		Air.pop();
	}
}

void Find_cheeze()
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Map[i][j] == -1) { //바깥공기일때,
				if (confirm(i, j)) //다음위치가 치즈이고, 변이1개이하 공기와 맞닿았으면 (아직 치즈가 산화안됨)
				{
					Air.push({ i,j }); //지금위치가 가장바깥테두리 이므로 Air큐에push
				}
			}

			else if (Map[i][j] >= 3) { //현재가 치즈이고, 변이2개이상 공기와 맞닿았으면 (치즈가 산화됨)
				Air.push({ i,j }); //현재위치 Air큐에 push
				Map[i][j] = -1; //바깥공기처리
				visit[i][j] = 0; //방문처리
			}
		}
	}

}

bool confirm(int x, int y)
{
	bool yes = false;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
		if (Map[nx][ny] == 2) { // 다음위치가 산화안된 치즈이면
			Map[nx][ny] = 1; //치즈 값 초기화 해주고
			yes = true;
		}
	}
	if (yes) return true; //true리턴
	else return false;
}

bool stop()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (Map[i][j] == 1)return false;
		}
	}
	return true;
}
