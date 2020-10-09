//17:57~18:29 => 32��

#include<iostream>

using namespace std;

int N;
int Room[20][20];
int Answer = 0;

void Input();
void DFS(int cx, int cy, int shape);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Input();
	DFS(1, 2, 1); //������ ��ġ�� ��������

	cout << Answer;
	return 0;
}


void Input() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Room[i][j];
		}
	}
}





void DFS(int cx, int cy, int shape) {

	if (cx == N && cy == N) {
		Answer++;
		return;
	}

	if (shape == 1) { //���θ��
		
		//���θ�� �����Ұ��
		int nx = cx;
		int ny = cy + 1;
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N && Room[nx][ny] == 0) {
			DFS(nx, ny, 1);
		}

		//ȸ�����Ѽ� �밢�����
		nx = cx + 1;
		ny = cy + 1;
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N && Room[nx][ny] == 0 &&Room[cx+1][cy] == 0 && Room[cx][cy+1] == 0) {
			DFS(nx, ny, 3);
		}
	}

	else if (shape == 2) { //���� ���
		
		//���θ�� �����Ұ��
		int nx = cx + 1;
		int ny = cy;
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N && Room[nx][ny] == 0) {
			DFS(nx, ny, 2);
		}

		//ȸ�����Ѽ� �밢�����
		nx = cx + 1;
		ny = cy + 1;
		if (nx >= 1 && ny >= 1 && nx <=N && ny <= N && Room[nx][ny] == 0 && Room[cx + 1][cy] == 0 && Room[cx][cy + 1] == 0) {
			DFS(nx, ny, 3);
		}
	}

	else if (shape == 3) { //�밢�� ���

		//�밢�� ��� ����
		int nx = cx + 1;
		int ny = cy + 1;
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N && Room[nx][ny] == 0 && Room[cx + 1][cy] == 0 && Room[cx][cy + 1] == 0) {
			DFS(nx, ny, 3);
		}
	
		//���θ��
		nx = cx;
		ny = cy + 1;
		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N && Room[nx][ny] == 0) {
			DFS(nx, ny, 1);
		}

		//���θ��
		nx = cx + 1;
		ny = cy;

		if (nx >= 1 && ny >= 1 && nx <= N && ny <= N && Room[nx][ny] == 0) {
			DFS(nx, ny, 2);
		}
	}

}