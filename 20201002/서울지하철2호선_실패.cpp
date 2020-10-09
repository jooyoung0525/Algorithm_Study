#include<iostream>
#include<vector>
#include<cstring>

/*
	1. DFS로 순환그래프 찾기
	2. 순환 아닌 점들 거리 찾기 (DFS 2) 
*/
using namespace std;


int N;
vector<int>Graph[3010];
bool visit[3010];
int dist[3010];
int start = 0;
bool flag;
int cnt=0;
void DFS(int before, int cur);
void DFS2(int parent,int cur);

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
	
		int a, b;
		cin >> a >> b;

		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}

	//DFS로 순환 찾음 -> 순환인것들은 visit = 1표시
	for (int i = 1; i <= N; i++) {
		
		memset(visit, false, sizeof(visit));
		start = i;
		DFS(0, i);
		if (flag) break;
	}

	for (int i = 1; i <= N; i++) {
		cout << visit[i] << " ";
	}

	//순환인 애들부터 다른 점의 거리계산
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < Graph[i].size(); j++) {
			if (visit[Graph[i][j]] == true) continue; //순환인 점은 건너뛰기
			DFS2(i,Graph[i][j]);
		}
	}

	/*
	for (int i = 1; i <= N; i++) {
		cout << dist[i] << " ";
	}*/
	
	return 0;
}

void DFS(int before, int cur) {
	
	if (start == cur && visit[cur] == true) {
		flag = true;
		return;
	}

	visit[cur] = true;

	for (int i = 0; i < Graph[cur].size(); i++) {
		
		int now = Graph[cur][i];
		if (visit[now])return;
		if (before == now)continue;
		DFS(cur, now);
		if (flag)return;
		visit[now] = false;
	}

}


void DFS2(int parent,int cur) {
	
	if (visit[cur] || dist[cur] > 0)return;
	dist[cur] = dist[parent] + 1;
	//cnt--;
	for (int i = 0; i < Graph[cur].size(); i++) {
		if (visit[Graph[cur][i]] == true)continue;
		DFS2(cur, Graph[cur][i]);
	}
	return;
}