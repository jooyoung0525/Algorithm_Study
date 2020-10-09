//16:00~17:11

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct info { int x, y; };
int N, M, K;
int Map[15][15] = {5,};
int plusFood[15][15];
int totalSurvive = 0;
bool flag = false;

vector<pair<info,int>>survive;
vector<pair<info,int>>Die; //�������� ����
vector<info>spread;  //���ĳ��� ����

void Input();

void spring();
void summer();
void fall();
void winter();

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	Input();
	
	for(int i = 0; i<K; i++){ //K�ð����� ����Ű��
		
		Die.clear();
		spread.clear();
		
		spring();
		summer();
		fall();
		winter();
	}
	
	cout << survive.size();
	
	return 0;
}

void Input() {

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> plusFood[i][j];
		}
	}

	fill(&Map[0][0], &Map[14][14], 5);

	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		survive.push_back({ {x,y},z });
	}
	/*
	cout << "\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}
	*/
}



void spring() {

	vector<int>Array[15][15]; //������ ���� ����.
//	bool visit[15][15] = {false};//5�� ����� ������ ���� �ڸ��� ������ ���� �� �����Ƿ� �ɷ��ַ���

	
	//���� �ʿ� ���� ���� ����
	for (int i =0; i < survive.size(); i++) {
	
		int cx = survive[i].first.x;
		int cy = survive[i].first.y;
		int age = survive[i].second;

		Array[cx][cy].push_back(age);
	}
	survive.clear();

	//���� �迭 ���鼭, �� ���� ���� ������ ���� ���� ���, sort(��������)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (Array[i][j].size() == 1 || Array[i][j].empty())continue;
			sort(Array[i][j].begin(), Array[i][j].end());
		}
	}
	
	//������ ��� �Ա�
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			
			if (Array[i][j].empty())continue; //��ĭ �ǳʶ�

			for (int k = 0; k < Array[i][j].size(); k++) { 

				int nowage = Array[i][j][k];

				if (nowage <= Map[i][j]) { //��и��� �� ����
					
					int nextage = nowage + 1;
					survive.push_back({ {i,j}, nextage }); //��������� ����ִ� ���Ϳ� �־���.
					
					Map[i][j] -= nowage;

					if (nextage % 5 == 0) { 
						spread.push_back({ i,j });
					}
				}

				else { //��� ���� �� ����
					Die.push_back({ {i,j},nowage });
				}
			}
		}
	}
}

void summer() {

	if (Die.empty())return;

	for (int i = 0; i < Die.size(); i++) {
		int cx = Die[i].first.x;
		int cy = Die[i].first.y;
		int age = Die[i].second;

		Map[cx][cy] += age / 2;
	}
}

void fall() {

	if (spread.empty())return;
	
	int dx[] = { -1,-1,-1,0,0,1,1,1};
	int dy[] = { -1,0,1,-1,1,-1,0,1 };
	
	for (int i = 0; i < spread.size(); i++) {
		
		int cx = spread[i].x;
		int cy = spread[i].y;

		for (int j = 0; j < 8; j++) {

			int nx = cx + dx[j];
			int ny = cy + dy[j];

			if (nx<=0 || ny<=0 || nx>N || ny>N )continue;
			survive.push_back({ { nx,ny }, 1 });
		}
	}
}


void winter() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Map[i][j] += plusFood[i][j];
		}
	}
}

