// BFS이용하면 메모리초과
// DFS접근할 때 string으로 이전 경로저장하는 것이 아닌 그냥 배열로 각 알파벳을 썼는지 안썼는지 체크해주며 접근하는 방법으로 품

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int R, C;
int mmax;
char map[30][30];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool alpha_check[30];
vector<int>Result;

void DFS(int x, int y, int cnt);


int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
		}
	}

	alpha_check[map[0][0] - 'A'] = true;
	DFS(0,0,1);

	cout << mmax << endl;

	return 0;
}

void DFS(int x, int y, int cnt)
{
	mmax = max(mmax, cnt);
	
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= R || ny >= C)continue;
		
		if (alpha_check[map[nx][ny]-'A'] == false) {
			alpha_check[map[nx][ny]-'A'] = true;
			DFS(nx, ny, cnt + 1);
			alpha_check[map[nx][ny]-'A'] = false;
		}
	}

	return;
}
