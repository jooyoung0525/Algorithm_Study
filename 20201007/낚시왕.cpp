#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int R, C, M;
struct info { int x, y, speed, dir, size; bool die; };
vector<info>S;
int Total;
int Map[105][105];
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,1,-1 };

void Input(); //입력
void moveFisher(); //낚시왕 이동 함수
void Catch(int idx); //낚시왕이 상어잡는 함수
void moveShark(); //상어 이동함수


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Input();
	moveFisher();

	cout << Total;
	return 0;
}


void Input() {

	cin >> R >> C >> M;  //Map은 1부터 시작

	S.push_back({ -1,-1,-1,-1,-1,true });
	int X = (R - 1) * 2;
	int Y = (C - 1) * 2;
	for (int i = 1; i <= M; i++) { //상어번호 1부터~M까지
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;

		if (d == 1 || d == 2) {
			S.push_back({ r,c,s%X,d,z,false });
		}
		else if (d == 3 || d == 4) {
			S.push_back({ r,c,s%Y,d,z,false });
		}
		Map[r][c] = i; //맵에 상어표시
		
	}

	/*
	cout << "Start Map" << "\n";
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}
	*/

}

void moveFisher() {

	for (int i = 1; i <= C; i++) {
		Catch(i);
		//cout << "i : " << i << "\n";
		moveShark();
	}
}

void Catch(int idx) {

	for (int i = 1; i <= R; i++) {
		if (Map[i][idx] > 0 && S[Map[i][idx]].die == false) { //맵에 상어가 표시되있고, 살아있으면
			Total += S[Map[i][idx]].size;
			//cout << "idx: " << idx << " Total : " << Total << "\n";
			S[Map[i][idx]].die = true;
			break;
		}
	}
}

void moveShark() {

	memset(Map, 0, sizeof(Map));

	for (int i = 1; i < S.size(); i++) {

		if (S[i].die == true)continue; //죽은상어 건너뜀

		//이동할 현재 상어의 정보
		int cx = S[i].x;
		int cy = S[i].y;
		int s = S[i].size;
		int sp = S[i].speed;
		int d = S[i].dir;
		//cout << cx << " " << cy << " " << s << " " << sp << " " << d <<" "<<S[i].die<< "\n";

		int nx = cx;
		int ny = cy;
		for (int i = 0; i < sp; i++) {
			nx = nx + dx[d];
			ny = ny + dy[d];

			if (nx <= 0 || ny <= 0 || nx > R || ny > C) {
				nx -= dx[d]; //원래의 값
				ny -= dy[d];
				if (d == 1 || d == 2) {
					d = d == 1 ? 2 : 1;
				}
				else if (d == 3 || d == 4) {
					d = d == 3 ? 4 : 3;
				}
				nx += dx[d];
				ny += dy[d];
			}
		}

		//상어가 도착하는 공간에 다른상어가 있다면
		if (Map[nx][ny] > 0) {
			if (s > S[Map[nx][ny]].size) //현재상어가 더 큰경우
			{
				S[Map[nx][ny]].die = true; //기존상어 죽이고
				Map[nx][ny] = i; //현재상어로 맵 리셋 
				S[i] = { nx,ny,sp,d,s,false };
			}

			else { //현재상어가 작은경우는 현재상어 죽이고, Map리셋안해도됨
				S[i].die = true;
			}
		}
		else { //상어가 도착공간이 빈공간이면
			Map[nx][ny] = i;
			S[i] = { nx,ny,sp,d,s,false };
		}
	}
	/*
	cout << "Map" << "\n";
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}
	*/
}