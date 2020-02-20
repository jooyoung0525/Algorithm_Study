### 두 문제는 MAX와, KMAX만 달라지고 동일


#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

#define MAX 100010
#define KMAX 17
using namespace std;

int N, M; 
vector<int>Edge[MAX]; //간선정보 저장
int Parent[20][MAX]; //각 정점의 2^K번째 조상의 정보 저장된 배열
int Depth[MAX]; //트리에서 각 정점의 깊이 저장

void InputEdge();
void Maketree();
void Fill_sparetable();
void Save_Ans();
void Compare(int a, int b);


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	InputEdge(); //간선정보 입력받기

	Maketree(); //BFS로 트리만들기
	
	Fill_sparetable(); //sparetable을 채워서 2^k의 조상정보를 갱신해준다.
	
	Save_Ans(); //M만큼 입력받은 두수의 LCA를 구함


	return 0;
}


void InputEdge()
{
	cin >> N;
	for (int i = 0; i < N - 1; i++) //트리는 정점N개, 간선N-1개
	{
		int from = 0, to = 0;
		cin >> from >> to;
		Edge[from].push_back(to);
		Edge[to].push_back(from);
	}
}

void Maketree() //BFS로 트리생성
{
	queue<int>Q;
	memset(Depth, -1, sizeof(Depth));

	Depth[1] = 0; //정점은 1번부터 시작 ==> ※idx = 0은 초기화하지말기(초기화해주면 틀림 -->원래 초기화값이 -1이기때문)
	Parent[0][1] = 0; //1번정점은 루트노드여서 조상정점이 없음 (0으로 표기)
	Q.push(1); //루트를 큐에 넣어줌

	while (!Q.empty())
	{
		int NowSpot = Q.front();
		Q.pop();

		for (int NextSpot : Edge[NowSpot]) //C++식 포문ㅎㅎ
		{
			if (Depth[NextSpot] == -1)
			{
				Depth[NextSpot] = Depth[NowSpot] + 1; //현재정점과 연결된 다음정점은 깊이가 한층 깊어짐
				Parent[0][NextSpot] = NowSpot; //현재정점이 연결된다음정점의 부모노드 (k==0은 바로 윗 부모정점)
				Q.push(NextSpot);
			}
		}
	}
}

void Fill_sparetable()
{
	for (int k = 1; k <= KMAX; k++)  //k의 값은 정점에 따라 다르게 설정가능 (보통 2^17이 10만일때,)
	{
		for (int v = 1; v <= N; v++)
		{
			Parent[k][v] = Parent[k - 1][Parent[k - 1][v]]; //2^k의 조상을 채워준다.
		}
	}
}

void Save_Ans()
{
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a = 0, b= 0 ;
		cin >> a >> b;

		Compare(a, b);
	}
}

void Compare(int a, int b)
{
	int LCAresult = 0;
	

	if (Depth[a] < Depth[b]) //무조건 a정점이 깊게
		swap(a, b);

	for (int k = KMAX; k >= 0; k--)
	{
		if (Depth[b] <= Depth[Parent[k][a]]) { //b정점의 깊이보다 a정점조상의 깊이가 깊거나 같으면 (k==16,depth 0에서부터 시작하므로)
			a = Parent[k][a]; //a정점을 a의 조상정점으로 바꿔주며 b와 깊이를 맞춘다.
		}
	}

	for (int k = KMAX; k >= 0 && a!=b; k--)
	{
		if (Parent[k][a] != Parent[k][b]) //현재정점 a와b가 같지않고, a와b의 부모노드가 같지않을때, 둘다 부모노드로 한칸올려줌!
		{
			a = Parent[k][a];
			b = Parent[k][b];
		}
	}

	if (a == b) LCAresult = a; //두수가 같으면 LCA
	else LCAresult = Parent[0][a]; //두 수가 다르면 둘중 아무거나의 조상이 LCA
	 
	cout << LCAresult << "\n";
}
