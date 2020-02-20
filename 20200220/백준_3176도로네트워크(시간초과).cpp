#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

#define MAX 100001
#define KMAX 17

using namespace std;

struct info { int to, cost; };
int N,M;
vector<info>Edge[MAX];
int Parent[KMAX+5][MAX];
int Depth[MAX];

int PathMax[KMAX+5][MAX], PathMin[KMAX+5][MAX];

void MakeTree();
void Fill_Sparetable();
void IInit();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		Edge[from].push_back({ to,cost });
		Edge[to].push_back({ from,cost });
	}

	IInit();
	MakeTree();
	Fill_Sparetable();

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		int mmin = 1000001, mmax = -1;

		cin >> a >> b;
		
		if (Depth[a] > Depth[b]) //먼저, 깊이비교
		{
			for (int K = KMAX; K >= 0 && a!=b; K--)
			{
				if (Depth[b] <= Depth[Parent[K][a]]) {

					mmin = min(mmin, PathMin[K][a]);
					mmax = max(mmax, PathMax[K][a]);
					a = Parent[K][a];

				}
			}
		}

		else if (Depth[a] < Depth[b]) //먼저, 깊이비교
		{
			for (int K = KMAX; K >= 0 && a!=b ; K--)
			{
				if ( Depth[a] <= Depth[Parent[K][b]]) {

					mmin = min(mmin, PathMin[K][b]);
					mmax = max(mmax, PathMax[K][b]);
					b = Parent[K][b];

				}
			}
		}
		

		for (int K = KMAX; K >= 0 && a != b; K--)
		{
			if(a!=b&&Parent[K][a] != Parent[K][b])
			{
				mmax = max(mmax, max(PathMax[K][a], PathMax[K][b]));
				mmin = min(mmin, min(PathMin[K][a], PathMin[K][b]));
				a = Parent[K][a];
				b = Parent[K][b];
			}
		}

		if (a != b)
		{
			mmax = max(mmax, max(PathMax[0][a], PathMax[0][b]));
			mmin = min(mmin, min(PathMin[0][a], PathMin[0][b]));
		}

		cout << mmin << " " << mmax << endl;
		
	}
	

	return 0;
}

void MakeTree()
{
	queue<int>Q;
	memset(Depth, -1, sizeof(Depth));
	Depth[1] = 0; //정점1을 루트노드로
	Parent[0][1] = 0;
	Q.push(1);

	while (!Q.empty())
	{
		int CurSpot = Q.front();
		Q.pop();

		for (int i = 0; i<Edge[CurSpot].size(); i++)
		{
			int NextSpot = Edge[CurSpot][i].to;
			int Cost = Edge[CurSpot][i].cost;

			if (Depth[NextSpot] == -1)
			{
				PathMax[0][NextSpot] = Cost;
				PathMin[0][NextSpot] = Cost;

				Depth[NextSpot] = Depth[CurSpot] + 1;
				Parent[0][NextSpot] = CurSpot;
				Q.push(NextSpot);
			}
		}
	}
}

void Fill_Sparetable()
{
	for (int K = 1; K <=KMAX; K++)
	{
		for (int V = 1; V <= N; V++)
		{
			Parent[K][V] = Parent[K - 1][Parent[K - 1][V]];
			PathMax[K][V] = max(PathMax[K - 1][V], PathMax[K - 1][Parent[K - 1][V]]);
			PathMin[K][V] = min(PathMin[K - 1][V], PathMin[K - 1][Parent[K - 1][V]]);
		}
	}
}

void IInit()
{
	for (int i = 0; i < MAX; i++)
	{
		Depth[i] = -1;
		for (int j = 0; j < KMAX+5; j++)
		{
			PathMin[j][i] = MAX;
		}
	}
}
