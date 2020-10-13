//11:21~13:37 (2시간 15분)


#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

struct info { int id, time, recep;
bool operator <(const info a) const{
	if (time == a.time) {
		return recep > a.recep;
	}
	return time > a.time;
}
};

vector<pair<int,bool>>people; //고객정보
vector<pair<int, bool>>Recep[25]; //접수창구
vector<pair<int, bool>>Repair[25]; //정비창구
queue<int>Wait1; //대기1
priority_queue<info>Wait2; //대기2

int recep[25]; //접수창구 시간 (1부터~)
int receptime[25]; //접수창구 시간계산
int repair[25];//정비창구 시간 (1부터~)
int repairtime[25];//정비창구 시간계산
int N, M, K, A, B, T;
int All = 0;
bool visit[1010];

void solve();
void initialize();
void Input();
void Play();
void findPeople(int t);
void playRecep(int t);
void playRepair();
bool CanRepair(int id);
int findanswer();

//void debug();

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//debug();
	solve();

	return 0;
}

void debug() {
	priority_queue<info>Q;
	Q.push({ 1,3,2 }); //고객 시간 창구번호
	Q.push({ 3,3,1 }); 
	Q.push({ 5,1,1 }); 

	//5,3,1

	int idx = 0;
	while (!Q.empty()) {
		cout <<idx<<" "<< Q.top().id << " " << Q.top().time << " " << Q.top().recep << "\n";
		idx++;
		Q.pop();
	}
}

void solve() {

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
	
		initialize();
		Input();
		Play();
		int ans = findanswer();
		if (ans == 0) ans = -1;
		cout << '#' << tc << ' ' << ans << "\n";
	}
}

void initialize() {
	
	All = 0, N = 0, M = 0, K = 0, A = 0, B = 0;
	people.clear();
	for (int i = 0; i < 25; i++) {
		Recep[i].clear();
		Repair[i].clear();
	}

	while (!Wait1.empty()) {
		Wait1.pop();
	}

	while (!Wait2.empty()) {
		Wait2.pop();
	}

	memset(recep, 0, sizeof(recep));
	memset(repair, 0, sizeof(repair));
	memset(receptime, 0, sizeof(receptime));
	memset(repairtime, 0, sizeof(repairtime));

}

void Input() {

	cin >> N >> M >> K >> A >> B;
	for (int i = 1; i <= N; i++) {
		cin >> recep[i];
	}
	for (int i = 1; i <= M; i++) {
		cin >> repair[i];
	}
	for (int i = 0; i < K; i++) {
		int a;
		cin >> a;
		people.push_back({ a,false });
	}
	All = K;
}


void Play() {

	int t = 0;

	while (1) {
		//cout << "시간 : " << t << "\n";
		if (All == 0)break;
		findPeople(t); //t시간에 맞는 고객 대기1에
		playRecep(t);
		playRepair();

		t++;
	}
	/*
	cout << "접수" << "\n";
	for (int i = 1; i <= N; i++) {
		cout << i << " : i -> ";
		for (int j = 0; j < Recep[i].size(); j++) {
			cout << Recep[i][j].first << " ";
		}
		cout << "\n";
	}

	cout << "정비" << "\n";
	for (int i = 1; i <= M; i++) {
		cout << i << " : i -> ";
		for (int j = 0; j < Repair[i].size(); j++) {
			cout << Repair[i][j].first << " ";
		}
		cout << "\n";
	}*/

}

void findPeople(int t) {

	for (int i = 0; i < people.size(); i++) {
		int arrivetime = people[i].first;
		int can = people[i].second;

		if (arrivetime == t && !can) {
			people[i].second = true; //이미 방문한 고객체크
			Wait1.push(i+1); //고객아이디저장
		}
	}
	return;
}


void playRecep(int t) {

	for (int i = 1; i <= N; i++) {
		
		if (receptime[i] == 0) { //사람배치
			int last = Recep[i].size() - 1;
			if (!Recep[i].empty() && !Recep[i][last].second ) { //마지막 접수창구사람이, 대기2에 간적 없으면 대기2로
				Recep[i][last].second = true;
				if (!CanRepair( Recep[i][last].first)) {
					Wait2.push({ Recep[i][last].first,t,i });
				}
			}
			if (!Wait1.empty()) {
				int person = Wait1.front();
				Wait1.pop();
				receptime[i] = recep[i] - 1; //시간갱신
				Recep[i].push_back({ person,false }); //접수창구 벡터에 사람배치
			}
		}
		else {
			if(receptime[i] > 0) //접수창구 몇초흐르는지 세기
				receptime[i]--;
		}
	}

}


void playRepair() {
	
	for (int i = 1; i <= M; i++) {
		
		if (repairtime[i] == 0){

			int last = Repair[i].size() - 1;
			if (!Repair[i].empty() && !Repair[i][last].second) { //마지막 정비창구사람 설문조사
				Repair[i][last].second = true;
				All--;
			}
			if (!Wait2.empty()) { //정비대기에 사람 있음
				int person = Wait2.top().id;
				Wait2.pop();
				Repair[i].push_back({ person,false });
				repairtime[i] = repair[i] - 1;
			}
		
		}
		else {
			if(repairtime[i]>0){
				repairtime[i]--;
			}
		}
	
	}
}


bool CanRepair(int id) { //접수가 0이면 빈 정비창구 있는지 확인

	for (int i = 1; i <= M; i++) {
		if (repairtime[i] == 0 && Wait2.empty()) {
			int last = Repair[i].size() - 1;
			if (!Repair[i].empty()&& !Repair[i][last].second ) {
				Repair[i][last].second = true;
				All--;
			}
			Repair[i].push_back({ id,false });//정비창구에 빈자리 있으면 바로 해당사람 정비창구 배치
			repairtime[i] = repair[i];
			return true;
		}
	}
	return false; //정비창구에 빈자리 없으면 대기2에 보내야함
}


int findanswer() {

	int tot = 0;
	for (int i = 0; i < Recep[A].size(); i++) {
		int stand = Recep[A][i].first;
		for (int j = 0; j < Repair[B].size(); j++) {
			if (stand == Repair[B][j].first) tot += stand;
		}
	}

	return tot;
}
