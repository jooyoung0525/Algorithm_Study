
/*
1. 간선정보(N-1개!)를 입력받아 트리를 만든다. (가중치도 함께저장)
2. BFS를 돌면서 Depth값 구하기
3. Parent[][]배열을 작성
4. D,E를 입력받으면서, 1) 깊이맞추기(vector에 간선가중치저장) 2)조상찾기 (vector에 간선가중치저장)
5. vector값에서 최소, 최대를 찾아 출력한다.
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

#define MAX 100010

using namespace std;

struct info { int to, cost; };

vector<info>Tree[MAX];
int Depth[MAX];
int Parent[18][MAX];
pair<int,int> Value[18][MAX];
int N, M;

void MakeTree();
void FindDepth();
void MakeParent();
void InputDE();
void Compare(int a, int b);

int main() {

	ios_base::sync_with_stdio(false); //반드시!!!!!
	cin.tie(0);

	MakeTree();
	FindDepth();
	MakeParent();
	InputDE();

	return 0;
}


void MakeTree() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b ,c;
		cin >> a >> b >> c;

		Tree[a].push_back({ b,c });
		Tree[b].push_back({ a,c });
	}
}


void FindDepth() {

	queue<int>Q;
	memset(Depth,-1,sizeof(Depth));


	Depth[1] = 0;
	Q.push(1);
	Parent[0][1] = 0;


	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		for (int i = 0; i < Tree[cur].size(); i++) {
			int next = Tree[cur][i].to;
			if (Depth[next] == -1) {
				Depth[next] = Depth[cur] + 1;
				Q.push(next);
				Parent[0][next] = cur;
				Value[0][next] = { Tree[cur][i].cost,Tree[cur][i].cost };
			}
		}
	}
}


void MakeParent() {

	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= N; j++) {
			Parent[i][j] = Parent[i - 1][Parent[i - 1][j]];
			Value[i][j].first = min(Value[i-1][j].first, Value[i - 1][Parent[i - 1][j]].first);
			Value[i][j].second = max(Value[i-1][j].second, Value[i - 1][Parent[i - 1][j]].second);
		}
	}
}


void InputDE() {
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Compare(a, b);
	}
}

void Compare(int a, int b) {

	vector<int>Cost;
	int MMax = -1; int MMin = 987654321;
	

	if (Depth[a] < Depth[b]) //무조건 a가 깊이가 더 깊게
		swap(a, b);

	for (int i = 17; i >= 0; i--) { // 두 정점의 깊이를 같게 맞춰주면서 지나온 cost모두 저장
		if (Depth[b] <= Depth[Parent[i][a]]) {
			MMin = min(MMin, Value[i][a].first);
			MMax = max(MMax, Value[i][a].second);

			a = Parent[i][a];
		}
	}

	for (int i = 17; i >= 0 && a != b; i--) { //두 점이 같지 않으면 조상이 같은지 확인
		if (Parent[i][a] != Parent[i][b]) {
			
			MMin = min(MMin, Value[i][a].first);
			MMax = max(MMax, Value[i][a].second);

			MMin = min(MMin, Value[i][b].first);
			MMax = max(MMax, Value[i][b].second);

			a = Parent[i][a];
			b = Parent[i][b];	
		}
	}
	if (a != b) {
	

		MMin = min(MMin, Value[0][a].first);
		MMax = max(MMax, Value[0][a].second);

		MMin = min(MMin, Value[0][b].first);
		MMax = max(MMax, Value[0][b].second);
	
	
	}
	
	cout << MMin<<" "<<MMax<< "\n";
}
