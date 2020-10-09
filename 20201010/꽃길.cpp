//12:26~1:05 (22분)


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int MMin = 987654321;
int price[15][15];
struct info { int x, y;};
vector<info>Start;
vector<string>Selected;

void Input();
void Select();
void canFlower(int arr[3]);


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Input();
	Select();

	cout << MMin;
	return 0;
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> price[i][j];
		}
	}

	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			Start.push_back({ i,j });
		}
	}
}


void Select(){
	
	vector<int>V;
	for (int i = 0; i < Start.size() - 3; i++) {
		V.push_back(0);
	}
	for (int i = 0; i < 3; i++) {
		V.push_back(1);
	}


	do {
		int arr[3] = { 0 };
		int idx = 0;
		for (int i = 0; i < Start.size(); i++) {
			if (V[i] == 1) {
				arr[idx] = i;
				idx++;
			}
		}
		
		canFlower(arr);

	} while (next_permutation(V.begin(), V.end()));


}

void canFlower(int arr[3]) {

	bool check[15][15] = { false };
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	for (int i = 0; i < 3; i++) {
		int idx = arr[i];
		int cx = Start[idx].x;
		int cy = Start[idx].y;

		check[cx][cy] = true;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (check[nx][ny]) return;
			check[nx][ny] = true;
		}
	}

	//비용계산
	int tot = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j]) tot += price[i][j];
		}
	}

	MMin = min(MMin, tot);
}