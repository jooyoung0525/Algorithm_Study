#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct info {
	int from, to, cost;
	bool operator<(const info& a)const
	{
		return cost < a.cost;
	};
};

struct info2 { int x, y, inum; };
int N, M;
int initm[15][15];
int map[15][15];
bool check[15][15];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int PParent[10];
int height[10];

vector<info2>island;
vector<info>Kruscal;

void finddiff(int cx, int cy, int inum, int dir);
void DFS(int x, int y, int cnt);
int find(int a);
void merge(int a, int b);


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> initm[i][j];
		}
	}

	//다리번호매김 및 정보저장
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0 && initm[i][j] == 1) {
				cnt++;
				map[i][j] = cnt;
				island.push_back({ i,j,cnt });
				DFS(i, j, cnt);
			}
		}
	}

	//정점의 갯수
	int islandN = cnt;

	// 다른 섬과의 연결선 및 비용찾기
	for (int i = 0; i < island.size(); i++)
	{
		int cx = island[i].x;
		int cy = island[i].y;
		int cn = island[i].inum;

		for (int j = 0; j < 4; j++)
		{
			//다른섬을 만날때까지 다리길이 계산
			finddiff(cx, cy, cn, j);
		}
	}

	//작은순으로 정렬(최소비용을 구하기 위해)
	sort(Kruscal.begin(), Kruscal.end());

	//배열초기화(Union-find)
	for (int i = 1; i <= islandN; i++)
	{
		PParent[i] = i;
	}

	int result = 0;
	for (int i = 0; i < Kruscal.size(); i++)
	{
		// from과 to의 부모노드가 같지않으면 연결안되있으므로
		if (find(Kruscal[i].from) == find(Kruscal[i].to)) continue;

		//정답에 최솟값을 더해주고
		result += Kruscal[i].cost;

		//from과 to를 묶어준다
		merge(Kruscal[i].from, Kruscal[i].to);
	}

	//1~정점개수 까지 부모노드가 같은지 조사해준다 (기존의 크루스칼은 모든 연결된정점을 여러개주는데
	                                                //이 문제는 모든 정점이 연결되어있는지 모름 --> 다시확인해줘야함
	int all = find(1);

	for (int i = 2; i <= islandN; i++)
	{
		if (all != find(i))
			result = -1;
	}

	//정답 출력
	cout << result;
	return 0;
}

//Union-find 함수
int find(int a)
{
	if (PParent[a] == a)return a;
	return PParent[a] = find(PParent[a]);
}

void merge(int a, int b)
{
	int roota = find(a);
	int rootb = find(b);

	if (roota == rootb)return;

	//최적화 필요
	if (height[roota] > height[rootb]) 
		swap(roota, rootb);

	PParent[roota] = rootb;

	if (height[roota] == height[rootb])
		height[rootb]++;
}

//섬군집 넘버링
void DFS(int x, int y, int cnt)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
		if (map[nx][ny] == 0 && initm[nx][ny] == 1)
		{
			map[nx][ny] = cnt;
			island.push_back({ nx,ny,cnt });
			DFS(nx, ny, cnt);
		}
	}
}

//현재섬과 다른섬과의 거리계산
void finddiff(int cx, int cy, int inum, int dir)
{
	int count = 0; // 거리계산

	int from = -1; int to = -1; int connectnum = -1;
	int nx = cx + dx[dir]; int ny = cy + dy[dir];
	while (1)
	{
		if (nx < 0 || ny < 0 || nx >= N || ny >= M || map[nx][ny] == inum)break; //범위넘고, 같은섬일경우 멈춤
		if (map[nx][ny] == 0) count++; //바다이면 거리++
		if (map[nx][ny] != inum && map[nx][ny] > 0 )//다른섬이면
		{
			from = inum; to = map[nx][ny]; //현재섬->다음섬
			connectnum = count; //거리 변수에 저장하고 멈춤
			break;
		}
		nx += dx[dir]; 
		ny += dy[dir];
	}

	if (connectnum >= 2) //거리가 2이상일 경우만 Kruscal벡터에 간선 정보저장
		Kruscal.push_back({ from,to,connectnum });

	return;
}
