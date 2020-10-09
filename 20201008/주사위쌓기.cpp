// 22:10 ~ 23:55 

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int, int>>firstCube; //1�� �ֻ��� ��,�Ʒ� �� ����.
vector<string>Num; // �ֻ��� ���� ���� string
int N;
int Cube[10005][6];
int MMax = -1;

void Calculate(); //1���ֻ��� �������� ����
string canNum(int up,int down); // �������� ���� ���ڸ� string����
void findNum(int idx, int stand); // 1���ֻ��� ���� N���ֻ������� ��,�Ʒ� ����
int search(int a); // a�� ¦�̵Ǵ� �ε����� ��ȯ
int findMax(string a); //vector�� ��Ƴ��� ����������, �� ������ �ִ��� ã�� ����

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		
		for (int j = 0; j < 6; j++) {
			cin>>Cube[i][j];
		}
	}
	
	//�ֻ��� 6���� idx�� 0~5��� ���� ��, {0,5} {1,3} {2,4}�� ¦���̷�
	firstCube.push_back({ Cube[0][0],Cube[0][5] });
	firstCube.push_back({ Cube[0][1],Cube[0][3] });
	firstCube.push_back({ Cube[0][2],Cube[0][4] });

	Calculate();

	cout << MMax << "\n";
	return 0;
}

void Calculate() {

	//1�� �ֻ��� ���� ������
	for (int i = 0; i < firstCube.size(); i++) { //3 1 6 5
	
		Num.clear(); //1�� �ֻ��� ������ �ٲ� ��� �������� ������ ���� �ʱ�ȭ �ؾ���.
		
		int up = firstCube[i].first; // 2
		int down = firstCube[i].second; //4

		string n = canNum(up, down); //�����̶� �Ʒ��� ���ڸ� canNum�� �ѱ�� ������ ���ڸ� string���� ��ȯ�ؼ� ����
		Num.push_back(n); //���������� ����
		
		//1���ֻ����� ���������� ���� �� �����Ƿ�, ���� �Ʒ��� �ٲ� �� ����.
		findNum(1, up); //2���ֻ�������, ���� ���� �Ѱ���.
		findNum(1, down);
	}

}

string canNum(int up, int down) { //������ ����ã���ռ�

	string s = "";
	for (int j = 1; j <= 6; j++) //1~6�߿� 
	{
		if (j == up || j == down)continue; //�Ű������� �Ѱܹ��� ���� �Ʒ� �� �����ϰ�
		s += (j + '0'); //��Ʈ������ ��ȯ ==> 1~6�� ���ڸ����̹Ƿ� ��Ʈ������ ��ȯ ����
	}

	return s;
}


void findNum(int idx, int stand) { //stand :����
	
	if (idx == N) {
		//�� ��Ʈ���� �ִ�
		int total = 0;

		int mmax = 0;
		for (int i = 0; i < Num.size(); i++) {
		//	cout << "i "<<Num[i] << "\n";
			mmax = findMax(Num[i]); //�ֻ��� ��� �׾��� ��, �� �ֻ����� ���������� findMax�� �ѱ�� findMax���� ������ �ִ���� ã����.
			total+=mmax; //�� ������ �ִ��� ��
		}

		MMax = max(MMax, total); 

		return;
	}


	int upidx = 0; int downidx = 0; //����� �Ʒ����� 

	for (int i = 0; i < 6; i++) {
		if (stand == Cube[idx][i]) { //���� �ֻ����� ����� ���� ���ڸ� ã���� ��, 
			downidx = i; //�ش� �ε����� �Ʒ��� (������ �� == ���� �Ʒ�)
			upidx = search(i); //�Ʒ���� ¦�̵Ǵ� ������ �ε��� ã��
			break;
		}
	}

	int upnum = Cube[idx][upidx]; //�� �ε����� ��ġ�� ��, �Ʒ����� ���ڵ� ã����.
	int downnum = Cube[idx][downidx];

	string nnum = canNum(downnum, upnum); //��, �Ʒ� ���� ������ ������ ���� ����
	Num.push_back(nnum); //���� ���Ϳ� ����
	
	findNum(idx + 1, upnum); //���� ������ ���ڿ� ���� �ֻ����� �Ѿ,

	Num.pop_back(); //���麤�Ϳ� ����Ȱ� ����
}


int search(int a) { //¦�� �´� �ε��� �� ã��
	if (a == 0)return 5;
	else if (a == 1)return 3;
	else if (a == 2)return 4;
	else if (a == 3)return 1;
	else if (a == 4)return 2;
	else if (a == 5)return 0;
}


int findMax(string a) { //������ ���� �� �ִ� ã��.

	int mmax = 0;
	for (int i = 0; i < a.length(); i++) {
		mmax = max(mmax, a[i] - '0');
	}
	return mmax;
}