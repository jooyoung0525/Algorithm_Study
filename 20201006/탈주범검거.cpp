#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

struct info {
	int x, y, pipe, t;
};

int T;
int N, M, sx, sy, TTime;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int Map[55][55];
bool visit[55][55];
queue<info>Q;


void IInput();
void IInit();
int BFS();
//int Count();
bool Check(int idx, int nx, int ny);
void go(int x, int y, int shape, int ct);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	for (int testcase = 1; testcase <= T; testcase++) {

		IInit();
		IInput();
		int result = BFS();
		//int result = Count();
		cout << "#" << testcase << " " << result << "\n";
	}
	return 0;
}

void IInit() {

	N = 0, M = 0, sx = 0, sy = 0, TTime = 0;
	memset(Map, 0, sizeof(Map));
	memset(visit, false, sizeof(visit));

	while (!Q.empty()) {
		Q.pop();
	}
}

void IInput() {

	cin >> N >> M >> sx >> sy >> TTime;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}
}


int BFS() {

	Q.push({ sx,sy,Map[sx][sy],0 });
	visit[sx][sy] = true;

	int cnt = 0;
	while (!Q.empty()) {

		int cx = Q.front().x;
		int cy = Q.front().y;
		int shape = Q.front().pipe;
		int ct = Q.front().t;
		Q.pop();

		if (ct == TTime) {
			return cnt;
		}

		cnt++;
		go(cx, cy, shape, ct);

	}

	return cnt;
}



void go(int x, int y, int shape, int ct) {

	if (shape == 1) {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M || Map[nx][ny] == 0)continue;
			if (!visit[nx][ny] && Check(i, nx, ny)) {
				visit[nx][ny] = true;
				Q.push({ nx,ny,Map[nx][ny],ct + 1 });

			}
		}
	}

	else if (shape == 2) {
		for (int i = 0; i <= 1; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M || Map[nx][ny] == 0)continue;
			if (!visit[nx][ny] && Check(i, nx, ny)) {
				visit[nx][ny] = true;
				Q.push({ nx,ny,Map[nx][ny],ct + 1 });
			}
		}
	}

	else if (shape == 3) {
		for (int i = 2; i <= 3; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M || Map[nx][ny] == 0)continue;
			if (!visit[nx][ny] && Check(i, nx, ny)) {
				visit[nx][ny] = true;
				Q.push({ nx,ny,Map[nx][ny],ct + 1 });
			}
		}
	}

	else if (shape == 4) {
		int idx = 0;
		for (int i = 0; i < 4; i += 3) {
			//cout << "shape 4" << i << "\n";
			int nx = x + dx[i];
			int ny = y + dy[i];
			idx += 3;
			if (nx < 0 || ny < 0 || nx >= N || ny >= M || Map[nx][ny] == 0)continue;
			if (!visit[nx][ny] && Check(i, nx, ny)) {
				visit[nx][ny] = true;
				Q.push({ nx,ny,Map[nx][ny],ct + 1 });
			}
		}
	}

	else if (shape == 5) {
		for (int i = 1; i < 4; i += 2) {
			//cout << "shape 5" << i << "\n";
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M || Map[nx][ny] == 0)continue;
			if (!visit[nx][ny] && Check(i, nx, ny)) {
				visit[nx][ny] = true;
				Q.push({ nx,ny,Map[nx][ny],ct + 1 });
			}
		}
	}

	else if (shape == 6) {
		for (int i = 1; i <= 2; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M || Map[nx][ny] == 0)continue;
			if (!visit[nx][ny] && Check(i, nx, ny)) {
				visit[nx][ny] = true;
				Q.push({ nx,ny,Map[nx][ny],ct + 1 });
			}
		}
	}


	else if (shape == 7) {

		for (int i = 0; i < 3; i += 2) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M || Map[nx][ny] == 0)continue;
			if (!visit[nx][ny] && Check(i, nx, ny)) {
				visit[nx][ny] = true;
				Q.push({ nx,ny,Map[nx][ny],ct + 1 });
			}
		}
	}
}

/*
int Count() {

	int cnt = 0;
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == true)cnt++;
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}
	return cnt;
}*/


bool Check(int idx, int nx, int ny) {

	if (idx == 0) {
		if (Map[nx][ny] == 1 || Map[nx][ny] == 2 || Map[nx][ny] == 5 || Map[nx][ny] == 6)return true;
	}
	else if (idx == 1) {
		if (Map[nx][ny] == 1 || Map[nx][ny] == 2 || Map[nx][ny] == 4 || Map[nx][ny] == 7)return true;
	}
	else if (idx == 2) {
		if (Map[nx][ny] == 1 || Map[nx][ny] == 3 || Map[nx][ny] == 4 || Map[nx][ny] == 5)return true;
	}
	else if (idx == 3) {
		if (Map[nx][ny] == 1 || Map[nx][ny] == 3 || Map[nx][ny] == 6 || Map[nx][ny] == 7)return true;
	}
	return false;
}