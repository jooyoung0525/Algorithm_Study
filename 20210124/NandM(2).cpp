// 1~N 중 중복없이 M개 고른 수열

#include<iostream>
#include<string>

using namespace std;

void Select(int idx, int cnt, string s);
int N, M;
bool check[10];

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) { // 처음 수 선택
		string str = to_string(i); //스트링으로 변환
		Select(i, 1, str); //현재수와 cnt, string으로 변환한 수  넘기기
	}

	return 0;
}

void Select(int idx, int cnt, string s) {

	if (cnt == M) { //cnt가 M이랑 같으면

		//출력
		for (int i = 0; i < s.length(); i++) {
			cout << s[i] << " ";
		}
		cout << "\n";
		
		return;
	}

	for (int i = idx+1; i <= N; i++) { //현재 수 다음부터 for문 돌리기
		Select(i, cnt + 1,s+to_string(i));
	}
}
