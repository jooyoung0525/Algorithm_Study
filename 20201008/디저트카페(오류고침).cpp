#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct info { int x, y; };
int T, N;
int MMax = -1;
int Cafe[25][25];
int dx[] = { 1,1,-1,-1 };
int dy[] = { 1,-1,-1,1 };
bool isNum[105];
vector<info>Start;
int Startx = 0; int Starty = 0;
void Input();
void Init();
void startPoint();
void Go();
void DFS(int x, int y, int dir, int cnt, int changeN);
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int testcase = 1; testcase <= T; testcase++) {

		Init();
		Input();
		startPoint();
		Go();
		cout << "#" << testcase << " " << MMax << "\n";
	}
	return 0;
}
void Init() {
	N = 0, Startx = 0, Starty = 0;
	memset(Cafe, 0, sizeof(Cafe));
	memset(isNum, false, sizeof(isNum));
	Start.clear();
	MMax = -1;
}
void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Cafe[i][j];
		}
	}
}
void startPoint() {
	for (int i = 0; i < N - 2; i++) {
		for (int j = 1; j < N - 1; j++) {
			Start.push_back({ i,j });
		}
	}
}
void Go() {
	for (int i = 0; i < Start.size(); i++) {

		memset(isNum, false, sizeof(isNum)); //숫자 방문체크하는거 시작점별로 갱신.
		int cx = Start[i].x;
		int cy = Start[i].y;
		Startx = cx; Starty = cy; //시작점을 전역으로 잡아줌
		isNum[Cafe[cx][cy]] = true; //현재시작점 숫자 방문체크

		//cout << "dfs go" << "\n";
		//cout << Cafe[cx][cy] << "\n";
		DFS(cx, cy, 0, 1, 0);
		//if (MMax == (N - 1) * 2) break; //이미 최대로 만들수있는 경로를 방문한 적이 있으면 끝냄.
	}
}
void DFS(int x, int y, int dir, int cnt, int changeN) {

	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx == Startx && ny == Starty && dir == 3) {
		MMax = max(MMax, cnt);
		return;
	}
	if (nx < 0 || ny < 0 || nx >= N || ny >= N) return; //범위를 넘거나, 이미 방문한 숫자인경우 경우를 보지 않고 리턴
	if (!isNum[Cafe[nx][ny]]) {
		//cout << nx << ny << "\n";

		isNum[Cafe[nx][ny]] = true; //앞의 조건에 걸리지 않았다면 현재점의 숫자 방문체크

		DFS(nx, ny, dir % 4, cnt + 1, changeN); //방향을 유지한채로 갈 수 있고
		DFS(nx, ny, (dir + 1) % 4, cnt + 1, changeN + 1); //방향을 한번 꺽어서 갈 수 있음

		isNum[Cafe[nx][ny]] = false;

	}
}
