//2시간 소요

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

struct info{ int id, time; };
struct shark { int id, x, y, dir; bool die; };

int N, M, K;
info Map[25][25];
vector<shark>S;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int priority_dir[450][5][5]; //상어id, 현재dir, 우선순위dir순

bool cmp(shark a, shark b) {
	return a.id < b.id;
}
void solution();
void Input();
void Move();
bool finish();


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	solution();

	return 0;
}


void solution() {

	Input();
	/*
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << Map[i][j].id << " " << Map[i][j].time << "   ";
		}
		cout << "\n";
	}*/
	bool flag = false;
	int time = 0;

	for (int i = 1; i <=1000; i++) {
		Move();
		if (finish()) { //상어가 1번만 남았는지
			time = i;
			flag = true;
			break;
		}
	}
	/*
	cout << "\n";
	for (int j = 0; j < S.size(); j++) {
		cout << S[j].x << " " << S[j].y << " " << S[j].dir << " " << S[j].die << "\n";
	}*/
	if (!flag)cout << -1;
	else cout << time;
}


void Input() {

	
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) { //Map0부터
		for (int j = 0; j < N; j++) {
			int a; 
			cin >> a;
			
			if (a > 0) {
				Map[i][j] = { a,K };
				S.push_back({ a,i,j,0,false });
			}
		}
	}

	if (M > 1) sort(S.begin(), S.end(), cmp);

	for (int i = 0; i < M; i++) {
		int d;
		cin >> d;
		S[i].dir = d-1;
	}

	for (int i = 1; i <= M; i++) { //상어아이디
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				int a;
				cin >> a;
				priority_dir[i][j][k] = a - 1;
			}
		}
	}

	/*
	cout << "처음 상어정보\n";
	for (int j = 0; j < S.size(); j++) {
		cout << S[j].x << " " << S[j].y << " " << S[j].dir << " " << S[j].die << "\n";
	}

	for (int i = 1; i <= M; i++) {
		cout << "상어 id : " << i << "\n";
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cout << priority_dir[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	*/
}


bool finish() {
	for (int i = 1; i < S.size(); i++) {
		if (!S[i].die)return false; //1번상어 빼고 살아있는경우
	}
	return true;
}


void Move() {

	info cpy[25][25];
	memcpy(cpy, Map, sizeof(Map));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cpy[i][j].time > 0) { //시간 줄이고
				cpy[i][j].time--;
			}
		}
	}

	for (int i = 0; i < S.size(); i++) {
		if (S[i].die)continue; //죽은상어면 그냥 넘어감
		
		int curID = S[i].id;
		int cx = S[i].x;
		int cy = S[i].y;
		int nowdir = S[i].dir;
		bool m = false;

		//1.방향 우선순위 고려해서 빈칸 찾기
		for (int j = 0; j < 4; j++) { //방향 우선순위
			int nx = cx + dx[priority_dir[curID][nowdir][j]];
			int ny = cy + dy[priority_dir[curID][nowdir][j]];
			
			if (nx < 0 || ny < 0 || nx >= N || ny >= N || Map[nx][ny].id > 0)continue;

			m = true; //빈칸 찾음
			
			S[i].dir = priority_dir[curID][nowdir][j];
			S[i].x = nx; 
			S[i].y = ny;
			if (cpy[nx][ny].id == 0) { //아무도 도착한 상어가 없는 경우
				cpy[nx][ny] = { curID,K };
			}
			else {	//다른 상어가 먼저 도착해있는 경우
				int origin = cpy[nx][ny].id;
				if (origin > curID) { //현재상어 num이 더 작은경우  **상어 아이디값**
					S[origin-1].die = true;
					cpy[nx][ny] = { curID,K };
				}
				else { //기존상어 num이 작은경우 현재상어 죽임
					S[i].die = true;
				}
			}
			break;
		}

		//2.빈칸 없어서 우선순위 중, 자신의 냄새로 가는 경우
		if (!m) {
			for (int j = 0; j < 4; j++) {
				int nx = cx + dx[priority_dir[curID][nowdir][j]];
				int ny = cy + dy[priority_dir[curID][nowdir][j]];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
				if (Map[nx][ny].id == curID) { //자기냄새로 돌아감
					S[i].dir = priority_dir[curID][nowdir][j];
					S[i].x = nx;
					S[i].y = ny;
					cpy[nx][ny] = { curID,K };
					break;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cpy[i][j].time == 0) //냄새없어진칸 갱신
				cpy[i][j].id = 0;
		}
	}
	memcpy(Map, cpy, sizeof(cpy));
	/*	
	cout << "상어정보\n";
	for (int j = 0; j < S.size(); j++) {
		cout << S[j].x << " " << S[j].y << " " << S[j].dir <<" "<<S[j].die<< "\n";
	}
	cout << "맵\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << Map[i][j].id << " " << Map[i][j].time << "   ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "\n";
	*/
	

}