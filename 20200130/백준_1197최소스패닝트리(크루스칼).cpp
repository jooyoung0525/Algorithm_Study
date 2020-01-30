#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct info { int start, end, weight;

	bool operator<(const info& a)const
	{
		return weight < a.weight;
	};
};

int V, E,result;
vector<info>edge;
int Parent[10010];
int height[10010];

int findparent(int a)
{
	if (Parent[a] == a)return a;
	return Parent[a] = findparent(Parent[a]);
}

void merge(int a, int b)
{
	int roota = findparent(a);
	int rootb = findparent(b);

	if (roota == rootb)return;

	if (height[roota] > height[rootb])
		swap(roota, rootb);
	else if (height[roota] == height[rootb])
		height[rootb]++;

	Parent[roota] = rootb;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int s=0, e=0, w=0;
		cin >> s >> e >> w;

		edge.push_back({ s,e,w });
	}

	//초기화
	for (int i = 1; i <= V; i++)
	{
		Parent[i] = i;
	}

	sort(edge.begin(), edge.end());

	for (int i = 0; i < edge.size(); i++)
	{
		if (findparent(edge[i].start) == findparent(edge[i].end)) continue;
		result+=edge[i].weight;
		merge(edge[i].start, edge[i].end);
	}
	cout << result;
	return 0;
}
