//2�ð� �ҿ�

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
int priority_dir[450][5][5]; //���id, ����dir, �켱����dir��

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
		if (finish()) { //�� 1���� ���Ҵ���
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
	for (int i = 0; i < N; i++) { //Map0����
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

	for (int i = 1; i <= M; i++) { //�����̵�
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				int a;
				cin >> a;
				priority_dir[i][j][k] = a - 1;
			}
		}
	}

	/*
	cout << "ó�� �������\n";
	for (int j = 0; j < S.size(); j++) {
		cout << S[j].x << " " << S[j].y << " " << S[j].dir << " " << S[j].die << "\n";
	}

	for (int i = 1; i <= M; i++) {
		cout << "��� id : " << i << "\n";
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
		if (!S[i].die)return false; //1����� ���� ����ִ°��
	}
	return true;
}


void Move() {

	info cpy[25][25];
	memcpy(cpy, Map, sizeof(Map));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cpy[i][j].time > 0) { //�ð� ���̰�
				cpy[i][j].time--;
			}
		}
	}

	for (int i = 0; i < S.size(); i++) {
		if (S[i].die)continue; //�������� �׳� �Ѿ
		
		int curID = S[i].id;
		int cx = S[i].x;
		int cy = S[i].y;
		int nowdir = S[i].dir;
		bool m = false;

		//1.���� �켱���� ����ؼ� ��ĭ ã��
		for (int j = 0; j < 4; j++) { //���� �켱����
			int nx = cx + dx[priority_dir[curID][nowdir][j]];
			int ny = cy + dy[priority_dir[curID][nowdir][j]];
			
			if (nx < 0 || ny < 0 || nx >= N || ny >= N || Map[nx][ny].id > 0)continue;

			m = true; //��ĭ ã��
			
			S[i].dir = priority_dir[curID][nowdir][j];
			S[i].x = nx; 
			S[i].y = ny;
			if (cpy[nx][ny].id == 0) { //�ƹ��� ������ �� ���� ���
				cpy[nx][ny] = { curID,K };
			}
			else {	//�ٸ� �� ���� �������ִ� ���
				int origin = cpy[nx][ny].id;
				if (origin > curID) { //������ num�� �� �������  **��� ���̵�**
					S[origin-1].die = true;
					cpy[nx][ny] = { curID,K };
				}
				else { //������� num�� ������� ������ ����
					S[i].die = true;
				}
			}
			break;
		}

		//2.��ĭ ��� �켱���� ��, �ڽ��� ������ ���� ���
		if (!m) {
			for (int j = 0; j < 4; j++) {
				int nx = cx + dx[priority_dir[curID][nowdir][j]];
				int ny = cy + dy[priority_dir[curID][nowdir][j]];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
				if (Map[nx][ny].id == curID) { //�ڱ⳿���� ���ư�
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
			if (cpy[i][j].time == 0) //����������ĭ ����
				cpy[i][j].id = 0;
		}
	}
	memcpy(Map, cpy, sizeof(cpy));
	/*	
	cout << "�������\n";
	for (int j = 0; j < S.size(); j++) {
		cout << S[j].x << " " << S[j].y << " " << S[j].dir <<" "<<S[j].die<< "\n";
	}
	cout << "��\n";
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