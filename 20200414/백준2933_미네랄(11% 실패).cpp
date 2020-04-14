#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

struct Dist { int x, y; 
bool operator < (const Dist& A)
{
	return x>A.x;
};
};
int R, C, N;
char Map[150][150];
int Cpy[150][150];
int Order[110];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Is_Seperate(int x, int y);
void DFS(int x, int y, int cnt);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;

	for (int a = 1; a <= R; a++)
	{
		for (int b = 1; b <= C; b++)
		{
			cin >> Map[a][b];
		}
	}

	
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Order[i];
	}

	for (int i = 1; i <= N; i++)
	{
		int col = R - Order[i] + 1;
		int row = 0;
		bool erase = false;
		if (i % 2 != 0)//홀수 ->
		{
			for (int j = 1; j <= C; j++)
			{
				if (Map[col][j] == 'x')
				{
					if (erase) {
						row = j;
						break;
					}
					else if(!erase)
					{
						Map[col][j] = '.';
						erase = true;
					}
					
				}	
			}
		}
		else if(i% 2 == 0) //짝수 <-
		{
			for (int j = C; j >= 1; j--)
			{
				if (Map[col][j] == 'x')
				{
					if (erase) {
						row = j;
						break;
					}
					else if (!erase)
					{
						Map[col][j] = '.';
						erase = true;
					}

				}
			}
		}
		//클러스터가 분리되었는지 확인하고 아래로 내려갈 수 있으면 내리는 함수
		Is_Seperate(col, row);
	}

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cout << Map[i][j];
		}
		cout << endl;
	}
	
	return 0;
}

void Is_Seperate(int x, int y)
{
	memset(Cpy, 0, sizeof(Cpy));
	bool down[110] = { false };

	int cnt = 0;
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (Map[i][j] == 'x' && Cpy[i][j] == 0)
			{
				cnt++;
				Cpy[i][j] = cnt;
				DFS(i, j, cnt);
			}
		}
	}

	if (cnt > 1)//아래로 내려야함
	{
		for (int h = 1; h <= C; h++)
		{
			if (Cpy[R][h] > 0)
			{
				down[Cpy[R][h]] = true;
			}
		}

		int down_num = 0;
		for (int i = 1; i < cnt; i++)
		{
			if (down[i] == false)
			{
				down_num = i;
				break;
			}
		}
		
		vector<Dist>D;

		if (down_num != 0)
		{
			for (int i = 1; i <= R; i++)
			{
				for (int j = 1; j <= C; j++)
				{
					if (Cpy[i][j] == down_num)
					{
						Map[i][j] = '.';
						D.push_back({ i,j });
					}
				}
			}
			sort(D.begin(), D.end());

			int mmax_col = 0;

			for (int k = R - D[0].x; k >= 1; k--) {

				bool cant = false;
				mmax_col = k;
				for (int i = 0; i < D.size(); i++)
				{
					int nx = D[i].x + k;
					int ny = D[i].y;
					if (Map[nx][ny] == 'x')
					{
						cant = true;
						break;
					}
				}
				if (!cant)break;
			}
		
			for (int i = 0; i < D.size(); i++)
			{
				int nx = D[i].x + mmax_col;
				int ny = D[i].y;
			
				Map[nx][ny] = 'x';
			}		
		}
	}
}

void DFS(int x, int y, int cnt)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx<1 || ny<1 || nx>R || ny>C)continue;
		if (Map[nx][ny] == 'x' && Cpy[nx][ny] == 0) {
			Cpy[nx][ny] = cnt;
			DFS(nx, ny, cnt);
		}
	}
}
