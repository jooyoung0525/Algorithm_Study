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
int MMin = 99999999;
int NNN = 0;
vector<info>CCTV;

void one(int x, int y, int a);
void Run(int idx);

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
			if (Room[i][j] < 6 && Room[i][j] > 0) {
				CCTV.push_back({ i,j,Room[i][j] });
				NNN++;
			}
			else if (Room[i][j] == 6)
				check[i][j] = true;
		}
	}

	//재귀로 cctv돌리기
	Run(0);
	
	cout << MMin;

	return 0;
}


void one(int x, int y, int a)
{
	int dx[] = { 0,1,0,-1 };
	int dy[] = { 1,0,-1,0 };

	int nx = x + dx[a];
	int ny = y + dy[a];

	while (Room[nx][ny] < 6 && nx >= 0 && ny >= 0 && nx < N && ny < M)
	{
		check[nx][ny] = true;
		nx += dx[a];
		ny += dy[a];
	}

	return;

}

void Run(int idx)
{

	if (idx == NNN)
	{
		
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

	info cctvN = CCTV[idx];
  
	bool checkcpy[10][10]; //복사배열은 지역으로 선언해야하는게 킬포..

	if (cctvN.num == 1)
	{
		for (int i = 0; i < 4; i++) {

			memcpy(&checkcpy, &check, sizeof(check));
			check[cctvN.x][cctvN.y] = true;
			one(cctvN.x, cctvN.y, i);
			Run(idx + 1);
			memcpy(&check, &checkcpy, sizeof(checkcpy));
		}
	}
	else if (cctvN.num == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			memcpy(&checkcpy, &check, sizeof(check));
			check[cctvN.x][cctvN.y] = true;
			one(cctvN.x, cctvN.y, i);
			one(cctvN.x, cctvN.y, i + 2);
			Run(idx + 1);
			memcpy(&check, &checkcpy, sizeof(checkcpy));
		}
	}
	else if (cctvN.num == 3)
	{
		for (int i = 0; i < 4; i++)
		{
			memcpy(&checkcpy, &check, sizeof(check));
			check[cctvN.x][cctvN.y] = true;
			one(cctvN.x, cctvN.y, i);
			one(cctvN.x, cctvN.y, (i + 1) % 4);
			Run(idx + 1);
			memcpy(&check, &checkcpy, sizeof(checkcpy));
		}
	}

	else if (cctvN.num == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			memcpy(&checkcpy, &check, sizeof(check));
			check[cctvN.x][cctvN.y] = true;
			one(cctvN.x, cctvN.y, i);
			one(cctvN.x, cctvN.y, (i + 1) % 4);
			one(cctvN.x, cctvN.y, (i + 2) % 4);
			Run(idx + 1);
			memcpy(&check, &checkcpy, sizeof(checkcpy));
		}
	}
	else if (cctvN.num == 5) //4방향이라고 미리처리해주면 예외가 발생
	{
		memcpy(&checkcpy, &check, sizeof(check));
		check[cctvN.x][cctvN.y] = true;
		for (int i = 0; i < 4; i++)
		{
			one(cctvN.x, cctvN.y, i);
		}
		Run(idx + 1);
		memcpy(&check, &checkcpy, sizeof(checkcpy));
	}

}
