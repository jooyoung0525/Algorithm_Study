#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, M;
vector<int>Graph[1010];
vector<int>Result;
int Num[1010]; //1번인덱스부터 시작(정점시작이 1)
queue<int>Q;

void Input();
void Find();
bool Check(); //하나라도 방문안한점이 있게 끝나면 false
void Print();

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	Input();
	Find();
	Print();

	return 0;
}

void Input() {

	//데이터 입력
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		int arr[1010] = {0};

		for (int j = 0; j < num; j++) {
			int a;
			cin >> a;
			arr[j] = a;
		}

		//그래프만들기
		for (int j = num - 1; j >= 0; j--) {
			if (j - 1 < 0)break;
			Graph[arr[j]].push_back(arr[j - 1]); //뒷 인덱스에서 앞의인덱스 정점을 넣어줌
		}

	}


	for (int i = 1; i <= N; i++) {
		Num[i] = Graph[i].size(); //각 정점의 진입차수를 저장
	}

}


void Find() {
	
//초기값 설정
	for (int i = 1; i <= N; i++) {
		if (Num[i] == 0) { //진입차수가 0이면 시작
			Q.push(i); //큐에넣어주고
			Num[i] = -1; //방문한 정점이라는 것을 표시
		}
	}


	while (!Q.empty()) { //큐가 빌때까지 계속 반복
	
		int cur = Q.front(); //현재의 정점
		Q.pop();

		Result.push_back(cur); //결과에 값을 넣어줌


		for (int i = 1; i <= N; i++) { //1번부터 N번까지 
			if (cur == i)continue; //현재의 정점은 이미 방문했으니까 건너뛰고
			for (int j = 0; j < Graph[i].size(); j++) { //모든 그래프의 정점을 돌면서
				if (Graph[i][j] == cur) Num[i]--; //현재의 정점과 연결된 정점들의 진입차수를 1씩 빼준다.
			}
		}

		for (int i = 1; i <= N; i++) { //다시 진입차수가 0이된 정점들을 큐에 넣어주고
			if (Num[i] == 0) {
				Q.push(i);
				Num[i] = -1; //방문처리를 해준다(재방문방지)
			}
		}
	
	}
}

bool Check() { 

	for (int i = 1; i <= N; i++) {
		if (Num[i] > 0) return false; //Find()함수를 다 돌았지만, 방문을 안한정점이 있으면 false (위상정렬이 모든 정점을 방문하지 않음)
	}
	return true; //모든정점을 방문다했으면 위상정렬됨
}



void Print() {
	if (Check()) { //Check()함수를 돌았을때, 모든정점을 방문했으면
		for (int i = 0; i < N; i++) {
			cout << Result[i] << "\n"; //0~N까지 결과값을 출력
		}
	}
	else cout << 0; //모든 점 방문안했으면 0출력

}
