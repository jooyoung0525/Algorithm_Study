#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int V, E;
vector<int>EDGE[100010];
int visit_order[100010];
bool Cutspot[100010];
int Count;

int DFS(int Now, bool Root);

int main()
{
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int A = 0, B = 0;
		cin >> A >> B;
		EDGE[A].push_back(B);
		EDGE[B].push_back(A);
	}

	for (int i = 1; i <= V; i++)
	{
		if (visit_order[i] == 0)
			DFS(i, true);
	}

	int spotnum = 0;
	for (int i = 1; i <= V; i++)
	{
		if (Cutspot[i] == true)
			spotnum++;
	}
	cout << spotnum << "\n";

	for (int i = 1; i <= V; i++)
	{
		if (Cutspot[i] == true) cout << i << " ";
	}

	return 0;
}

int DFS(int Now, bool Root)
{
	visit_order[Now] = ++Count;
	int ret = visit_order[Now];

	int child = 0;

	for (int i = 0; i < EDGE[Now].size(); i++)
	{
		int Next = EDGE[Now][i];

		if (visit_order[Next])
		{
			ret = min(ret, visit_order[Next]);
			continue;
		}

		child++;
		int Before = DFS(Next, false);

		if (Root == false && Before >= visit_order[Now]) //Before가 현재방문순서보다 커야하는이유
			Cutspot[Now] = true;                          // Before는 다음정점(Next)의 DFS리턴값이니까, 현재 정점(작은수)보다 방문순서가 커야 단절점!

		ret = min(ret, Before);
	}

	if (Root== true && child >= 2)
		Cutspot[Now] = true;

	return ret;
}
