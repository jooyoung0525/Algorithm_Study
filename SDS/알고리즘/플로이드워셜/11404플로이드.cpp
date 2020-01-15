#include<iostream>
#include<algorithm>

using namespace std;

#define INF 987654321

int dist[110][110];

int main()
{
	int N,M;
	cin >> N >>M; // N:정점 , M:간선

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			dist[i][j] = INF; // i -> j로가는 경로가 없을경우 무한대 값
			                  
		}
	}

	for (int i = 0; i < M; i++)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c); // 같은 경로에 다른가중치를 가진 간선이 여러개 일 경우, 최소값을 초기값으로 설정
	}


	for (int k = 1; k <= N; k++) // i->j로가는 경로중에 중간정점 k (i->j로바로 가는 경로가아니라 어떤 정점을 지날경우)
	{
		for (int i = 1; i <= N; i++) //출발점
		{
			for (int j = 1; j <= N; j++) //도착점
			{
				if (i == j)continue; //자기 자신의 정점은 경로가 없으므로 넘어간다!!! 
				                     //여기서 안넘어가면 만약 k==2일경우, dist[1][1], dist[1][2]+dist[2][1] 중 최솟값 계산됨.
				if (dist[i][j] > dist[i][k] + dist[k][j]) //i->j 로가는 경로중, i->k->j일 때, i->j경로와 i->k->j경로중 최솟값을 i->j경로의 비용으로 설정
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (dist[i][j] == INF) cout << "0 "; //경로의 값이 초기값과 같을경우, i->j경로가 없으므로 0출력
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}
