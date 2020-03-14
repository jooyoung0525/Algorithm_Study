#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

vector<int>Graph[1010];

int N, M, V;
bool visit[1010];

void DFS(int start);
void BFS(int start);

int main()
{
	cin >> N >> M >> V;
	
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}
	
	for (int i = 1; i <= N; i++)
	{
		sort(Graph[i].begin(), Graph[i].end());
	}

	DFS(V);
	cout << endl;
	memset(visit, false, sizeof(visit));
	BFS(V);

	return 0;
}


void DFS(int start)
{
	visit[start] = true;
	cout << start << " ";

	for (int i = 0; i < Graph[start].size(); i++)
	{
		int next = Graph[start][i];
		if (!visit[next])
		{
			DFS(next);
		}
	}


}

void BFS(int start)
{
	queue<int>Q;
	visit[start] = true;
	Q.push(start);

	while (!Q.empty())
	{
		int cur = Q.front();
		cout << cur << " ";
		Q.pop();

		for (int i = 0; i < Graph[cur].size(); i++)
		{
			int next = Graph[cur][i];
			if (!visit[next])
			{
				Q.push(next);
				visit[next] = true;
			}
		}
	}
	cout << endl;
}
