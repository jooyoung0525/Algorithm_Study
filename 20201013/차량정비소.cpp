//11:21~13:37 (2�ð� 15��)


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

vector<pair<int,bool>>people; //������
vector<pair<int, bool>>Recep[25]; //����â��
vector<pair<int, bool>>Repair[25]; //����â��
queue<int>Wait1; //���1
priority_queue<info>Wait2; //���2

int recep[25]; //����â�� �ð� (1����~)
int receptime[25]; //����â�� �ð����
int repair[25];//����â�� �ð� (1����~)
int repairtime[25];//����â�� �ð����
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
	Q.push({ 1,3,2 }); //�� �ð� â����ȣ
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
		//cout << "�ð� : " << t << "\n";
		if (All == 0)break;
		findPeople(t); //t�ð��� �´� �� ���1��
		playRecep(t);
		playRepair();

		t++;
	}
	/*
	cout << "����" << "\n";
	for (int i = 1; i <= N; i++) {
		cout << i << " : i -> ";
		for (int j = 0; j < Recep[i].size(); j++) {
			cout << Recep[i][j].first << " ";
		}
		cout << "\n";
	}

	cout << "����" << "\n";
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
			people[i].second = true; //�̹� �湮�� ��üũ
			Wait1.push(i+1); //�����̵�����
		}
	}
	return;
}


void playRecep(int t) {

	for (int i = 1; i <= N; i++) {
		
		if (receptime[i] == 0) { //�����ġ
			int last = Recep[i].size() - 1;
			if (!Recep[i].empty() && !Recep[i][last].second ) { //������ ����â�������, ���2�� ���� ������ ���2��
				Recep[i][last].second = true;
				if (!CanRepair( Recep[i][last].first)) {
					Wait2.push({ Recep[i][last].first,t,i });
				}
			}
			if (!Wait1.empty()) {
				int person = Wait1.front();
				Wait1.pop();
				receptime[i] = recep[i] - 1; //�ð�����
				Recep[i].push_back({ person,false }); //����â�� ���Ϳ� �����ġ
			}
		}
		else {
			if(receptime[i] > 0) //����â�� �����帣���� ����
				receptime[i]--;
		}
	}

}


void playRepair() {
	
	for (int i = 1; i <= M; i++) {
		
		if (repairtime[i] == 0){

			int last = Repair[i].size() - 1;
			if (!Repair[i].empty() && !Repair[i][last].second) { //������ ����â����� ��������
				Repair[i][last].second = true;
				All--;
			}
			if (!Wait2.empty()) { //�����⿡ ��� ����
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


bool CanRepair(int id) { //������ 0�̸� �� ����â�� �ִ��� Ȯ��

	for (int i = 1; i <= M; i++) {
		if (repairtime[i] == 0 && Wait2.empty()) {
			int last = Repair[i].size() - 1;
			if (!Repair[i].empty()&& !Repair[i][last].second ) {
				Repair[i][last].second = true;
				All--;
			}
			Repair[i].push_back({ id,false });//����â���� ���ڸ� ������ �ٷ� �ش��� ����â�� ��ġ
			repairtime[i] = repair[i];
			return true;
		}
	}
	return false; //����â���� ���ڸ� ������ ���2�� ��������
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
