/*
1. 순환점찾기 -> DFS (순환점 찾으면 빠져나오기)
2. 순환점부터 그 외의 역에대한 거리구하기 -> DFS(순환점부터)
*/
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N;
vector<int>Subway[3010];
bool visit[3010];
int dist[3010];
bool flag, Stop;

void IInput();
void Find_Cycle();
void DFS(int start, int before, int cur);
void Print();
void Calculate_dist();
void makedist(int cur);

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	IInput();
	Find_Cycle();
	Calculate_dist();
	Print();

	return 0;
}


void IInput() //입력
{
	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		int a, b;
		cin >> a >> b;
		Subway[a].push_back(b);
		Subway[b].push_back(a);
	}
}


void Find_Cycle() {

	for (int i = 1; i <= N; i++) { //모든점을 시작점으로 DFS를 돌려본다.
		memset(visit, false, sizeof(visit)); //visit : 순환점이면 true
		flag = false; //DFS에 초기값을 줬을 때, 맨처음 start==cur에서 걸리지 않게 하려고
		visit[i] = true; 
		DFS(i, i, i);
		if (Stop)break; //순환을 찾았으면 break
		visit[i] = false;
	}
}


void DFS(int start, int before, int cur) {

	if (start == cur && flag) {
		Stop = true;
		return;
	}

	for (int i = 0; i < Subway[cur].size(); i++) {
		flag = true;

		if (before == Subway[cur][i])continue;
		if (start != Subway[cur][i] && visit[Subway[cur][i]])break; // *중요* DFS돌다가 이미 방문된점이고, 시작점과 값이 다르면 break 해줘야함
		                                                            // 이 조건을 걸지 않으면 순환을 돌고 다른점으로 가는 걸 걸러주지 않음 -> 6 같은 모양?
		visit[Subway[cur][i]] = true;
		
		DFS(start, cur, Subway[cur][i]);
		
		if (Stop) break; //순환을 찾았으면 DFS끝내기
		visit[Subway[cur][i]] = false;
	}

	return;
}

void Print() {
	for (int i = 1; i <= N; i++) {
		cout << dist[i] << " ";
	}
}


void Calculate_dist() {

	for (int i = 1; i <= N; i++) { //순환점 기준으로 DFS돌면서 거리계산
		
		if (!visit[i])continue; //순환점이아니면 건너뛰기
		makedist(i);
	
	}
}

void makedist(int cur) {

	for (int i = 0; i < Subway[cur].size(); i++) {
		
		if (visit[Subway[cur][i]] || dist[Subway[cur][i]]>0) continue; //순환점이거나, 이미 거리계산이 되어있으면 건너 뜀
		dist[Subway[cur][i]] = dist[cur] + 1; //이전정점의 거리에서 +1씩
		makedist(Subway[cur][i]);
	}
}