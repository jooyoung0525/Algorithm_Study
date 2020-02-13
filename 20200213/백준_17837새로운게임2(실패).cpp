/*
턴을 돌때마다 말의정보를 큐에 저장했는데, 이렇게 하면 엎혀가는 말의 정보를 갱신할 수 없어서 문제를 맞을 수 없다!
문제를 많이 생각해보고 풀자!
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


struct vecinfo { int num, dir; };
struct quinfo { int x, y, dir, num, turn;};
int N, K,result; 
bool stop = false;
int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};
int origin_map[15][15];
vector<vecinfo>Move[15][15];
queue<quinfo>Q;


void MoveMal();
void Saveinfo();

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> origin_map[i][j];
		}
	}

	int count = 1;
	for (int i = 0; i < K; i++)
	{
		int x, y, dir;
		cin >> x >> y >> dir;
		Move[x][y].push_back({count,dir});
		Q.push({ x,y,dir,count,1});
		count++;
	}
	//10개짜리 말배열 만들고

	//int horseIdx = 0;
	MoveMal();

	cout << result << endl;

	return 0;
}


void MoveMal()
{
	while (!Q.empty())
	{
		int cx = Q.front().x;
		int cy = Q.front().y;
		int cd = Q.front().dir;
		int Num = Q.front().num;
		int ct = Q.front().turn;
		Q.pop();

		if (ct > 1000) {
			result = -1;
			return;
		}
		
		int nx = cx + dx[cd];
		int ny = cy + dy[cd];

		cout << cx << " " << cy << " " << cd << " " << Num << " " << nx << " " << ny << endl;

		if (origin_map[nx][ny] == 2 || nx <= 0 || ny <= 0 || nx > N || ny > N)
		{
			int nd = 0; int cidx = 0;
			if (cd == 1)nd = 2;
			else if (cd == 2)nd = 1;
			else if (cd == 3)nd = 4;
			else if (cd == 4)nd = 3;

			int nnx = cx + dx[nd];
			int nny = cy + dy[nd];

			if (Move[cx][cy].size() == 1) cidx = 0; //현재위치에 말이 하나일경우
			else if (Move[cx][cy].size() > 1)
			{
				for (int a = 0; a < Move[cx][cy].size(); a++) // 현재위치에 말이 여러개일경우, 지금 움직이는 말의 인덱스 구해줌
				{
					if (Move[cx][cy][a].num == Num)
					{
						cidx = a;
						break;
					}
				}
			}
			Move[cx][cy][cidx].dir = nd;

			if (origin_map[nnx][nny] == 2 || nnx <= 0 || nny <= 0 || nnx > N || nny > N) //방향바꾸고 다음칸이 파랑이거나,벽일때
			{
				Q.push({ cx,cy,nd,Num,ct+1 });
				continue;
			}

			else if (origin_map[nnx][nny] == 1)
			{
				vector<vecinfo>Red;
				Red = Move[cx][cy];
				Move[cx][cy].clear();

				for (int b = Red.size() - 1; b >= cidx; b--)
				{
					Move[nnx][nny].push_back({ Red[b] });
				}
				if (cidx > 0)
				{
					for (int i = 0; i < cidx; i++)
					{
						Move[cx][cy].push_back({ Red[i] });
					}
				}

				if (Move[nnx][nny].size() >= 4)
				{
					result = ct;
					return;
				}
			}

			else if (origin_map[nnx][nny] == 0)//움직일칸이 흰색일경우
			{
				if (Move[cx][cy].size() == 1)//현재칸에 말이 하나
				{
					Move[nnx][nny].push_back({ Move[cx][cy][0] });
					Move[cx][cy].clear();
				}

				else if (Move[cx][cy].size() > 1) //현재칸에 말이 여러개일경우
				{

					vector<vecinfo>White;
					White = Move[cx][cy]; //현재칸white벡터에 복사
					Move[cx][cy].clear(); //현재칸 빈칸만들고

					for (int b = cidx; b < White.size(); b++)
					{
						Move[nnx][nny].push_back({ White[b] });
					}
					if (cidx > 0) //넘길 말의 인덱스가 0부터 시작안하면 
					{
						for (int a = 0; a < cidx; a++)
							Move[cx][cy].push_back(White[a]);
					}
				}

				if (Move[nnx][nny].size() >= 4)
				{
					result = ct;
					return;
				}
			}
			
			Q.push({ nnx,nny,nd,Num,ct+1 });
			cout << "움ㅈㄱ전: 파" << endl;
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= N; j++)
				{
					cout << Move[i][j].size() << " ";
				}
				cout << endl;
			}
		}

		else if (origin_map[nx][ny] == 0)//다음이 흰색
		{
			if (Move[cx][cy].size() == 1)//현재칸에 말이 하나
			{
				Move[nx][ny].push_back(Move[cx][cy][0]);
				Move[cx][cy].clear();
				if (Move[nx][ny].size() >= 4)
				{
					result = ct;
					return;
				}
			}
			else if (Move[cx][cy].size() > 1) //현재칸에 말이 여러개일경우
			{
				int cidx = 0;
				vector<vecinfo>White;
				White = Move[cx][cy]; //현재칸white벡터에 복사
				Move[cx][cy].clear(); //현재칸 빈칸만들고

				for (int a = 0; a < White.size(); a++) 
				{
					if (White[a].num == Num)
					{
						cidx = a;
						break;
					}
				}
				
				for (int b = cidx; b < White.size(); b++)
				{
					Move[nx][ny].push_back({ White[b] });
				}

				
				if (cidx > 0) //넘길 말의 인덱스가 0부터 시작안하면 
				{
					for (int a = 0; a < cidx; a++)
						Move[cx][cy].push_back(White[a]);
				}
				if (Move[nx][ny].size() >= 4)
				{
					result = ct;
					return;
				}
			}

			Q.push({ nx,ny,cd,Num,ct+1 });

			cout << "움ㅈㄱ전: 흰" << endl;
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= N; j++)
				{
					cout << Move[i][j].size() << " ";
				}
				cout << endl;
			}
		}

		else if (origin_map[nx][ny] == 1)//다음 칸이 빨강일경우
		{
			vector<vecinfo>Red;
			int cidx = 0;
			Red = Move[cx][cy]; //현재칸의 벡터모두복사
			Move[cx][cy].clear();

			for (int a = 0; a < Red.size(); a++)
			{
				if (Red[a].num == Num)
				{
					cidx = a;
					break;
				}
			}

			for (int a = Red.size() - 1; a >= cidx; a--)
			{
				Move[nx][ny].push_back({ Red[a]});
			}
			if (cidx > 0)
			{
				for (int i = 0; i < cidx; i++)
				{
					Move[cx][cy].push_back({ Red[i] });
				}
			}
			if (Move[nx][ny].size() >= 4)
			{
				result = ct;
				return;
			}
			Q.push({ nx,ny,cd,Num,ct + 1 });


			cout << "움ㅈㄱ전: 빨" << endl;
			for (int i = 1; i <= N; i++)
			{
				for (int j = 1; j <= N; j++)
				{
					cout << Move[i][j].size() << " ";
				}
				cout << endl;
			}
			
		}
	
	}

}



