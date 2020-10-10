//���ǵ��� �� �����ؼ� ����ġ���ϱ�! ->if������..

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

struct info { int num, time, score; };
int T;
int N, M, Airport;
int alltime[40][40];
bool visit[40];
int MMax = 0;
vector<info>tourist;
vector<int>Hotel;
vector<int>maxpath;


void solve();
void IInit();
void IInput();
void DFS(int cur, int days, int spendTime, int satisfaction, int dept, vector<int>savePath);

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}


void solve() {

	cin >> T;
	for (int testcase = 1; testcase <= T; testcase++) {
	
		IInit();
		IInput();
		
		vector<int>path; //�� ����
		DFS(Airport, 1, 0, 0, 0, path);

		cout << "#" <<testcase << " " << MMax << " ";
		if (MMax != 0) {
			for (int i = 0; i < maxpath.size(); i++) {
				cout << maxpath[i] << " ";
			}
			cout << "\n";
		}
		else cout << "\n";
	}
}


void IInit() {
	
	N = 0, M = 0, Airport = 0, MMax =0;
	memset(alltime, 0, sizeof(alltime));
	memset(visit, false, sizeof(visit));
	tourist.clear();
	Hotel.clear();
	maxpath.clear();
}

void IInput() {

	cin >> N >> M;
	for (int i = 1; i < N; i++) { //1 ~ N-1
		for (int j = 1 + i; j <= N; j++) {
			int a;
			cin >> a;
			alltime[j][i] = a;
			alltime[i][j] = a;
		}
	}


	for (int i = 1; i <= N; i++) { //���� ���̵� �ο�
		char a;
		cin >> a;
		if (a == 'A') Airport = i;
		else if (a == 'P') {
			int b, c;
			cin >> b >> c;
			tourist.push_back({ i,b,c, }); //������ �Է�
		}
		else {
			Hotel.push_back(i); //ȣ���Է�
		}
	}
}

void DFS(int cur, int days, int spendTime, int satisfaction,int dept, vector<int>savePath) {
	//cout << "cur:  " << cur << "\n";

	if (cur == Airport && days == M && dept!=0) {
		if (MMax < satisfaction) {
		
			MMax = satisfaction;
			maxpath = savePath;
			//cout << MMax << "\n";
		}
		return;
	}

	bool canTour = false;

	//������ �湮
	for (int i = 0; i < tourist.size(); i++) {
	
		int next = tourist[i].num;
	//	cout << "next:  " << next << "\n";
		
		int t = tourist[i].time; //�ҿ�ð�
		int s = tourist[i].score;
		int nexttime = spendTime + t + alltime[cur][next];

		if (visit[next] == true || cur == next)continue;
		if (nexttime > 540)continue;

		visit[next] = true;
		savePath.push_back(next);
		canTour = true;
		DFS(next, days, nexttime, satisfaction+s, dept + 1, savePath);
		visit[next] = false;
		savePath.pop_back();
	}


	if (canTour == false) { //�湮������ �������� ������
		
		if (days == M) { //���������̸� ���װ�����.
			int nexttime = spendTime + alltime[cur][Airport];
			if (nexttime <= 540) {
				savePath.push_back(Airport);
				DFS(Airport, days, nexttime, satisfaction, dept + 1, savePath);
				savePath.pop_back();
			}
		}
		else {
			for (int i = 0; i < Hotel.size(); i++) { //ȣ�ڹ湮��������
				int curH = Hotel[i];

				if (spendTime + alltime[cur][curH] <= 540) { //ȣ�ڵ������� 9�ð� �����̸�
					savePath.push_back(curH);
					DFS(curH, days + 1, 0, satisfaction, dept+1, savePath); //ȣ�ڵ����ϸ� �������� ����.
					savePath.pop_back();
				}
			}
		}
	}
}

