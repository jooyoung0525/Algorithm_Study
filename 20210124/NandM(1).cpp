#include<iostream>
#include<string>

using namespace std;

void Select(int cnt, string s);
int N, M;
bool check[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		check[i] = true;
		string str = to_string(i);
		Select(1, str);
		check[i] = false;
	}

	return 0;
}

void Select(int cnt, string s) {

	if (cnt == M) {
		for (int i = 0; i < s.length(); i++) {
			cout << s[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (check[i])continue;
		check[i] = true;
		Select(cnt + 1,s+to_string(i));
		check[i] = false;
	}
}
