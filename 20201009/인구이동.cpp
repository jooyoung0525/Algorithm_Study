//14:21~15:41
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;


int N, L, R;
int Count = 0;
int Map[55][55];
int cpy[55][55];
int check[55][55];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int cnt;
int total = 0;


void Input();
bool isMove();
void DFS(int x, int y, int nownum, int idx);
void resetMap(int cnt, int total, int idx);
void Move();

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);


	Input();

	while (isMove()) {

		Move();
		Count++;
	}

	cout << Count;

	return 0;
}

void Input() {

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
		}
	}
}


void Move() {

	memset(check, 0, sizeof(check));
	memcpy(cpy, Map, sizeof(Map));

	int idx = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0) {

				cnt = 1;
				total = Map[i][j];
				check[i][j] = idx;
				DFS(i, j, Map[i][j], idx); //위치,지역개수,현재숫자
				if (cnt > 1) {
					resetMap(cnt, total, idx);
				}
				idx++;

			}
		}
	}

	memcpy(Map, cpy, sizeof(cpy)); //인구이동 적용한 맵을 원래 맵에 복사.
	/*
	cout << "Map\n";
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}*/
}


void DFS(int x, int y, int nownum, int idx) {

	int now = nownum;

	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N || check[nx][ny] != 0)continue; //범위 넘고, 이미 연합이면 건너뜀

		if (abs(now - Map[nx][ny]) <= R && L <= abs(now - Map[nx][ny])) {
			check[nx][ny] = idx;
			cnt++;
			total += Map[nx][ny];
			DFS(nx, ny, Map[nx][ny], idx);
		}
	}

	return;
}



void resetMap(int cnt, int total, int idx) {

	int newNum = total / cnt;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			if (check[i][j] == idx) {
				cpy[i][j] = newNum;
			}
		}
	}
}


bool isMove() {

	bool visit[55][55] = { false };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (!visit[i][j]) {
				visit[i][j] = true;
				int now = Map[i][j];
				for (int k = 0; k < 4; k++) {

					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny])continue;

					if (abs(now - Map[nx][ny]) <= R && abs(now - Map[nx][ny]) >= L) return true;
				}
			}
		}
	}
	return false;
}