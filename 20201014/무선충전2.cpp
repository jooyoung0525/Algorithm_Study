//조건을 최대한 세부적으로 나누지말고 뭉뚱그려서 생각해보기!

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
	// 사람A 이동방향
	for (int i = 1; i <= M; i++) {
		cin >> Move[1][i];
	}
	// 사람B 이동방향
	for (int i = 1; i <= M; i++) {
		cin >> Move[2][i];
	}

	// AP정보 입력
	for (int i = 0; i < A; i++) {
		int x, y, c, p;
		cin >> y >> x >> c >> p;
		AP.push_back({ x,y,c,p });
	}
}

void play() {

	Moveinfo startA = { 1,1 };
	Moveinfo startB = { 10,10 };

	//0초부터 충전가능
	for (int i = 0; i <= M; i++) {

		//cout << "i : " << i << "\n";
		vector<info>A; vector<info>B; //사람 A,B이동할 때,충전가능한 AP저장.

		//사람A
		int dirA = Move[1][i];
		int anx = startA.x + dx[dirA];
		int any = startA.y + dy[dirA];
		startA = { anx,any };

		//사람B
		int dirB = Move[2][i];
		int bnx = startB.x + dx[dirB];
		int bny = startB.y + dy[dirB];
		startB = { bnx,bny };
	
		//cout << "다음위치\n";
		//cout << anx << " " << any << " " << bnx << " " << bny << "\n";

		//저장가능한 AP정보 
		A = findAP(startA);
		B = findAP(startB);
		//cout << A.size() << " " << B.size() << "\n";

		//A,B모든조합 최대
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

		if (abs(a.x - apx) + abs(a.y - apy) > apc) continue; //사람위치가 ap의 거리안에 있음
		ap.push_back({ i,app });//AP의아이디, 값
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