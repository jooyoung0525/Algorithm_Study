//최소시간 구하기.
/*
	BFS (위치,시간,소용돌이기다리는지)
	1. 시작점을 BFS태운다 -
*/

#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

# define MAX 987654321
using namespace std;

struct info { int x, y; };
struct info2 { int x, y, time; bool storm; };
int T;
int N;
int Map[20][20];
bool check[20][20];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
info startpoint, endpoint;

void solve();
void initialize();
void Input();
int go();

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();
	
	return 0;
}



void solve() {
	
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		initialize();
		Input();
		int result = go();
		cout << '#' << tc << ' ' << result<<"\n";
	}
}


void initialize() {

	
	N = 0;
	memset(Map, 0, sizeof(Map));
	memset(check, false, sizeof(check));
	startpoint = { 0,0 };
	endpoint = { 0,0 };

}

void Input() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
		}
	}

	cin>>startpoint.x;
	cin>>startpoint.y;
	
	cin>>endpoint.x;
	cin>>endpoint.y;
	//cout << endpoint.x << " " << endpoint.y << "\n";
}


int go() {

	queue<info2>Q;
	Q.push({ startpoint.x,startpoint.y,0,false});
	check[startpoint.x][startpoint.y] = true;


	while (!Q.empty()) {
	
		int cx = Q.front().x;
		int cy = Q.front().y;
		int ct = Q.front().time;
		bool storm = Q.front().storm;
		//cout << cx << " " << cy << " "<<ct<<"\n";
		Q.pop();
		
		if (cx == endpoint.x && cy == endpoint.y) {
				return ct;
		}

		for (int i = 0; i < 4; i++) {
		
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N|| check[nx][ny])continue;
			
			if (Map[nx][ny] == 0) {
				check[nx][ny] = true;
				Q.push({ nx,ny,ct + 1,storm});
			}
			else if (Map[nx][ny] == 2) {
				if ((ct+1) % 3 == 0 && ct>0) { //소용돌이 지나갈 수 있음
					check[nx][ny] = true;
					Q.push({ nx,ny,ct+1,true});
				}
				else { //지날 수 없음
					Q.push({ cx,cy,ct + 1,storm});//위치는 그대로 시간만 흘려보냄
				}
			}
		}
	}

	return -1;
}