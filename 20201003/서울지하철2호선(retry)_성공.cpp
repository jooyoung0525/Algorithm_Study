/*
1. ��ȯ��ã�� -> DFS (��ȯ�� ã���� ����������)
2. ��ȯ������ �� ���� �������� �Ÿ����ϱ� -> DFS(��ȯ������)
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


void IInput() //�Է�
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

	for (int i = 1; i <= N; i++) { //������� ���������� DFS�� ��������.
		memset(visit, false, sizeof(visit)); //visit : ��ȯ���̸� true
		flag = false; //DFS�� �ʱⰪ�� ���� ��, ��ó�� start==cur���� �ɸ��� �ʰ� �Ϸ���
		visit[i] = true; 
		DFS(i, i, i);
		if (Stop)break; //��ȯ�� ã������ break
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
		if (start != Subway[cur][i] && visit[Subway[cur][i]])break; // *�߿�* DFS���ٰ� �̹� �湮�����̰�, �������� ���� �ٸ��� break �������
		                                                            // �� ������ ���� ������ ��ȯ�� ���� �ٸ������� ���� �� �ɷ����� ���� -> 6 ���� ���?
		visit[Subway[cur][i]] = true;
		
		DFS(start, cur, Subway[cur][i]);
		
		if (Stop) break; //��ȯ�� ã������ DFS������
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

	for (int i = 1; i <= N; i++) { //��ȯ�� �������� DFS���鼭 �Ÿ����
		
		if (!visit[i])continue; //��ȯ���̾ƴϸ� �ǳʶٱ�
		makedist(i);
	
	}
}

void makedist(int cur) {

	for (int i = 0; i < Subway[cur].size(); i++) {
		
		if (visit[Subway[cur][i]] || dist[Subway[cur][i]]>0) continue; //��ȯ���̰ų�, �̹� �Ÿ������ �Ǿ������� �ǳ� ��
		dist[Subway[cur][i]] = dist[cur] + 1; //���������� �Ÿ����� +1��
		makedist(Subway[cur][i]);
	}
}