// 두 점의 거리를 구할 때, 재귀를 이용한 조합으로 풀면 시간초과! 그냥 2중for문사용해줌

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

struct init_info { double x,y; int n; };
struct Edge { int from, to; double weight; 
bool operator<(const Edge& a)const
{
	return weight < a.weight;
}
};

vector<init_info>Input;
vector<Edge>E;

int Parent[1100];
int height[1100];
int N;
int check[110];

void CalDist();
int findparent(int a);
void merge(int a, int b);

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	double min = 0;

	cin >> N; 

	
	for (int i = 0; i < N; i++)
	{
		double a, b;
		cin >> a >> b;
		Input.push_back({ a,b,i+1 });
	}

	CalDist();

	sort(E.begin(), E.end());

	for (int i = 0; i < N; i++)
	{
		Parent[i] = i;
	}

	for (int i = 0; i < E.size(); i++)
	{
		if (findparent(E[i].from) == findparent(E[i].to)) continue;
		min += E[i].weight;
		merge(E[i].from, E[i].to);
	}

	cout.precision(3);
	cout << min << endl;
	
	return 0;
}

void CalDist()
{
	for (int i = 0; i < Input.size() - 1; i++)
	{
		for (int j = 1; j < Input.size(); j++)
		{
			if (i == j)continue;
			double dist = 0;
			dist = sqrt(pow((Input[i].x - Input[j].x), 2) + pow((Input[i].y - Input[j].y), 2));
			E.push_back({ i,j,dist });
		}
	}
}

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

	if (height[roota] > height[rootb]) swap(roota, rootb);
	else if (height[roota] == height[rootb]) height[rootb]++;

	Parent[roota] = rootb;
}
