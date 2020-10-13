/*
	17:46 ~ 18 : 28 (42분)
	1. 4*4의 맵을 모두 시작점으로 둠
	2. set에 저장해서 거름
*/
#include<iostream>
#include<set>
#include<string>
#include<cstring>

using namespace std;

int Map[5][5];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

set<string>S;

void solve();
void initialize();
void Input();
void go();
void DFS(int x, int y, int cnt, string ans);

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}


void solve() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		initialize();
		Input();
		go();
		cout << '#' << tc << ' ' << S.size() << "\n";
	}
}


void initialize() {
	memset(Map, 0, sizeof(Map));
	S.clear();
}

void Input() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> Map[i][j];
		}
	}
}

void go() { //모든점을 시작점으로 dfs

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int start = Map[i][j];
			string ans = "";
			ans += to_string(start);
			DFS(i,j, 1, ans);
		}
	}
}


void DFS(int x, int y, int cnt, string ans) {

	if (cnt == 7) { //종료조건
		if (S.find(ans) == S.end()) {
			//cout << ans << "\n";
			S.insert(ans);
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4)continue;
		
		DFS(nx, ny, cnt + 1, ans + to_string(Map[nx][ny]));
	}

}