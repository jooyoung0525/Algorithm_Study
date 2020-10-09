//11:44 ~ 12:59 => 1시간15분
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

struct info { int x, y; };
int N;
int Map[25][25];
int MMin = 987654321;
vector<info>Start;
vector<info>Dist;

void StartPoint();
void Input();
void All(); //모든 경우의수
void drawLine(int cx, int cy, int d1, int d2); //경계그리기


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Input();
	StartPoint();
	All();
	cout << MMin;

	return 0;
}


void Input() {

	cin >> N; 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Map[i][j];
		}
	}
}

void StartPoint() {

	for (int i = 1; i <= N - 2; i++) {
		for (int j = 2; j <= N-1; j++) {
			Start.push_back({ i,j });
		}
	}

	for (int i = 1; i < N - 1; i++) {
		for (int j = N - 1 - i; j >= 1; j--) {
			Dist.push_back({ i,j });
		}
	}
}


void All() {
	
	for (int i = 0; i < Start.size(); i++) {
	
		int cx = Start[i].x; //기준점
		int cy = Start[i].y;

		for (int j = 0; j < Dist.size(); j++) {
			int d1 = Dist[j].x;
			int d2 = Dist[j].y;

			drawLine(cx, cy, d1, d2);
		}
	}

}


void drawLine(int cx, int cy, int d1, int d2) {

	bool cpy[25][25] = { false }; //여기다가 경계그리기
	
	cpy[cx][cy] = true; //시작점 방문체크

	//경계1
	for (int i = 1; i <= d1; i++) {
		int nx = cx + i;
		int ny = cy - i;
		if (cpy[nx][ny])continue;
		if (nx > N || ny <= 0)return;
		cpy[nx][ny] = true;
	}

	//경계2
	for (int i = 1; i <= d2; i++) {
		int nx = cx + i;
		int ny = cy + i;
		if (cpy[nx][ny])continue;
		if (nx > N || ny > N)return;
		cpy[nx][ny] = true;
	}

	//경계3
	for (int i = 0; i <= d2; i++) {
		int nx = (cx + d1) + i;
		int ny = (cy - d1) + i;
		if (cpy[nx][ny])continue;
		if (nx > N || ny > N)return;
		cpy[nx][ny] = true;
	}

	//경계4
	for (int i = 0; i <= d1; i++) {
		int nx = (cx+d2) + i;
		int ny = (cy+d2) - i;
		if (cpy[nx][ny])continue;
		if (nx > N || ny <= 0)return;
		cpy[nx][ny] = true;
	}


	//값구하기
	int visit[25][25] = { 0 };
	vector<int>region;

	// 1구역
	int total = 0;
	for (int i = 1; i < cx + d1; i++) {
		for (int j = 1; j <= cy; j++) {
			if (cpy[i][j]) break;
			visit[i][j] = 1;
			total += Map[i][j];
		}
	}
	region.push_back(total);

	// 2구역
	total = 0;
	for (int i = 1; i <= cx + d2; i++) {
		for (int j = N; j >cy; j--) {
			if (cpy[i][j]) break;
			visit[i][j] = 2;
			total += Map[i][j];
		}
	}
	region.push_back(total);


	// 3구역
	total = 0;
	for (int i = cx+d1; i <=N; i++) {
		for (int j = 1; j < cy - d1 + d2; j++) {
			if (cpy[i][j]) break;
			visit[i][j] =3;
			total += Map[i][j];
		}
	}
	region.push_back(total);

	// 4구역
	total = 0;
	for (int i = cx + d2 + 1; i <= N; i++) {
		for (int j = N; j >= cy - d1 + d2; j--) {
			if (cpy[i][j]) break;
			visit[i][j] = 4;
			total += Map[i][j];
		}
	}
	region.push_back(total);

	/*
	cout << "1\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << visit[i][j] << " ";
		}
		cout << "\n";
	}*/

	//5구역
	total = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visit[i][j] == 0) {
				total += Map[i][j];
			}
		}
	}
	region.push_back(total);

	int mmax = *max_element(region.begin(), region.end());
	int mmin = *min_element(region.begin(), region.end());

	if (MMin > (mmax - mmin)) MMin = (mmax - mmin);
}