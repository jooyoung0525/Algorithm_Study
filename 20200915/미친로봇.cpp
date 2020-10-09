#include<iostream>

using namespace std;


double Ans;
double percent[4];
bool map[31][31];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void DFS(int x, int y, int total, double per);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < 4; i++) {
		cin >> percent[i];
		percent[i] /= 100;
	}
	
	DFS(15, 15, N, 1.0);

	cout << fixed;
	cout.precision(10); //오차의 허용범위가 10^-9이므로 소수점 10까지 출력
	cout << Ans;

	return 0;
}


void DFS(int x, int y, int total, double per) {
	
	map[x][y] = true;

	if (total == 0) {
		Ans += per;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (map[nx][ny] == true)continue;
		
		//여기서 --total 하면 시간초과고, total-1 하면 왜 정답...? 
		DFS(nx, ny, total-1, per * percent[i]);	
	}
	 
	map[x][y] = false;
}
