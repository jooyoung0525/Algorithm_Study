/*

<<주의사항>> --> 구현이 매우 까다로움

1. 큐에다 넣어서 풀면안됨 (엎혀서 이동하는 말의정보를 갱신할 수 없음) --> 다음턴돌때 엎혀서 이동한 말의 이전정보로 턴을 돌아버림
2. 말의배열 정보를 갱신할 때, cd방향을 넣어서 갱신하는 것이 아니라 Move[cx][cy][idx].dir의 정보를 넣어서 갱신해야함


<<접근법>>
1. 체스판의 색을 확인할 체스배열을 선언해서 초기값넣어줌
2. 말의 이동정보를 저장하는 배열벡터를 선언해서 말이 이동할때마다 배열벡터에 정보갱신
3. 턴을 돌때마다 갱신된 말의 정보로 돌아야 함으로 말의 정보만을 저장하는 배열을 선언
4. 각 턴에서 말의 갯수만큼 말을 이동시키는데 이동시킬때마다 벡터의 사이즈를 확인한다 (말이 4개이상쌓이면 turn값을 출력)
5. 말을 이동시킬때마다 현재위치의 말의갯수를 파악하고 이동시켜준다( 1개일때, 여러개일때)


*/

#include<iostream>
#include<vector>

using namespace std;

struct info { int dir, Num; }; //방향 및 말의번호
struct info2 { int x, y, dir; }; 
int N, K, Turn;
bool stop = false;
int Chess[15][15];
int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};
info2 Holse[15];
vector<info>Move[15][15];

int changedir(int cd);
void Going(int idx);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> Chess[i][j];
		}
	}
	
	for (int i = 1; i <= K; i++)
	{
		int x = 0, y = 0, dir = 0;
		cin >> x >> y >> dir;
		Move[x][y].push_back({ dir,i });
		Holse[i] = { x,y,dir}; //Holse의 인덱스가 말의 번호
	}

	while (Turn <= 1000) 
	{
		Turn++;
		for (int i = 1; i <= K; i++)
		{
			//cout << endl;
			Going(i);
			/*cout <<i<< "번째 말" << endl;
			for (int j = 1; j <= K; j++) {
				cout << Holse[j].x << " " << Holse[j].y << " "<<Holse[j].dir<< endl;
			}
			for (int k = 1; k <= N; k++)
			{
				for (int a = 1; a <= N; a++)
				{
					cout << Move[k][a].size()<< " ";
				}
				cout << endl;
			}
			cout << endl;*/
			if (stop) break;
		}
		if (stop)break;
	}

	if (stop) cout << Turn << "\n";
	else cout << -1 << "\n";

	return 0;
}

void Going(int idx)
{
	int cx = Holse[idx].x;
	int cy = Holse[idx].y;
	int cd = Holse[idx].dir;
	int cnum = idx;

	int nx = cx + dx[cd];
	int ny = cy + dy[cd];

	//cout << idx << "번째  cx " << cx << " cy " << cy << " cd " << cd << "nx " << nx << "ny " << ny << endl;
	int cidx = 0;
	for (int i = 0; i < Move[cx][cy].size(); i++) //현재기준이되는 말번호의 인덱스값 구하기
	{
		if (Move[cx][cy][i].Num == cnum)
		{
			cidx = i;
			break;
		}
	}

	if (nx <= 0 || ny <= 0 || nx > N || ny > N || Chess[nx][ny]==2) //벽일경우, 다음칸이 파란색일경우
	{
		int nd = changedir(cd);
		int nnx = cx + dx[nd];
		int nny = cy + dy[nd];

		Move[cx][cy][cidx].dir = nd;

		if (nnx <= 0 || nny <= 0 || nnx > N || nny > N || Chess[nnx][nny] == 2)
		{
			Holse[idx] = { cx,cy,nd };
		}

		else if (Chess[nnx][nny] == 0)//다음칸이 흰색일때,
		{
			vector<info>White;
			White = Move[cx][cy];
			Move[cx][cy].clear();

			if (White.size() == 1)
			{
				Move[nnx][nny].push_back(White[0]); //말지도 변경
				Holse[idx] = { nnx,nny,White[0].dir };
			}

			else if (White.size() > 1)
			{
				for (int a = cidx; a < White.size(); a++)
				{
					int Hnum = White[a].Num;
					Move[nnx][nny].push_back({White[a] }); //다음칸에 말 넣어주고
					Holse[Hnum] = { nnx,nny,White[a].dir }; //현재말과 업힌말 모두 말의 정보갱신
				}
				
				for (int i = 0; i < cidx; i++)
				{
					Move[cx][cy].push_back({ White[i] });
				}
			}
		}

		else if (Chess[nnx][nny] == 1)//다음칸이 빨강일때
		{

			vector<info>Red; //현재위치 벡터복사
			Red = Move[cx][cy];
			Move[cx][cy].clear();

			if (Red.size() == 1)//현재위치의 말이 한개면
			{
				Move[nnx][nny].push_back(Red[0]);//다음위치에 현재위치의 말의값 넣어줌
				Holse[idx] = { nnx,nny,Red[0].dir };//말의 정보를 업데이트
			}

			else if (Red.size() > 1)//현재위치 말이 여러개
			{
		
				for (int a = Red.size() - 1; a >= cidx; a--)//뒤에서부터 현재말의 인덱스까지
				{
					int Hnum = Red[a].Num;
					Move[nnx][nny].push_back({ Red[a] });//다음위치에 넣어줌
					Holse[Hnum] = { nnx,nny,Red[a].dir }; //현재말에 업힌말까지 정보갱신
				}
				for (int i = 0; i < cidx; i++)
				{
					Move[cx][cy].push_back({ Red[i] });
				}
			}
		}

		if (Move[nnx][nny].size() >= 4)
		{
			stop = true;
			return;
		}
	}

	else if (Chess[nx][ny] == 0)//다음칸이 흰색일때,
	{

		vector<info>White;
		White = Move[cx][cy];
		Move[cx][cy].clear();

		if (White.size() == 1)
		{
			Move[nx][ny].push_back(White[0]); //말지도 변경
			Holse[idx] = { nx,ny,White[0].dir };
		}

		else if (White.size() > 1)
		{
			for (int a = cidx; a < White.size(); a++)
			{
				int Hnum = White[a].Num;
				Move[nx][ny].push_back({ White[a] }); //다음칸에 말 넣어주고
				Holse[Hnum] = { nx,ny,White[a].dir }; //현재말과 업힌말 모두 말의 정보갱신
			}

			for (int i = 0; i < cidx; i++)
			{
				Move[cx][cy].push_back({ White[i] });
			}
		}
		
		if (Move[nx][ny].size() >= 4)
		{
			stop = true;
			return;
		}
	}

	else if (Chess[nx][ny] == 1)//다음칸이 빨강일때
	{
		vector<info>Red; //현재위치 벡터복사
		Red = Move[cx][cy];
		Move[cx][cy].clear();

		if (Red.size() == 1)//현재위치의 말이 한개면
		{
			Move[nx][ny].push_back(Red[0]);//다음위치에 현재위치의 말의값 넣어줌
			Holse[idx] = { nx,ny,Red[0].dir };//말의 정보를 업데이트
		}

		else if (Red.size() > 1)//현재위치 말이 여러개
		{

			for (int a = Red.size() - 1; a >= cidx; a--)//뒤에서부터 현재말의 인덱스까지
			{
				int Hnum = Red[a].Num;
				Move[nx][ny].push_back({ Red[a] });//다음위치에 넣어줌
				Holse[Hnum] = { nx,ny,Red[a].dir}; //현재말에 업힌말까지 정보갱신
			}
			for (int i = 0; i < cidx; i++)
			{
				Move[cx][cy].push_back({ Red[i] });
			}
		}

		if (Move[nx][ny].size() >= 4)
		{
			stop = true;
			return;
		}
	}

}

int changedir(int cd)
{
	if (cd == 1) return 2;
	else if (cd == 2) return 1;
	else if (cd == 3) return 4;
	else if (cd == 4) return 3;
}
