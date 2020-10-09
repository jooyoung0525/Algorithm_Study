/*
1. 상어위치 찾기
2. 상어가 먹을수 있는 물고기 있나 찾기
  1) 상어보다 크기크면 -1 (못지나감) 지도에
  2) BFS로 거리계산
   (찾으면서 현재 상어위치와의 거리계산) -> 먹을수 있으면 우선순위큐에 담음 (거리차작은거,x작은거,y작은순)
3. 큐의 가장 앞에 물고기 먹고 상어위치와 먹은 마릿수, 물고기먹은수랑 상어크기 변경 , 시간은 상어가 간 거리니까 거리더함
4. 2번,3번 반복
5. 만약 우선순위 큐에서 먼저빠진게 상어보다 크기가 크거나, 큐가 비었으면 끝냄


*/

#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

struct Shark { int x, y, size, eat; }; //x,y,크기,상어와의거리차

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
}; //x,y,크기,상어와의거리차

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

	//1.입력과 상어위치찾기
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Sea[i][j];
			if (Sea[i][j] == 9) {
				Sea[i][j] = 0; //0으로 만들어줌.
				shark = { i,j,2,0 };
			}
		}
	}
	
	//2.물고기 초기값설정
	Find_fish();

	
	while (!fish.empty()) {
		
		//1. 먹을 수 있는 물고기 먹기 (지나가는길도 검사)
		Eat();

		//2. 큐초기화 하고 다시 먹을 수 있는 물고기 정보저장
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
				if (Sea[i][j] > shark.size) //상어보다 크면 못지나감
				{
					cpy[i][j] = -2;
				}
			}
		}
	}

	queue<pair<int, int>>Q;
	Q.push({ shark.x,shark.y });
	cpy[shark.x][shark.y] = 0; //상어 거리 0

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
				if (Sea[i][j] < shark.size && cpy[i][j]>0) { //상어가 먹을수 있는 애(상어보다 작고, 상어가 도달할 수 있는 애)
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
	
	//먹은시간 (=상어가 물고기에 도달한시간)
	Time += eattime;

	//상어와 물고기의 위치 갱신
	shark.x = closefishX; 
	shark.y = closefishY;
	Sea[closefishX][closefishY] = 0;

	//상어가 먹은 물고기수
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
