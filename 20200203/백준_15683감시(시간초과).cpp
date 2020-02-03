//뭐가 잘못된거지?

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

struct info { int x, y, num; };
int N, M;
int Room[10][10];
bool check[10][10];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int MMin = 10e9;
int NNN = 0;
vector<info>CCTV;

void Run(int cnt,int idx);
void one(int x, int y, int a)
{
	int nx = x + dx[a]; int ny = y + dy[a];
	while (Room[nx][ny] < 6 && nx >= 0 && ny >= 0 && nx < N && ny < M)
	{
		if (check[nx][ny] == true)continue;
		check[nx][ny] = true;
		nx += dx[a];
		ny += dy[a];
	}
	return;
}
void cpy_samusil(bool origin[10][10], bool cpy[10][10])
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cpy[i][j] = origin[i][j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Room[i][j];
			if (Room[i][j] < 5 && Room[i][j]>0) {
				check[i][j] = true;
				CCTV.push_back({ i,j,Room[i][j] });
				NNN++;
			}
			else if (Room[i][j] == 6)
				check[i][j] = true;
			else if (Room[i][j] == 5)
			{
				check[i][j] = true;
				for (int k = 0; k < 4; k++)
				{
					one(i, j, k);
				}
			}
		}
	}

	for (int i = 0; i < CCTV.size(); i++)
		cout << CCTV[i].x << CCTV[i].y << CCTV[i].num << endl;

	//재귀로 cctv돌리기
	Run(0,0);

	cout << MMin << "\n";

	return 0;
}


void Run(int cnt,int idx)
{
	
	if (cnt == NNN)
	{
		cout << endl;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cout << check[i][j] << " ";
			}
			cout << endl;
		}
		//사각지대세기
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (check[i][j] == false) count++;
			}
		}
		MMin = min(MMin, count);

		return;
	}

	bool checkcpy[10][10];

	
	for (int a = idx; a < CCTV.size(); a++) {

		info cctvN = CCTV[a];
		if (cctvN.num == 1)
		{
			for (int i = 0; i < 4; i++) {

				cpy_samusil(check, checkcpy);
				one(cctvN.x, cctvN.y, i);
				Run(cnt+1,idx + 1);
				cpy_samusil(checkcpy, check);
			}
		}
		else if (cctvN.num == 2)
		{
			for (int i = 0; i < 2; i++)
			{
				cpy_samusil(check, checkcpy);
				one(cctvN.x, cctvN.y, i);
				one(cctvN.x, cctvN.y, i + 2);
				Run(cnt+1,idx + 1);
				cpy_samusil(checkcpy, check);
			}
		}
		else if (cctvN.num == 3)
		{
			for (int i = 0; i < 4; i++)
			{
				cpy_samusil(check, checkcpy);
				one(cctvN.x, cctvN.y, i);
				one(cctvN.x, cctvN.y, (i + 1) % 4);
				Run(cnt+1,idx + 1);
				cpy_samusil(checkcpy, check);
			}
		}
		else if (cctvN.num == 4)
		{
			for (int i = 0; i < 4; i++)
			{
				cpy_samusil(check, checkcpy);
				one(cctvN.x, cctvN.y, i);
				one(cctvN.x, cctvN.y, (i + 1) % 4);
				one(cctvN.x, cctvN.y, (i + 2) % 4);
				Run(cnt+1,idx + 1);
				cpy_samusil(checkcpy, check);
			}
		}
	}
}
