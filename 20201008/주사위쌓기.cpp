// 22:10 ~ 23:55 

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int, int>>firstCube; //1번 주사위 위,아래 값 저장.
vector<string>Num; // 주사위 옆면 숫자 string
int N;
int Cube[10005][6];
int MMax = -1;

void Calculate(); //1번주사위 기준으로 돌림
string canNum(int up,int down); // 옆면으로 오는 숫자를 string으로
void findNum(int idx, int stand); // 1번주사위 부터 N번주사위까지 위,아래 맞춤
int search(int a); // a와 짝이되는 인덱스값 반환
int findMax(string a); //vector에 모아놓은 옆면정보중, 각 옆면의 최댓값을 찾아 리턴

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		
		for (int j = 0; j < 6; j++) {
			cin>>Cube[i][j];
		}
	}
	
	//주사위 6면의 idx를 0~5라고 봤을 때, {0,5} {1,3} {2,4}가 짝을이룸
	firstCube.push_back({ Cube[0][0],Cube[0][5] });
	firstCube.push_back({ Cube[0][1],Cube[0][3] });
	firstCube.push_back({ Cube[0][2],Cube[0][4] });

	Calculate();

	cout << MMax << "\n";
	return 0;
}

void Calculate() {

	//1번 주사위 기준 돌려줌
	for (int i = 0; i < firstCube.size(); i++) { //3 1 6 5
	
		Num.clear(); //1번 주사위 기준이 바뀔때 계속 옆면정보 저장한 벡터 초기화 해야함.
		
		int up = firstCube[i].first; // 2
		int down = firstCube[i].second; //4

		string n = canNum(up, down); //윗면이랑 아랫면 숫자를 canNum에 넘기면 옆면의 숫자를 string으로 변환해서 리턴
		Num.push_back(n); //옆면정보에 저장
		
		//1번주사위는 놓고싶은대로 놓을 수 있으므로, 위와 아래를 바꿀 수 있음.
		findNum(1, up); //2번주사위부터, 윗면 숫자 넘겨줌.
		findNum(1, down);
	}

}

string canNum(int up, int down) { //가능한 숫자찾는합수

	string s = "";
	for (int j = 1; j <= 6; j++) //1~6중에 
	{
		if (j == up || j == down)continue; //매개변수로 넘겨받은 위와 아래 수 제외하고
		s += (j + '0'); //스트링으로 변환 ==> 1~6은 한자리수이므로 스트링으로 변환 가능
	}

	return s;
}


void findNum(int idx, int stand) { //stand :윗값
	
	if (idx == N) {
		//각 스트링의 최댓값
		int total = 0;

		int mmax = 0;
		for (int i = 0; i < Num.size(); i++) {
		//	cout << "i "<<Num[i] << "\n";
			mmax = findMax(Num[i]); //주사위 모두 쌓았을 때, 각 주사위의 옆면정보를 findMax로 넘기면 findMax에서 옆면중 최대숫자 찾아줌.
			total+=mmax; //각 옆면의 최댓값의 합
		}

		MMax = max(MMax, total); 

		return;
	}


	int upidx = 0; int downidx = 0; //윗면과 아랫면의 

	for (int i = 0; i < 6; i++) {
		if (stand == Cube[idx][i]) { //이전 주사위의 윗면과 같은 숫자를 찾았을 때, 
			downidx = i; //해당 인덱스는 아랫면 (이전의 위 == 현재 아래)
			upidx = search(i); //아랫면과 짝이되는 윗면의 인덱스 찾음
			break;
		}
	}

	int upnum = Cube[idx][upidx]; //각 인덱스에 배치된 위, 아랫면의 숫자도 찾아줌.
	int downnum = Cube[idx][downidx];

	string nnum = canNum(downnum, upnum); //위, 아래 숫자 제외한 옆면의 숫자 리턴
	Num.push_back(nnum); //옆면 벡터에 저장
	
	findNum(idx + 1, upnum); //현재 윗면의 숫자와 다음 주사위로 넘어감,

	Num.pop_back(); //옆면벡터에 저장된거 빼줌
}


int search(int a) { //짝이 맞는 인덱스 값 찾기
	if (a == 0)return 5;
	else if (a == 1)return 3;
	else if (a == 2)return 4;
	else if (a == 3)return 1;
	else if (a == 4)return 2;
	else if (a == 5)return 0;
}


int findMax(string a) { //옆면의 숫자 중 최댓값 찾기.

	int mmax = 0;
	for (int i = 0; i < a.length(); i++) {
		mmax = max(mmax, a[i] - '0');
	}
	return mmax;
}