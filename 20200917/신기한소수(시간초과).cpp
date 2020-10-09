#include<iostream>
#include<string>
#include<cmath>

using namespace std;


int N;
int First[5] = { 2,3,5,7 };
int odd[6] = { 1,3,5,7,9 };

void DFS(int cnt, string ans);
bool Sosu(int num);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < 4; i++) {
		DFS(1, to_string(First[i]));
	}

	return 0;
}

void DFS(int cnt, string ans) {

	if (cnt == N) {
		cout << ans << "\n";
		return;
	}

	for (int i = 0; i < 5; i++) {
		string next = ans + to_string(odd[i]);
		int s = atoi(next.c_str());
		if (Sosu(s)) {
			DFS(cnt + 1, next);
		}
	}
}

bool Sosu(int num)
{
	if (num < 2) return false;

	for (int i = 2; i <= sqrt(num); i++) {
		for (int j = i + i; j <= num; j += i)
		{
			if (num == j) return false;
		}
	}
	return true;
}
