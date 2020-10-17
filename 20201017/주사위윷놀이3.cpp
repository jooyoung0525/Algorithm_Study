#include<iostream>
#include<string>
#include<vector>
#include<cstring>

using namespace std;

struct info { int path, idx; bool arrival; }; //���� �̹� �����Ѹ��̸� continue;
vector<string>Mal;
int Turn[10];      //[0][5]������ [1][]��, [0][10]������ [2][]��, [0][15]������ [3][]��, [0][20] & [4][4]����
int path[6][25] = { {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40}, //�����ư��� ���, 
					{10,13,16,19,25}, //[1][4]������ [4][]��
					{20,22,24,25}, //[2][3]������ [4][]��
					{30,28,27,26,25}, //[3][4]������ [4][]��
					{25,30,35,40}};
int MMax = -1;

void Input();
void solution();
void findAllpath(int cnt, string p);
void play();
bool finish(int path, int nidx, bool visit[6][25]);
info Go(info mal, int cango);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}

void Input() {
	for (int i = 0; i < 10; i++) {
		cin >> Turn[i];
	}
}

void solution() {

	Input();
	string s ="1";
    findAllpath(0,s); //DFS�� 0~10���� 1,2,3,4�� �����ֱ�
	play();
	cout << MMax;
}

void findAllpath(int cnt, string p) {

	if (cnt == 9) {
		//cout << p << "\n";
		Mal.push_back(p);
		return;
	}

	for (int i = 1; i <= 4; i++) {
		findAllpath(cnt + 1, p + to_string(i));
	}
}


bool finish(int path, int nidx, bool visit[6][25]) {

	if (visit[path][nidx]) { //�����̵�ĭ�� �ٸ����� ������ ���� -> �������Ž��
		return true;
	}
	if (path == 0 && nidx == 20 && visit[4][3]) { //���������� ����
		return true;
	}
	if (path == 4 && nidx == 3 && visit[0][20]) {
		return true;
	}

	return false;
}

info Go(info mal,int cango) {

	int nextPath = mal.path;
	int nextidx = mal.idx + cango;
	bool narrival = mal.arrival;

	if (nextPath == 0) {
		if (nextidx == 5) { //5������ ���2����
			nextPath = 1;
			nextidx = 0;
		}
		else if (nextidx == 10) { //10������ ���3����
			nextPath = 2;
			nextidx = 0;
		}
		else if (nextidx == 15) { //10������ ���3����
			nextPath = 3;
			nextidx = 0;
		}
		else if (nextidx >= 21) narrival = true;
	}
	else if (nextPath == 1 || nextPath == 3) {
		if (nextidx >= 4) {
			nextPath = 4;
			nextidx -=4;
		}
	}
	else if (nextPath == 2) {

		if (nextidx >= 3) {
			nextPath = 4;
			nextidx -= 3;
		}
	}
	else if (nextPath == 4) {
		if (nextidx > 3) narrival = true;
	}

	info newmal = { nextPath,nextidx,narrival };

	return newmal;
}


void play() {

	//Mal.push_back("1121333133");
	int tot = 0;//������ ��
	bool visit[6][25] = { false }; //�̵��ϴ� �� �湮üũ
	bool jump = false;
	info One = { 0,0,false }; info Two = { 0,0,false }; info Three = { 0,0,false }; info Four = { 0,0,false }; //���� ��� ����

 	for (int i = 0; i < Mal.size(); i++) {
		string cur = Mal[i];
		
		tot = 0;//������ ��
		memset(visit, false, sizeof(visit));
		jump = false;

		One = {0,0,false}; Two = { 0,0,false }; Three = { 0,0,false }; Four = { 0,0,false }; //���� ��� ����

		for (int j = 0; j < cur.length(); j++) {
			
			int nowMal = cur[j] - '0'; //�������
			int cango = Turn[j]; //��ĭ�����ϴ���
			//cout << "�����̵�\n";
			//cout << nowMal << "���� -> " << cango << "ĭ �̵�\n";
			if (cango == 0)continue;
			if (nowMal == 1) {

				if (One.arrival)continue; //�̵��ؾ��ϴ� ���� ���� ����ĭ�� �����ϸ� ���� �̵� �ǳʶ�
				visit[One.path][One.idx] = false; //���� 1������ ��ġ false -> �������� �̵��ؾ��ؼ�
				info newM = Go(One, cango); //�������
				//cout << "�̵� �� : " << One.path << " " << One.idx << " " << One.arrival << "\n";
				if (finish(newM.path, newM.idx, visit)) { //�ߺ��̸� ����
					jump = true;
					break;
				}
				
				One = newM;
				//cout << "�̵� �� : " << One.path << " " << One.idx << " " << One.arrival << "\n";
					
				if ((One.path == 0 && One.idx >=21)||(One.path == 4 && One.idx >=4)) {//������ ������ (������������ �湮üũ���� ����)
					//tot += path[One.path][One.idx];
					continue;
				}

				visit[One.path][One.idx] = true; //������ �湮üũ
				tot += path[One.path][One.idx];

				//cout << "1 p : " << One.path << " idx : " << One.idx << "\n";
				//cout << path[One.path][One.idx] <<" ";
			}
			else if (nowMal == 2) {

				if (Two.arrival)continue; //�̵��ؾ��ϴ� ���� ���� ����ĭ�� �����ϸ� ���� �̵� �ǳʶ�
				visit[Two.path][Two.idx] = false; //���� 1������ ��ġ false -> �������� �̵��ؾ��ؼ�
				info newM = Go(Two, cango); //�������
				
				if (finish(newM.path, newM.idx, visit)) { //�ߺ��̸� ����
					jump = true;
					break;
				}

				Two = newM;

				if ((Two.path == 0 && Two.idx >= 21) || (Two.path == 4 && Two.idx >= 4)) {//������ ������ (������������ �湮üũ���� ����)
					//tot += path[Two.path][Two.idx];
					continue;
				}

				visit[Two.path][Two.idx] = true; //������ �湮üũ
				tot += path[Two.path][Two.idx];
				
				//cout << "2 p : " << Two.path << " idx : " << Two.idx << "\n";
				//cout << path[Two.path][Two.idx] << " ";
				
			}
			else if (nowMal == 3) {
				if (Three.arrival)continue;
				visit[Three.path][Three.idx] = false; //���� 1������ ��ġ false -> �������� �̵��ؾ��ؼ�
				info newM = Go(Three, cango); //�������

				if (finish(newM.path, newM.idx, visit)) { //�ߺ��̸� ����
					jump = true;
					break;
				}

				Three = newM;

				if ((Three.path == 0 && Three.idx >= 21) || (Three.path == 4 && Three.idx >= 4)) {//������ ������ (������������ �湮üũ���� ����)
					//tot += path[Three.path][Three.idx];
					continue;
				}

				visit[Three.path][Three.idx] = true; //������ �湮üũ
				tot += path[Three.path][Three.idx];

				//cout << "3 p : " << Three.path << " idx : " << Three.idx << "\n";
				//cout << path[Three.path][Three.idx] << " ";
			
			}
			else if (nowMal == 4) {
				if (Four.arrival)continue;
				visit[Four.path][Four.idx] = false; //���� 1������ ��ġ false -> �������� �̵��ؾ��ؼ�
				info newM = Go(Four, cango); //�������

				if (finish(newM.path, newM.idx, visit)) { //�ߺ��̸� ����
					jump = true;
					break;
				}

				Four = newM;

				if ((Four.path == 0 && Four.idx >= 21) || (Four.path == 4 && Four.idx >= 4)) {//������ ������ (������������ �湮üũ���� ����)
					//tot += path[Four.path][Four.idx];
					continue;
				}

				visit[Four.path][Four.idx] = true; //������ �湮üũ
				tot += path[Four.path][Four.idx];

				//cout << "2 p : " << Two.path << " idx : " << Two.idx << "\n";
				//cout << path[Two.path][Two.idx] << " ";
			}
			/*
			cout << "\n";
			cout << "�湮üũ\n";
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 21; j++) {
					cout << visit[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";
			cout << "\n";*/
		}
		
		
		if (MMax < tot) MMax = tot;
	}

}