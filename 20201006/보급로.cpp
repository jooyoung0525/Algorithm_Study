#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int T;
int N;
int Map[105][105];
int Min[105][105];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct info { int x, y; };

void IInput();
void Go();

int main() {

	cin >> T;

	for (int TC = 1; TC <= T; TC++) {

		N = 0;
		memset(Map, 0, sizeof(Map));

		IInput();

		Go();
		int result = Min[N - 1][N - 1];

		cout << "#" << TC << " " << result << "\n";
	}

	return 0;
}


void IInput() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &Map[i][j]);
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Min[i][j] = 987654321;
		}
	}

}


void Go() {
	queue<info>Q;
	Q.push({ 0,0 });
	Min[0][0] = 0;

	while (!Q.empty()) {

		int cx = Q.front().x;
		int cy = Q.front().y;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
			if (Min[nx][ny] == 987654321) { //방문안했을경우
				Min[nx][ny] = Min[cx][cy] + Map[nx][ny];
				Q.push({ nx,ny });
			}
			else { //방문한경우
				int now = Min[cx][cy] + Map[nx][ny]; //현재 시간
				if (now < Min[nx][ny]) { 
					Min[nx][ny] = now;
					Q.push({ nx,ny });
				}
			}

		}
	}

	return;
}