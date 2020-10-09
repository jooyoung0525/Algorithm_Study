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

void Input(); //�Է�
void moveFisher(); //���ÿ� �̵� �Լ�
void Catch(int idx); //���ÿ��� ������ �Լ�
void moveShark(); //��� �̵��Լ�


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Input();
	moveFisher();

	cout << Total;
	return 0;
}


void Input() {

	cin >> R >> C >> M;  //Map�� 1���� ����

	S.push_back({ -1,-1,-1,-1,-1,true });
	int X = (R - 1) * 2;
	int Y = (C - 1) * 2;
	for (int i = 1; i <= M; i++) { //����ȣ 1����~M����
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;

		if (d == 1 || d == 2) {
			S.push_back({ r,c,s%X,d,z,false });
		}
		else if (d == 3 || d == 4) {
			S.push_back({ r,c,s%Y,d,z,false });
		}
		Map[r][c] = i; //�ʿ� ���ǥ��
		
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
		if (Map[i][idx] > 0 && S[Map[i][idx]].die == false) { //�ʿ� �� ǥ�õ��ְ�, ���������
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

		if (S[i].die == true)continue; //������� �ǳʶ�

		//�̵��� ���� ����� ����
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
				nx -= dx[d]; //������ ��
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

		//�� �����ϴ� ������ �ٸ��� �ִٸ�
		if (Map[nx][ny] > 0) {
			if (s > S[Map[nx][ny]].size) //����� �� ū���
			{
				S[Map[nx][ny]].die = true; //������� ���̰�
				Map[nx][ny] = i; //������� �� ���� 
				S[i] = { nx,ny,sp,d,s,false };
			}

			else { //����� �������� ������ ���̰�, Map���¾��ص���
				S[i].die = true;
			}
		}
		else { //�� ���������� ������̸�
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