#include<iostream>
#include<vector>

using namespace std;

struct info2 { int x, y, dir; };
struct info { int num, dir; };
int A, B, N, M;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int Map[110][110];
vector<info2>Robot;


int changeL(int cd);
int changeR(int cd);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> B >> A;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int x = 0; int y = 0; char d;
		cin >> y >> x >> d;
		if (d == 'N')
		{
			Map[A - x + 1][y] = i+1;
			Robot.push_back({ A - x + 1,y,0 });
		}
		else if (d == 'S')
		{
			Map[A - x + 1][y] = i+1;
			Robot.push_back({ A - x + 1,y,1 });
		}
		else if (d == 'W')
		{
			Map[A - x + 1][y] = i+1;
			Robot.push_back({ A - x + 1,y,2 });
		}
		else if (d == 'E')
		{
			Map[A - x + 1][y] = i+1;
			Robot.push_back({ A - x + 1,y,3 });
		}
	}

	bool flag = false;
	for (int i = 0; i < M; i++)
	{
		int num = 0;  char oper; int T = 0;
		cin >> num >> oper >> T;

		int cx = Robot[num - 1].x;
		int cy = Robot[num - 1].y;
		int cd = Robot[num - 1].dir;
	
		flag = false;

		int nx = cx; int ny = cy; int nd = cd;
		
		for (int j = 0; j < T; j++)
		{
			Map[nx][ny] = 0;

			if (oper == 'F')
			{
				nx += dx[nd];
				ny += dy[nd];
			
				if (nx < 1 || ny < 1 || nx > A  || ny > B )
				{
					//cout << nx << " " << ny << "\n"; //이거때매..계속틀림..!!!바보!!!!!
					flag = true;
					cout << "Robot "<< num <<" crashes into the wall";
					break;
				}

				if (Map[nx][ny] > 0)
				{
					flag = true;
					cout << "Robot "<< num <<" crashes into robot " << Map[nx][ny];
					break;
				}
				else if (Map[nx][ny] == 0)
					Map[nx][ny] = num;

			}
			else if (oper == 'L')
			{
				nd = changeL(nd);
			}
			else if (oper == 'R')
			{
				nd = changeR(nd);
			}
		}
		//cout << nx << " " << ny << " " << nd << "\n";
		if (flag) break;
		Robot[num - 1].x = nx; Robot[num - 1].y = ny; Robot[num - 1].dir = nd;

	}

	/*
	cout << "\n";
	for (int i = 1; i <= A; i++)
	{
		for (int j = 1; j <= B; j++)
		{
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}*/

	if (!flag)cout << "OK";

	return 0;
}


int changeL(int cd)
{
	if (cd == 0)return 2;
	else if (cd == 2)return 1;
	else if (cd == 1)return 3;
	else if (cd == 3)return 0;
}
int changeR(int cd)
{
	if (cd == 0)return 3;
	else if (cd == 3)return 1;
	else if (cd == 1)return 2;
	else if (cd == 2)return 0;
}
