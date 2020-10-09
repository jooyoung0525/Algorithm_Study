/*
1. �����ġ ã��
2. �� ������ �ִ� ����� �ֳ� ã��
  1) ���� ũ��ũ�� -1 (��������) ������
  2) BFS�� �Ÿ����
   (ã���鼭 ���� �����ġ���� �Ÿ����) -> ������ ������ �켱����ť�� ���� (�Ÿ���������,x������,y������)
3. ť�� ���� �տ� ����� �԰� �����ġ�� ���� ������, ������������ ���ũ�� ���� , �ð��� �� �� �Ÿ��ϱ� �Ÿ�����
4. 2��,3�� �ݺ�
5. ���� �켱���� ť���� ���������� ���� ũ�Ⱑ ũ�ų�, ť�� ������� ����


*/

#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

struct Shark { int x, y, size, eat; }; //x,y,ũ��,�����ǰŸ���

struct Fish { int x, y, size,dist; 
	bool operator < (const Fish a) const {
		if (dist == a.dist) {
			if (x == a.x) {
				return y > a.y;
			}
			return x > a.x;
		}
		return dist > a.dist;
	}
}; //x,y,ũ��,�����ǰŸ���

int N;
int Time = 0;
int CanEatFish = 0;
int Sea[25][25];
Shark shark;
priority_queue<Fish>fish;

void Find_fish();
void Eat();
void initQ();

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//1.�Է°� �����ġã��
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Sea[i][j];
			if (Sea[i][j] == 9) {
				Sea[i][j] = 0; //0���� �������.
				shark = { i,j,2,0 };
			}
		}
	}
	
	//2.����� �ʱⰪ����
	Find_fish();

	
	while (!fish.empty()) {
		
		//1. ���� �� �ִ� ����� �Ա� (�������±浵 �˻�)
		Eat();

		//2. ť�ʱ�ȭ �ϰ� �ٽ� ���� �� �ִ� ����� ��������
		initQ();
		Find_fish();
	}

	cout << Time;

	return 0;
}


void Find_fish() 
{
	int cpy[25][25];
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };
	memset(cpy, -1,sizeof(cpy));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Sea[i][j] > 0 && Sea[i][j]<7) {
				if (Sea[i][j] > shark.size) //���� ũ�� ��������
				{
					cpy[i][j] = -2;
				}
			}
		}
	}

	queue<pair<int, int>>Q;
	Q.push({ shark.x,shark.y });
	cpy[shark.x][shark.y] = 0; //��� �Ÿ� 0

	while (!Q.empty()) {
		int cx = Q.front().first;
		int cy = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
			if (cpy[nx][ny] == -1) {
				cpy[nx][ny] = cpy[cx][cy] + 1;
				Q.push({ nx,ny });
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Sea[i][j] > 0 && Sea[i][j] < 7) {
				if (Sea[i][j] < shark.size && cpy[i][j]>0) { //�� ������ �ִ� ��(���� �۰�, �� ������ �� �ִ� ��)
					fish.push({ i,j,Sea[i][j],cpy[i][j]});
				}
			}
		}
	}	
}


void Eat() {

	int closefishX = fish.top().x;
	int closefishY = fish.top().y;
	int eattime = fish.top().dist;
	
	//�����ð� (=�� ����⿡ �����ѽð�)
	Time += eattime;

	//���� ������� ��ġ ����
	shark.x = closefishX; 
	shark.y = closefishY;
	Sea[closefishX][closefishY] = 0;

	//�� ���� ������
	shark.eat++;
	if (shark.eat == shark.size) {
		shark.eat = 0;
		shark.size++;
	}
}

void initQ()
{ 
	while (!fish.empty()) {
		fish.pop();
	}
}
