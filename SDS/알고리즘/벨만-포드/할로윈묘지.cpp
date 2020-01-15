//인접리스트이용

#include<iostream>
#include<vector>

using namespace std;

#define INF 35*35*10000

struct info { int from, to, cost; };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<info>edge;


int map[35][35] = { 0 };
int hole[35][35] = { 0 }; //귀신구멍
int dist[35 * 35] = { 0 };
int W, H, G, E = 0;


int main()
{
	while(1)
	{
		
		//입력
		cin >> W >> H;
		if (W == 0 && H == 0)break;
		edge.clear();

		//각 배열 초기화
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				map[i][j] = i*W + j; //map칸에 정점을 할당
				hole[i][j] = 0;//귀신구멍 초기화
				dist[map[i][j]] = INF; //????????????????
			}
		}

		//묘비 위치
		cin >> G;
		for (int i = 0; i < G; i++) //묘비의 위치
		{
			int a = 0, b = 0;
			cin >> a >> b;
			map[b][a] = -1; //열->행 순으로 입력받음
		}

		//귀신구멍 위치 (귀신구멍으로 갈 수 있는 간선)
		cin >> E;
		for (int i = 0; i < E; i++)
		{
			int x1, y1, x2, y2, t = 0;
			cin >> x1 >> y1 >> x2 >> y2 >> t;
			hole[y1][x1] = 1;
			edge.push_back({ map[y1][x1],map[y2][x2], t });// 시작점, 도착점, 비용 vector에 저장해서 인접리스트 생성. (갈수있는 경로들 저장)
														   //예제 -> 11번에서 귀신구멍을 통해 2로가는 경우.
		}
		

		//간선정보 저장 (상하좌우)
		for (int i = 0; i < H; i++) //모든 map의 칸을 방문하며 이동할 수 있는 간선을 edge에 저장
		{
			for (int j = 0; j < W; j++)
			{
				if (map[i][j] == -1 || hole[i][j] == 1) continue;//맵의 위치가 묘비이거나 귀신구멍이면 건너뜀
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 0 || ny < 0 || nx >= H || ny >= W || map[nx][ny] == -1)continue; //다음위치가 범위를 벗어나거나, 묘비이면 건너뜀
					edge.push_back({ map[i][j],map[nx][ny],1 }); //귀신구멍 가중치 t이외의, 모든 경로의 가중치는 1로둠
				}
			}
		}

		//벨만-포드알고리즘
		dist[0] = 0;
		int update = 1; 
		for (int v = 0; v < W * H - G -1 && update == 1; v++) //  루프를 V-1번반복->여기서는 W*H-G-1반복
		{
			update = 0;
			for (info e : edge) //벡터 edge의 모든 간선을 돈다
			{
				if (dist[e.from] == INF)continue;
				if (e.from == W*H - 1)continue;
				if (dist[e.to] > dist[e.from] + e.cost)
				{
					update = 1;
					dist[e.to] = dist[e.from] + e.cost;
				}
			}
		}

		update = 0;
		for (info e : edge) //V번째루프에서 값이 갱신되었으면 음수사이클 가지고있는것
		{
			if (dist[e.from] == INF)continue;
			if (e.from == W*H - 1)continue;
			if (dist[e.to] > dist[e.from] + e.cost)
			{
				update = 1;
				break;
			}
		}

		if (update == 1) cout << "Never\n";
		else if (dist[H*W - 1] == INF)cout << "Impossible\n";
		else cout << dist[H*W - 1] << "\n";
	}

	return 0; 
}
