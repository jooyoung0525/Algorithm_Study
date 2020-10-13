//16:07~17:42(1시간 35분)

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

struct info { int x, y, de; bool deactive; int ac; bool active, die, spread; };
int N, M, K;
int Map[900][900];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<info>Bug;

void solve();
void Input();
void play();
void activeBug();
int calLive();
void initialize();

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}



void solve() {

	int T = 0;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
	
		initialize();
		Input();
		play();
		int result = calLive();
		cout << '#' << tc << ' ' <<result<< "\n";
	}
}

void initialize() {

	N = 0, M = 0, K = 0;
	memset(Map, 0, sizeof(Map));
	Bug.clear();
}

void Input() {

	cin >> N >> M >> K;
	for (int i = 400; i < N+400; i++) {
		for (int j = 400; j < M + 400; j++) {

			cin >> Map[i][j];
			if (Map[i][j] > 0) {
				Bug.push_back({ i,j,Map[i][j],true,Map[i][j],false,false,false });
			}
		}
	}
	/*
	cout << "Map\n";
	for (int i = 400; i < N + 400; i++) {
		for (int j = 400; j < M + 400; j++) {
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}


	for (int i = 0; i < Bug.size(); i++) {
		cout <<i<<" : "<< Bug[i].x << " " << Bug[i].y << " " << Bug[i].de << " " << Bug[i].deactive << " " << Bug[i].ac << " " << Bug[i].active << " " << Bug[i].die << " " << Bug[i].spread << "\n";
	}
	*/
}



void play() {

	for (int i = 0; i < K; i++) { //K시간 동안 세포번식
		//cout << i << "i" << "\n";
		activeBug();
	}
}


void activeBug() {

	vector<info>newBug;

	for (int i = 0; i < Bug.size(); i++) {
		
		if (Bug[i].die)continue;

		int cx = Bug[i].x;
		int cy = Bug[i].y;
		int cde = Bug[i].de;
		bool deactive = Bug[i].deactive;
		int cac = Bug[i].ac;
		bool active = Bug[i].active;
		bool die = Bug[i].die;
		bool spread = Bug[i].spread;
	
		if (deactive && cde > 0) { //비활성진행
			Bug[i].de--;
			if (Bug[i].de == 0) { //비활성 끝남
				Bug[i].deactive = false; 
				Bug[i].active = true; //활성화
			}
		}
		else if (cac > 0 && active) {
			if (!spread) {
				//번식
				for (int j = 0; j < 4; j++) {
					int nx = cx + dx[j];
					int ny = cy + dy[j];
					if (Map[nx][ny] == 0) {
						Map[nx][ny] = Map[cx][cy];
						newBug.push_back({ nx,ny,Map[nx][ny],true,Map[nx][ny],false,false,false });
					}
				}
				Bug[i].spread = true;
			}
			Bug[i].ac--;
			//cout << i << " " << Bug[i].ac << " ";
			if (Bug[i].ac == 0) {
				Bug[i].active = false;
				Bug[i].die = true;
				//cout << "die" << "\n";
			}
		}
	}
	/*
	cout << "Map\n";
	for (int i = 390; i < 410; i++) {
		for (int j = 390; j < 410; j++) {
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "newBug\n";
	*/
	//번식세포 추가
	for (int i = 0; i < newBug.size(); i++) {
		//cout << newBug[i].x << " " << newBug[i].y << "\n";
		Bug.push_back(newBug[i]);
	}
}


int calLive() {

	int cnt = 0;
	for (int i = 0; i < Bug.size(); i++)
	{
		//cout <<i<<" : "<< Bug[i].die << "\n";
		if (!Bug[i].die)cnt++;
	}
	
	return cnt;
}