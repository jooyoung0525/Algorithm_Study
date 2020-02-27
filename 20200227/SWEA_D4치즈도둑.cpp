#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

int T,N;
int Map[110][110];
bool visit[110][110];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<int>Result;


int Find_Max();
void Eat_cheeze(int delecious);
void check_region();
void DFS(int x, int y);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int q = 1; q <= T; q++)
	{
		//초기화
		N = 0;
		memset(Map, 0, sizeof(Map));
		Result.clear();

		//입력
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> Map[i][j];
			}
		}

		//Map의 최댓값 찾기
		int MMax = Find_Max();
		
		//요정이 맛있는정도가x인 치즈먹음
		for (int i = 0; i <= MMax; i++) { //0부터시작해야함!
			memset(visit, false, sizeof(visit));
			Eat_cheeze(i);
			check_region();
		}
		
    //벡터에 저장한 최댓값출력
		int Ans = *max_element(Result.begin(), Result.end());

		cout <<'#'<<q<<' '<< Ans << endl;
	}

	return 0;
}

int Find_Max()
{
	int Max_col[110] = { 0 };

	for (int i = 0; i < N; i++)
	{
		Max_col[i] = *max_element(Map[i], Map[i] + (N + 1));
	}

	int Max_result = *max_element(Max_col, Max_col + (N + 1));

	return Max_result;
}

void Eat_cheeze(int delecious)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Map[i][j] == delecious)
			{
				visit[i][j] = true;
				Map[i][j] = -1;
			}
		}
	}
}

void check_region()
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == false && Map[i][j]>0)
			{
				visit[i][j] = true;
				DFS(i, j);
				cnt++;
			}
		}
	}
	Result.push_back(cnt);
}

void DFS(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
		if (visit[nx][ny] == false && Map[nx][ny] > 0) {
			visit[nx][ny] = true;
			DFS(nx, ny);
		}
	}
}
