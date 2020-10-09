#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct info {
	int x, y, dust;
};

int R, C, T;
int room[55][55];
vector<info>V;
info AirUp, AirDown; //공기청정기 위치

void Input();
void spread();
void wind();
void reset_vector();
void Rotate_Up();
void Rotate_Down();

//void Print();

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C >> T;

	Input();

	for (int q = 1; q <= T; q++) {
		
		spread();   //확산
		//Print();

		wind();     //순환
		//Print();

		reset_vector(); //미세먼지 정보리셋
	}

	int total = 0;
	for (int i = 0; i < V.size(); i++) {
		total += V[i].dust;
	}

	cout << total;


	return 0;
}

void Print() {

	cout << "\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << room[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void Input()
{
	bool up = false;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> room[i][j];
			if (room[i][j] > 0) {
				V.push_back({ i, j, room[i][j] });
			}
			else if (room[i][j] == -1)
			{
				if (!up) { //up이 false일 경우 공기청정기 윗부분
					AirUp = { i,j,-1 };
					up = true;
				}
				else { //up이 true일 경우 공기청정이 아랫부분
					AirDown = { i,j,-1 };
				}
			}
		}
	}
}

void reset_vector() {

	V.clear();

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] > 0) {
				V.push_back({ i, j, room[i][j] });
			}
		}
	}
}

void spread() {

	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	for (int i = 0; i < V.size(); i++) {
		int cnt = 0;
		int cx = V[i].x;
		int cy = V[i].y;
		int cdust = V[i].dust/5;
	
		//cout << cx << cy << cdust << "\n";
		for (int j = 0; j < 4; j++) {
			int nx = cx + dx[j];
			int ny = cy + dy[j];

			if (nx < 0 || ny < 0 || nx >= R || ny >= C || room[nx][ny] == -1) continue;

			room[nx][ny] += cdust;
			room[cx][cy] -= cdust;
		}
		
	}

}

void wind() {

	Rotate_Up();
	Rotate_Down();
}



void Rotate_Up() {

	queue<int>Q;

	for (int i = 1; i < C; i++) {
		Q.push(room[AirUp.x][i]);
		room[AirUp.x][i] = 0;
	}
	for (int i = AirUp.x-1; i >= 0; i--) {
		Q.push(room[i][C - 1]);
		room[i][C-1] = 0;
	}
	for (int i = C - 2; i >= 0; i--) {
		Q.push(room[0][i]);
		room[0][i] = 0;
	}
	for (int i = 1; i < AirUp.x; i++) {
		Q.push(room[i][0]);
		room[i][0] = 0;
	}
	
	
	for (int i = 2; i < C; i++) {
		if (!Q.empty()) {
			room[AirUp.x][i] = Q.front();
			Q.pop();
		}
	}
	for (int i = AirUp.x - 1; i >= 0; i--) {
		if (!Q.empty()) {
			room[i][C - 1] = Q.front();
			Q.pop();
		}
	}
	for (int i = C - 2; i >= 0; i--) {
		if (!Q.empty()) {
			room[0][i] = Q.front();
			Q.pop();
		}
	}
	for (int i = 1; i < AirUp.x; i++) {
		if (!Q.empty()) {
			room[i][0] = Q.front();
			Q.pop();
		}
	}
}

void Rotate_Down() {
	queue<int>Q;

	for (int i = 1; i < C; i++) {
		Q.push(room[AirDown.x][i]);
		room[AirDown.x][i] = 0;
	}
	for (int i = AirDown.x + 1; i < R; i++) {
		Q.push(room[i][C - 1]);
		room[i][C - 1] = 0;
	}
	for (int i = C - 2; i >= 0; i--) {
		Q.push(room[R-1][i]);
		room[R-1][i] = 0;
	}
	for (int i = R-2; i > AirDown.x; i--) {
		Q.push(room[i][0]);
		room[i][0] = 0;
	}



	for (int i = 2; i < C; i++) {
		if (!Q.empty()) {
			room[AirDown.x][i] = Q.front();
			Q.pop();
		}
	}
	for (int i = AirDown.x + 1; i < R; i++) {
		if (!Q.empty()) {
			room[i][C - 1] = Q.front();
			Q.pop();
		}
	}
	for (int i = C - 2; i >= 0; i--) {
		if (!Q.empty()) {
			room[R - 1][i] = Q.front();
			Q.pop();
		}
	}
	for (int i = R - 2; i > AirDown.x; i--) {
		if (!Q.empty()) {
			room[i][0] = Q.front();
			Q.pop();
		}
	}
}