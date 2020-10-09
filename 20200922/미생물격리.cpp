//20:09~21:15

/*
	1. 1시간마다 미생물이동 (Map에 Bug idx값을 넣어줌 // 약품칠해진칸은 안넣음)
	 새로운 벡터에 정보입력 다음칸이 1) 약품칸 : 미생물수/2,방향반대
	2. 마지막으로 탐색하면서 Bug가 여러개일때 처리해줌.

	미생물 움직이면서 새로운 벡터에 값 넣어줌.
	1시간 지나고 모든 처리 끝나면 Bug에 복사 ,

*/
#include<iostream>
#include<vector>

using namespace std;

struct info { int x, y, cnt, dir; };
int T;
int N, M, K;
int Total;
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };
vector<info>Bug;
vector<int>Map[105][105];

void Move();
void Calculate_Ans();
int changeDir(int curd);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	for (int q = 1; q <= T; q++) {

		Total = 0, N = 0, M = 0, K = 0;
		Bug.clear();

		cin >> N >> M >> K;

		for (int i = 0; i < K; i++) {
			int x, y, cnt, dir;
			cin >> x >> y >> cnt >> dir;

			Bug.push_back({ x,y,cnt,dir });
		}

		for (int i = 0; i < M; i++) {
			Move();
		}

		Calculate_Ans();
		cout << "#" << q << ' ' << Total << "\n";
	}

	return 0;
}

void Move()
{
	vector<info>Cpy;

	for (int i = 0; i < Bug.size(); i++) {

		int curx = Bug[i].x;
		int cury = Bug[i].y;
		int curcnt = Bug[i].cnt;
		int curdir = Bug[i].dir;

		int nx = curx + dx[curdir];
		int ny = cury + dy[curdir];

		//cout << curx << " " << cury << " " << nx << " " << ny << "\n";
		if (nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1) { //약품칸
			int ncnt = curcnt / 2;
			if (ncnt == 0)continue;

			int ndir = changeDir(curdir);

			Cpy.push_back({ nx,ny,(curcnt / 2),ndir });
		}
		else {
			Map[nx][ny].push_back(i); //다음칸으로 이동하는 벌레 맵에 표시
		}
	}

	/*
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << Map[i][j].size() << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	*/

	//한곳에 모인 벌레들 처리
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Map[i][j].empty())continue;

			if (Map[i][j].size() > 1) { //벌레가 여러마리인 경우
				int standIdx = Map[i][j][0];
				int MMax = Bug[standIdx].cnt;
				int Totcnt = MMax;

				for (int k = 1; k < Map[i][j].size(); k++) {

					int Idx = Map[i][j][k];
					Totcnt += Bug[Idx].cnt;
					if (MMax < Bug[Idx].cnt) {
						MMax = Bug[Idx].cnt;
						standIdx = Idx;
					}
				}

				Cpy.push_back({ i,j,Totcnt,Bug[standIdx].dir });
			}
			else if (Map[i][j].size() == 1) //벌레가 한마리인경우 
			{
				int standIdx = Map[i][j][0];
				Cpy.push_back({ i,j,Bug[standIdx].cnt,Bug[standIdx].dir });
			}
		}
	}


	Bug.assign(Cpy.begin(), Cpy.end()); //Bug정보 갱신

	//Map초기화.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Map[i][j].clear();
		}
	}
}


void Calculate_Ans() {

	for (int i = 0; i < Bug.size(); i++) {
		Total += Bug[i].cnt;
	}
}

int changeDir(int curd)
{
	if (curd == 1) return 2;
	else if (curd == 2) return 1;
	else if (curd == 3) return 4;
	else if (curd == 4)return 3;
}
