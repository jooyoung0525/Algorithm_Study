//프림 알고리즘 -> 정점을 중심
//to,from,weight가 있을 때, 벡터로 트리를 생성(무방향)
// 어떤 정점을 기준으로 시작하는데 그 정점과 연결된 모든 간선을 우선순위 큐 통에 넣는다
// 방문하지 않고 그 정점과 연결된 가장 작은 간선을 선택한다. -> 방문체크를 한다.
// 선택된 간선은 우선순위 큐통에 넣는다. 계속반복한다.




#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct info {
	int from, weight;
	bool operator < (const info& a)const
	{
		return weight > a.weight;
	}
};

priority_queue<info>Q;
vector<info>Computer[1100];



int N, M;
int mincost;
bool visit[1100];
void Prim(int nowspot);

int main() {

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;

		Computer[from].push_back({ to,weight });
		Computer[to].push_back({ from,weight }); // 무방향 그래프
	}

	Prim(1);

	cout << mincost;
	return 0;
}

void Prim(int nowspot)
{
	visit[nowspot] = true;

	for (int i = 0; i < Computer[nowspot].size(); i++) {
		int next = Computer[nowspot][i].from;//nowspot에 연결된 정점
		int nextWeight = Computer[nowspot][i].weight;

		Q.push({ next, nextWeight });
	}

	while (!Q.empty()) {
		int now = Q.top().from;
		int nowW = Q.top().weight;

		Q.pop();


		if (!visit[now]) {
			visit[now] = true;
			mincost += nowW;

			for (int i = 0; i < Computer[now].size(); i++) {
				int next = Computer[now][i].from;
				int nextW = Computer[now][i].weight;

				if (!visit[next]) {
					Q.push({ next,nextW });
				}
			}
		}
	}
}
