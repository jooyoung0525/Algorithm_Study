//??? 왜...N이...최대가40????????????????????????????????????? 1시간15분

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

struct info { int x, y;};
struct val { int N, cost; };
val Cost[50]; //가로,세로의크기와 운영비용

int N, M,K;
int Map[25][25];
vector<info>House;
int MMax = -1;

void solve();
void calCost();
void initialize();
void Input();
void go(); //전체점들을 기준으로 1~K돌면서 최대집의개수찾음
void findHouse(int x,int y, int len, int cost);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();
	return 0;
}


void solve() {
	
	//운영비용미리구해놓기
	calCost();

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		
		initialize();
		Input();
		go();

		cout << '#' << tc << ' ' <<MMax<< "\n";
	}
}

void calCost() {//운영비용구하기

	for (int i = 1; i <= 40; i++) {
		int v = pow(i, 2) + pow(i - 1, 2);
		Cost[i] = { (i * 2) - 1,v };
	}
	/*
	for (int i = 1; i <= 10; i++) {
		cout << Cost[i].N << " " << Cost[i].cost << "\n";
	}*/
}


void Input() {
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 1) {
				House.push_back({ i,j });
			}
		}
	}
}



void go() { //전체점들을 기준으로 1~K돌면서 최대집의개수찾음


	for(int i = 0; i<N; i++){
		for (int j = 0; j < N; j++) {
			for (int a = 1; a <= 40; a++) {
				findHouse(i, j, a-1,Cost[a].cost);
			}
		}
	}

}

void findHouse(int x, int y, int len, int cost) {

	int cnt = 0;
	for (int i = 0; i < House.size(); i++) {
		int cx = House[i].x;
		int cy = House[i].y;

		if (abs(x - cx) + abs(y - cy) > len) continue;
		cnt++;
	}

	int all = (cnt * M) - cost;
	if (all < 0)return;
	else {
		if (MMax < cnt) MMax = cnt;
	}

}


void initialize() {

	N = 0, M = 0, K = 0;
	memset(Map, 0, sizeof(Map));
	House.clear();
	MMax = -1;
}