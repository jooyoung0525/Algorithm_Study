#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Bug { int x, y, num, dir; bool die; };

vector<Bug>Bugs;
vector<int>Map[110][110];
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };
int N, M, K;
int T;

int change(int cd);
void Move();
void A_Lot_Bugs();
int Count();
void Init_all();

int main()
{
	cin >> T;
	for (int q = 1; q <= T; q++)
	{
		Init_all();
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++)
		{
			int x, y, num, dir;
			cin >> x >> y >> num >> dir;
			//Map[Bugs[i].x][Bugs[i].y].push_back(i);
			Bugs.push_back({ x,y,num,dir,false });
		}

		for (int i = 0; i < M; i++)
		{
			Move();
		}

		cout << '#' << q << ' ' << Count() << "\n";
	}
	return 0;
}


void Move()
{
	bool alot = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Map[i][j].clear();
		}
	}

	//cout << "1"<<"\n";
	for (int i = 0; i < Bugs.size(); i++)
	{
		if (Bugs[i].die == true)continue;

		//cout << "2" << "\n";
		int cx = Bugs[i].x;
		int cy = Bugs[i].y;
		int cnum = Bugs[i].num;
		int cd = Bugs[i].dir;


		int nx = cx + dx[cd];
		int ny = cy + dy[cd];
		int nd = cd;
		int nnum = cnum;

		if (nx <= 0 || ny <= 0 || nx >= N - 1 || ny >= N - 1) //빨간영역
		{
			nd = change(nd); //방향반대
			nnum /= 2; //현재 벌레수의 1/2

			Map[nx][ny].push_back(i); //새로운 위치에 정보넣고

			Bugs[i].x = nx; //벡터에 정보들 다시저장
			Bugs[i].y = ny;
			Bugs[i].dir = nd;
			Bugs[i].num = nnum;
		}
		else
		{
			if (Map[nx][ny].empty())
			{
				Map[nx][ny].push_back(i); //새로운 위치에 정보넣고

				Bugs[i].x = nx; //벡터에 정보들 다시저장
				Bugs[i].y = ny;
				Bugs[i].dir = nd;
				Bugs[i].num = nnum;
			}
			else
			{
				alot = true; //사이즈가 1이상일때 

				Map[nx][ny].push_back(i); //새로운 위치에 정보넣고

				Bugs[i].x = nx; //벡터에 정보들 다시저장
				Bugs[i].y = ny;
				Bugs[i].dir = nd;
				Bugs[i].num = nnum;
			}

		}
	}

	if (alot)
		A_Lot_Bugs();
}


int change(int cd)
{
	if (cd == 1)return 2;
	else if (cd == 2)return 1;
	else if (cd == 3)return 4;
	else if (cd == 4)return 3;
}


void A_Lot_Bugs()
{
	//cout << "3" << "\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Map[i][j].size() <= 1)continue;
			else
			{
				int hap = 0;
				int Idx = -1;
				int MMAX = -1;

				for (int a = 0; a < Map[i][j].size(); a++)
				{
					int cidx = Map[i][j][a];
					hap += Bugs[cidx].num;
					if (MMAX < Bugs[cidx].num)
					{
						if (Idx > -1)
							Bugs[Idx].die = true;
						MMAX = Bugs[cidx].num;
						Idx = cidx;
					}
					else
						Bugs[cidx].die = true;

				}

				Map[i][j].clear();

				Map[i][j].push_back(Idx);
				Bugs[Idx].num = hap;
			}
		}
	}

}


int Count()
{
	int result = 0;
	for (int i = 0; i < Bugs.size(); i++)
	{
		if (Bugs[i].die == true)continue;
		result += Bugs[i].num;
	}

	return result;
}


void Init_all()
{
	N = 0; M = 0; K = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Map[i][j].clear();
		}
	}
	Bugs.clear();
}
