#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

struct info { int x, y, num; };
int N, M;
int Map[10][10];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
vector<info>cctv;
int MMin = 987654321;

void Input();//입력함수
void Run(int cnt); //사무실에 있는 모든 CCTV돌려보는 함수
void cctvRun(int dir,int x, int y); //한방향으로 cctv실행
void Count(); //사각지대 세는 함수

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Input();
	Run(0);

	cout << MMin;
	return 0;
}



void Input() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
			if (Map[i][j] >= 1 && Map[i][j] <= 5)
				cctv.push_back({ i,j,Map[i][j] });
		}
	}
}


void Run(int cnt) {
	
	if (cnt == cctv.size()) {
		Count();
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << Map[i][j] << " ";
			}
			cout << "\n";
		}*/
		return;
	}


	int cpy[10][10] = { 0 }; 
	memcpy(cpy, Map, sizeof(Map)); //cpy에 이전Map 저장

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << cpy[i][j] << " ";
		}
		cout << "\n";
	}*/
	
	int cx = cctv[cnt].x;
	int cy = cctv[cnt].y;
	int cnum = cctv[cnt].num;
	
	if (cnum == 1) {
		for (int i = 0; i < 4; i++) {
			cctvRun(i, cx, cy);
			Run(cnt + 1);
			//복구
			memcpy(Map, cpy, sizeof(cpy)); 
		}
	}
	else if (cnum == 2) {
		for (int i = 0; i < 2; i++) {
			cctvRun(i, cx, cy);
			cctvRun(i + 2, cx, cy);
			Run(cnt + 1);
			//복구
			memcpy(Map, cpy, sizeof(cpy));
		}
	}
	else if (cnum == 3) {
		for (int i = 0; i < 4; i++) 
		{
			for (int j = i; j < i + 2; j++) 
			{
				cctvRun(j % 4, cx, cy);
			}
			Run(cnt + 1);
			//복구
			memcpy(Map, cpy, sizeof(cpy));
		}
	}
	else if (cnum == 4) {
		for (int i = 0; i < 4; i++) 
		{
			for(int j = i; j<i+3; j++)
			{
				cctvRun(j % 4, cx, cy);
			}
			Run(cnt + 1);
			//복구
			memcpy(Map, cpy, sizeof(cpy));
		}
	}
	else if (cnum == 5) {
		for (int i = 0; i < 4; i++) 
		{
			cctvRun(i, cx, cy);
		}
		Run(cnt + 1);
		//복구
		memcpy(Map, cpy, sizeof(cpy));
	}

}

void cctvRun(int dir, int x, int y) {

	int nx = x;
	int ny = y;

	while (1) {
		nx += dx[dir];
		ny += dy[dir];
		
		if (nx < 0 || ny < 0 || nx >= N || ny >= M || Map[nx][ny] == 6)break;
		Map[nx][ny] = 7;
	}
}


void Count() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 0)cnt++;
		}
	}

	MMin = min(MMin, cnt);
}