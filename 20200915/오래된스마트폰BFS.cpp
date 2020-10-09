/*
	1. ������ �ִ� ��ư���� ���ϴ� ������� �ִ��� üũ
	2. BFS�� �ʱⰪ �ְ� ����� �ø��鼭 ������ ��翬��
	   -> M-1�� ������ �ȵ�: '='��ư �����¼� ���� �� 
	   -> ���ϴ� ���� ť���� ������ ������ ���� set�� �־��ش�. (�ߺ�����)
	   -> ������ �� �� Oper�� true�ΰŸ� ����
	   -> ���� �� ��, /0���� �Ұ����ϰų� 0~999 ������ ������ �ǳʶ�.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

struct info { int cur, opernum; string ans; };

int T, N, O, M;
int WantNum;
bool Oper[5]; //  +:1  -:2  *:3  /:4 
vector<int>num;
vector<int>Allnum;
int Answer = -1;

void Make_num();
void Initall();
void BFS();
bool Check();

int main() {
	cin >> T;

	for (int q = 1; q <= T; q++) {

		Initall();

		cin >> N >> O >> M;
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			num.push_back(a);
		}

		for (int i = 0; i < O; i++) {
			int a;
			cin >> a;
			Oper[a] = true;
		}
		cin >> WantNum;

		if(!Check()){
			BFS();
		}

		cout << Answer << "\n";
	}


	return 0;
}


void Initall() {

	Answer = -1;
	N = O;
	M = 0;
	WantNum = 0;
	memset(Oper, false, sizeof(Oper));
	num.clear();
	Allnum.clear();
}

void Make_num() {

	//����+����...
	for (int i = 2; i <= num.size(); i++) {
		
	}

}

bool Check() {

	int checknum = 0;
	string WN = to_string(WantNum);
	

	for (int i = 0; i < WN.length(); i++) {
		int cmp = WN[i] - '0';

		for (int j = 0; j < num.size(); j++) {
			if (cmp == num[j])checknum++;
		}
	}

	if (WN.length() == checknum) {
		Answer=WN.length();
		return true;
	}

	return false;
}

void BFS() {
	queue<info>Q;

	Make_num();

	//queue�� �ʱⰪ
	for (int i = 0; i < num.size(); i++) {
		string a = to_string(num[i]);
		Q.push({ num[i],1 ,a});
	}


	while (!Q.empty()) {

		int curnum = Q.front().cur;
		int opernum = Q.front().opernum;
		string cstr = Q.front().ans;

		Q.pop();
		cout <<"cur : "<< curnum << " oper : " << opernum <<" string : "<<cstr<< "\n";

		if (opernum == M+1) break; // ������� �Ѿ�� ����
		if (curnum == WantNum && opernum <= M-1) {
			Answer = opernum + 1;
			return;
		}

		for (int j = 1; j < 4; j++) {

			if (Oper[j] == false)continue;
			
			if (j == 1) {
				for (int i = 0; i < num.size(); i++) {
					if (num[i] == 0)continue; //0�̸� ���꿡 ���ܽ�Ų��. 
					int next = curnum + num[i];

					if (next <= 999) {
						string nstr = cstr + "+";
						nstr += to_string(next);

						cout << next << "\n";
						Q.push({ next, opernum + 2,nstr });
					}
				}
			}
			else if (j == 2 && curnum > 0)//����
			{
				for (int i = 0; i < num.size(); i++) {
					if (num[i] == 0)continue; //0�̸� ���꿡 ���ܽ�Ų��. 
					int next = curnum - num[i];
					if (next >= 0) {
						
						string nstr = cstr + "-";
						nstr += to_string(next);

						cout << next << "\n";
						Q.push({ next,opernum + 2 });
					}
				}
			}
			else if (j == 3 && curnum > 0) //���ϱ�
			{
				for (int i = 0; i < num.size(); i++) {
					if (num[i] == 0)continue; //0�̸� ���꿡 ���ܽ�Ų��. 
					int next = curnum * num[i];
					if (next <= 999) {
						
						string nstr = cstr + "*";
						nstr+=to_string(next);
						
						cout << next << "\n";
						Q.push({ next, opernum + 2 });
					}
				}
			}
			else if (j == 4 && curnum > 0)//������
			{
				for (int i = 0; i < num.size(); i++) {
					if (num[i] == 0)continue; //0�̸� ���꿡 ���ܽ�Ų��. 
					int next = curnum / num[i];
					if (next >= 0) {
						
						string nstr = cstr + "/" + to_string(next);
						nstr += to_string(next);

						cout << next << "\n";
						Q.push({ next,opernum + 2 });
					}
				}
			}
		}
	}
	return;
}

