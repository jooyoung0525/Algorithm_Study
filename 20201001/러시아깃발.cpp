#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

struct Color {
	int white, blue;
};
vector<Color>Sep;
int T;
int N, M;
int MMin = 987654321;
char flag[55][55];

void seperate();
void Init_all();
void paint_color();

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	for (int testcase = 1; testcase <= T; testcase++) {
	
		Init_all(); //�ʱ�ȭ

		//�Է�
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> flag[i][j];
			}
		}

		//�������κ� ������
		seperate();

		//���� ���� ��ĥ�ؾ��ϴ� �κ� ī��Ʈ
		paint_color();
		
		cout << '#' << testcase << " " << MMin << "\n";
	}
	return 0;
}

void Init_all() {

	MMin = 987654321;
	N = 0; M = 0; 
	memset(flag, 0, sizeof(flag));
	Sep.clear();
}

void paint_color()
{
	//���� ���� ���鼭 ��ĥ
	for (int i = 0; i < Sep.size(); i++) {
		int w = Sep[i].white;
		int b = Sep[i].blue;
		int count = 0;

		//���
		for (int j = 0; j < w; j++) {
			
			for (int k = 0; k < M; k++) {
				if (flag[j][k] != 'W') count++;
			}
		}

		//�Ķ���
		for (int j = w; j < w+b; j++) {

			for (int k = 0; k < M; k++) {
				if (flag[j][k] != 'B')count++;
			}
		}

		//������
		for (int j = w+b; j < N; j++) {

			for (int k = 0; k < M; k++) {
				if (flag[j][k] != 'R')count++;
			}
		}

		if (MMin > count)MMin = count;
	}
}


void seperate() {

	for (int i = 1; i <= N - 2; i++) {
	
		for (int j = 1; j <= N - i - 1; j++) {
		
			Sep.push_back({i,j});
		}
	}

}