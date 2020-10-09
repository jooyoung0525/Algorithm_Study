#include<iostream>

using namespace std;

int Banner[300][300];
bool Visit[300][300] = {false};
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };
int Col,Row;

void Input();
int Find_Letter();
void DFS(int C, int R);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Input();
	int result = Find_Letter();
	cout << result;


	return 0;
}


void Input() {
	cin >> Col >> Row;
	
	for (int i = 0; i < Col; i++) {
		for (int j = 0; j < Row; j++) {
			cin >> Banner[i][j];
		}
	}
}


int Find_Letter() {

	int letter = 0;

	for (int i = 0; i < Col; i++) {
		for (int j = 0; j < Row; j++) {
			if (Banner[i][j] == 1 && !Visit[i][j])
			{
				Visit[i][j] = true;
				DFS(i, j);
				letter++;
			}
		}
	}

	return letter;
}

void DFS(int curC, int curR) {

	for (int i = 0; i < 8; i++) {
		int nx = curC + dx[i];
		int ny = curR + dy[i];
		
		if (nx < 0 || ny < 0 || nx >= Col || ny >= Row)continue;

		if (Banner[nx][ny] == 1 && !Visit[nx][ny]) {
			Visit[nx][ny] = true;
			DFS(nx, ny);
		}
	}

	return;
}