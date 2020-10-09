//20:09~21:15

/*
	1. 1�ð����� �̻����̵� (Map�� Bug idx���� �־��� // ��ǰĥ����ĭ�� �ȳ���)
	 ���ο� ���Ϳ� �����Է� ����ĭ�� 1) ��ǰĭ : �̻�����/2,����ݴ�
	2. ���������� Ž���ϸ鼭 Bug�� �������϶� ó������.

	�̻��� �����̸鼭 ���ο� ���Ϳ� �� �־���.
	1�ð� ������ ��� ó�� ������ Bug�� ���� ,

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
		if (nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1) { //��ǰĭ
			int ncnt = curcnt / 2;
			if (ncnt == 0)continue;

			int ndir = changeDir(curdir);

			Cpy.push_back({ nx,ny,(curcnt / 2),ndir });
		}
		else {
			Map[nx][ny].push_back(i); //����ĭ���� �̵��ϴ� ���� �ʿ� ǥ��
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

	//�Ѱ��� ���� ������ ó��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Map[i][j].empty())continue;

			if (Map[i][j].size() > 1) { //������ ���������� ���
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
			else if (Map[i][j].size() == 1) //������ �Ѹ����ΰ�� 
			{
				int standIdx = Map[i][j][0];
				Cpy.push_back({ i,j,Bug[standIdx].cnt,Bug[standIdx].dir });
			}
		}
	}


	Bug.assign(Cpy.begin(), Cpy.end()); //Bug���� ����

	//Map�ʱ�ȭ.
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
