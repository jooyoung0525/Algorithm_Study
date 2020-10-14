//������ �ִ��� ���������� ���������� ���ױ׷��� �����غ���!

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

struct Moveinfo { int x, y; };
struct APinfo { int x, y, c, p; };
struct info { int num, val; };

vector<APinfo>AP;
int Move[3][110];
int Charge[110];
int M, A;
int dx[] = { 0,-1,0,1,0 };
int dy[] = { 0,0,1,0,-1};

bool cmp(info A, info B) {
	return A.val > B.val;
}
void solution();
void initialize();
void Input();
void play();
vector<info> findAP(Moveinfo a);
int printAns();
int findMax(vector<info>a, vector<info>b);


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	/*
	vector<info>V;
	V.push_back({ 1,10 });
	V.push_back({ 2,5 });
	V.push_back({ 10,100 });
	V.push_back({ 5,1 });
	sort(V.begin(), V.end(), cmp);
	for (int i = 0; i < V.size(); i++) {
		cout<<V[i].val << " ";
	}*/
	solution();

	return 0;
}


void solution() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		initialize();
		Input();
		play();
		int result = printAns();
		cout << "#" << tc << " " << result << "\n";
	}
}

void initialize() {

	AP.clear();
	memset(Move, 0, sizeof(Move));
	memset(Charge, 0, sizeof(Charge));
	M = 0, A = 0;
}

void Input() {

	cin >> M >> A;
	// ���A �̵�����
	for (int i = 1; i <= M; i++) {
		cin >> Move[1][i];
	}
	// ���B �̵�����
	for (int i = 1; i <= M; i++) {
		cin >> Move[2][i];
	}

	// AP���� �Է�
	for (int i = 0; i < A; i++) {
		int x, y, c, p;
		cin >> y >> x >> c >> p;
		AP.push_back({ x,y,c,p });
	}
}

void play() {

	Moveinfo startA = { 1,1 };
	Moveinfo startB = { 10,10 };

	//0�ʺ��� ��������
	for (int i = 0; i <= M; i++) {

		//cout << "i : " << i << "\n";
		vector<info>A; vector<info>B; //��� A,B�̵��� ��,���������� AP����.

		//���A
		int dirA = Move[1][i];
		int anx = startA.x + dx[dirA];
		int any = startA.y + dy[dirA];
		startA = { anx,any };

		//���B
		int dirB = Move[2][i];
		int bnx = startB.x + dx[dirB];
		int bny = startB.y + dy[dirB];
		startB = { bnx,bny };
	
		//cout << "������ġ\n";
		//cout << anx << " " << any << " " << bnx << " " << bny << "\n";

		//���尡���� AP���� 
		A = findAP(startA);
		B = findAP(startB);
		//cout << A.size() << " " << B.size() << "\n";

		//A,B������� �ִ�
		if (A.size() == 0 && B.size() > 0) {
			sort(B.begin(), B.end(), cmp);
			Charge[i] = B[0].val;
		}
		else if (A.size() > 0 && B.size() == 0) {
			sort(A.begin(), A.end(), cmp);
			Charge[i] = A[0].val;
		}
		else if (A.size() > 0 && B.size() > 0) {
			Charge[i] = findMax(A, B);
		}
	}

}


vector<info> findAP(Moveinfo a) {
	
	vector<info>ap;

	for (int i = 0; i < AP.size(); i++) {
		int apx = AP[i].x;
		int apy = AP[i].y;
		int apc = AP[i].c;
		int app = AP[i].p;

		if (abs(a.x - apx) + abs(a.y - apy) > apc) continue; //�����ġ�� ap�� �Ÿ��ȿ� ����
		ap.push_back({ i,app });//AP�Ǿ��̵�, ��
	}

	return ap;
}

int printAns()
{
	/*
	cout << "A\n";
	for (int i = 0; i <= M; i++) {
		cout << Charge[1][i] << " ";
	}
	cout << "\n";

	cout << "B\n";
	for (int i = 0; i <= M; i++) {
		cout << Charge[2][i] << " ";
	}
	cout << "\n";*/

	int cnt = 0;
	for (int i = 0; i <= M; i++) {
		cnt += Charge[i];
		//cnt += Charge[2][i];
	}
	
	return cnt;
}


int findMax(vector<info>a, vector<info>b) {
	int mmax = 0;
	
	for (int i = 0; i < a.size(); i++) {
		

		for (int j = 0; j < b.size(); j++) {
			int tot;
			if (a[i].num == b[j].num) {
				tot = a[i].val;
				mmax = max(mmax, tot);
			}
			else {
				tot = a[i].val + b[j].val;
				mmax = max(mmax, tot);
			}
		}
	}

	return mmax;
}