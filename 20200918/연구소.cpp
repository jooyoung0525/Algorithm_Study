/*
1. 0인곳을 벡터에 담음
2. 벡터에서 3개를 뽑아서 벽을세움
3. 바이러스 퍼트림
4. 안전영역 세면서 최대크기 찾기
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

struct info { int x, y; };
int map[10][10]; //원래 처음맵
int N, M;
int MMax = -1;
int dx[] = { -1,1,0,0 };
int dy[] = {0, 0, -1, 1};
vector<info>emptymap;
vector<info>Virus;


void SelectNum();
void BFS(int copy[10][10]);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				emptymap.push_back({ i,j });
			}
			else if (map[i][j] == 2)
				Virus.push_back({ i,j });
		}
	}

	SelectNum();

	cout << MMax;
	
	return 0;
}


void SelectNum() {

	int cpy[10][10] = {0};
	
	/*	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << cpy[i][j] << " ";
		}
		cout << "\n";
	}*/

	/*
	cout << "emptyroom" << "\n";
	for (int i = 0; i < emptymap.size(); i++)
		cout << i << " ";
	cout << "\n";*/

	//빈칸중 3개 고름
	vector<int>per;
	for (int i = 0; i < 3; i++) {
		per.push_back(1);
	}
	for (int i = 0; i < emptymap.size() - 3; i++) {
		per.push_back(0);
	}

	sort(per.begin(), per.end());

	do {

		memcpy(cpy, map, sizeof(map)); //원본 map복사해서 체크된 벽세움
		for (int i = 0; i < emptymap.size(); i++) {
			if (per[i] == 1) {
				cpy[emptymap[i].x][emptymap[i].y] = 1;
			}
		}

		/*
		cout << "\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << cpy[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";*/

		BFS(cpy);
		

	} while (next_permutation(per.begin(), per.end()));
	





}


void BFS(int copy[10][10]) {

	queue<info>Q;
	for (int i = 0; i < Virus.size(); i++) {
		Q.push({ Virus[i].x,Virus[i].y });
	}

	while (!Q.empty()) 
	{
		int cx = Q.front().x;
		int cy = Q.front().y;
		Q.pop();

		for (int i = 0; i < 4; i++) {
		
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
			if (copy[nx][ny] == 0) {
				copy[nx][ny] = 2;
				Q.push({ nx,ny });
			}
		}
	
	}

	/*
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << copy[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";*/

	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copy[i][j] == 0)count++;
		}
	}

	if (count > MMax) MMax = count;
}