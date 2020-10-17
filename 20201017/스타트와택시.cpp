//1:17�мҿ�

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct taxi { int id, x, y, fuel; }; //�¿�°� ���̵� �ý� ��ġ�� ��������
struct person { int sx, sy, ex, ey, dist; bool die; }; //�� �°��� ����, �������� ,�ýÿ��� �°����� �Ÿ�
struct fastperson { int id, x, y, dist; };

bool stop = false;
int N, M;
int Map[25][25];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<person>P;
taxi T;

bool cmp(fastperson a, fastperson b) {
	if (a.dist == b.dist) {
		if (a.x == b.x) {
			return a.y < b.y;
		}
		return a.x < b.x;
	}
	return a.dist < b.dist;
}
void solution();
void Input();
void Find();
void Drive();
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
	
	while (1) {
	
		Find(); //�ý���ġ���� BFS
		if (stop)break;
		Drive(); //�°���ġ���� BFS
		if (stop || finish())break;

	}

	if (stop)cout << -1;
	else cout << T.fuel;

}


void Input() {

	cin >> N >> M >> T.fuel; //��ũ��, �°���, �ʱ⿬��
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Map[i][j]; // �� �Է�
		}
	}
	
	cin >> T.x >> T.y; //�ý� �ʱ���ġ
	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		P.push_back({ a,b,c,d,false});
	}

	T.id = -1;
}


void Find() {

	struct info { int x, y; };
	queue<info>Q;
	int visit[25][25] = { 0 }; //�Ÿ�����
	//�ýð� 0�̹Ƿ� �迭 -1�� �ʱ�ȭ
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			visit[i][j] = -1;
		}
	}

	Q.push({ T.x,T.y});
	visit[T.x][T.y] = 0;

	while (!Q.empty()) {
	
		int cx = Q.front().x;
		int cy = Q.front().y;
		Q.pop();

		for (int i = 0; i < 4; i++) {
		
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx<1 || ny<1 || nx>N || ny>N || visit[nx][ny] > -1 ||Map[nx][ny]==1)continue; 
			visit[nx][ny] = visit[cx][cy] + 1;
			Q.push({ nx,ny });
		}
	}

	/*
	cout << "�����1\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << visit[i][j] << "   ";
		}
		cout << "\n";
	}
	cout << "\n";*/
	

	vector<fastperson>FP; //�°����̵�, ������ġ, �ýÿ��� �Ÿ�

	for (int i = 0; i < M; i++) {
		if (P[i].die)continue; //�ѹ� ������ �°� ����
		int cx = P[i].sx;
		int cy = P[i].sy;
		int cdist = visit[cx][cy];
		if (cdist == -1)continue;
		FP.push_back({ i,cx,cy,cdist });
	}

	if (FP.size() > 1)
		sort(FP.begin(), FP.end(), cmp);

	if (FP.empty()) {
		stop = true;
		return;
	}
	//�ýð� �¿췯�� �մ�
	int id = FP[0].id;
	//cout << "�ý� ���� : " << T.fuel << "\n";
	T.fuel -= FP[0].dist; //�ýð� �մ��¿췯���鼭 ���� ����
	if (T.fuel < 0) {
		stop = true;
		return;
	}
	//cout << "�ý�~�մ� : " << T.fuel << "\n";
	T.x = FP[0].x; T.y = FP[0].y; //�ý����� ����
	T.id = id;
}
 
void Drive() {

	struct info { int x, y; };
	queue<info>Q;
	int visit[25][25] = { 0 }; //�Ÿ�����
	//�ýð� 0�̹Ƿ� �迭 -1�� �ʱ�ȭ
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			visit[i][j] = -1;
		}
	}

	Q.push({ T.x,T.y }); //�°��¿� �ý���ġ
	visit[T.x][T.y] = 0;

	while (!Q.empty()) {

		int cx = Q.front().x;
		int cy = Q.front().y;
		Q.pop();

		for (int i = 0; i < 4; i++) {

			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx<1 || ny<1 || nx>N || ny>N || visit[nx][ny] > -1 || Map[nx][ny] == 1)continue;
			visit[nx][ny] = visit[cx][cy] + 1;
			Q.push({ nx,ny });
		}
	}

	/*
	cout << "�����2\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << visit[i][j] << "   ";
		}
		cout << "\n";
	}
	cout << "\n";
	*/

	//���� �ý�Ÿ���ִ� �°� ����
	int nowperson = T.id;
	int endx = P[nowperson].ex;
	int endy = P[nowperson].ey;
	P[nowperson].die = true; //�°� ����
	T.x = endx;
	T.y = endy;

	//������������ �ּҰŸ�
	int arrivedist = visit[endx][endy];
	if (arrivedist == -1) {
		stop = true;
		return;
	}
	T.fuel -= arrivedist;
	if (T.fuel < 0) {
		stop = true;
		return;
	}
	T.fuel += (arrivedist * 2);
	//cout << "��� ~ ���� : " << T.fuel<<"\n";
}


bool finish() {

	for (int i = 0; i < M; i++) {
		if (!P[i].die)return false;
	}
	return true;

}