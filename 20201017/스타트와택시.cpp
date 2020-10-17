//1:17분소요

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct taxi { int id, x, y, fuel; }; //태운승객 아이디 택시 위치와 남은연료
struct person { int sx, sy, ex, ey, dist; bool die; }; //각 승객의 시작, 도착정보 ,택시에서 승객까지 거리
struct fastperson { int id, x, y, dist; };

bool stop = false;
int N, M;
int Map[25][25];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<person>P;
taxi T;

bool cmp(fastperson a, fastperson b) {
	if (a.dist == b.dist) {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		return a.x < b.x;
	}
	return a.dist < b.dist;
}
void solution();
void Input();
void Find();
void Drive();
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
	
	while (1) {
	
		Find(); //택시위치에서 BFS
		if (stop)break;
		Drive(); //승객위치에서 BFS
		if (stop || finish())break;

	}

	if (stop)cout << -1;
	else cout << T.fuel;

}


void Input() {

	cin >> N >> M >> T.fuel; //맵크기, 승객수, 초기연료
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Map[i][j]; // 맵 입력
		}
	}
	
	cin >> T.x >> T.y; //택시 초기위치
	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		P.push_back({ a,b,c,d,false});
	}

	T.id = -1;
}


void Find() {

	struct info { int x, y; };
	queue<info>Q;
	int visit[25][25] = { 0 }; //거리저장
	//택시가 0이므로 배열 -1로 초기화
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			visit[i][j] = -1;
		}
	}

	Q.push({ T.x,T.y});
	visit[T.x][T.y] = 0;

	while (!Q.empty()) {
	
		int cx = Q.front().x;
		int cy = Q.front().y;
		Q.pop();

		for (int i = 0; i < 4; i++) {
		
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx<1 || ny<1 || nx>N || ny>N || visit[nx][ny] > -1 ||Map[nx][ny]==1)continue; 
			visit[nx][ny] = visit[cx][cy] + 1;
			Q.push({ nx,ny });
		}
	}

	/*
	cout << "디버깅1\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << visit[i][j] << "   ";
		}
		cout << "\n";
	}
	cout << "\n";*/
	

	vector<fastperson>FP; //승객아이디, 시작위치, 택시와의 거리

	for (int i = 0; i < M; i++) {
		if (P[i].die)continue; //한번 도착한 승객 제외
		int cx = P[i].sx;
		int cy = P[i].sy;
		int cdist = visit[cx][cy];
		if (cdist == -1)continue;
		FP.push_back({ i,cx,cy,cdist });
	}

	if (FP.size() > 1)
		sort(FP.begin(), FP.end(), cmp);

	if (FP.empty()) {
		stop = true;
		return;
	}
	//택시가 태우러갈 손님
	int id = FP[0].id;
	//cout << "택시 연료 : " << T.fuel << "\n";
	T.fuel -= FP[0].dist; //택시가 손님태우러가면서 연료 소진
	if (T.fuel < 0) {
		stop = true;
		return;
	}
	//cout << "택시~손님 : " << T.fuel << "\n";
	T.x = FP[0].x; T.y = FP[0].y; //택시정보 갱신
	T.id = id;
}
 
void Drive() {

	struct info { int x, y; };
	queue<info>Q;
	int visit[25][25] = { 0 }; //거리저장
	//택시가 0이므로 배열 -1로 초기화
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			visit[i][j] = -1;
		}
	}

	Q.push({ T.x,T.y }); //승객태운 택시위치
	visit[T.x][T.y] = 0;

	while (!Q.empty()) {

		int cx = Q.front().x;
		int cy = Q.front().y;
		Q.pop();

		for (int i = 0; i < 4; i++) {

			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx<1 || ny<1 || nx>N || ny>N || visit[nx][ny] > -1 || Map[nx][ny] == 1)continue;
			visit[nx][ny] = visit[cx][cy] + 1;
			Q.push({ nx,ny });
		}
	}

	/*
	cout << "디버깅2\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << visit[i][j] << "   ";
		}
		cout << "\n";
	}
	cout << "\n";
	*/

	//현재 택시타고있는 승객 정보
	int nowperson = T.id;
	int endx = P[nowperson].ex;
	int endy = P[nowperson].ey;
	P[nowperson].die = true; //승객 도착
	T.x = endx;
	T.y = endy;

	//도착지점까지 최소거리
	int arrivedist = visit[endx][endy];
	if (arrivedist == -1) {
		stop = true;
		return;
	}
	T.fuel -= arrivedist;
	if (T.fuel < 0) {
		stop = true;
		return;
	}
	T.fuel += (arrivedist * 2);
	//cout << "출발 ~ 도착 : " << T.fuel<<"\n";
}


bool finish() {

	for (int i = 0; i < M; i++) {
		if (!P[i].die)return false;
	}
	return true;

}