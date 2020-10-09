#include<iostream>
#include<set>
#include<cmath>
#include<string>
#include<vector>

using namespace std;

set<int>Sosu; //소수가 아닌 애들을 넣음.
vector<string>answer;

int N;
int usenum[10] = { 1,2,3,4,5,6,7,8,9 };

void Find_Erathos();
void DFS(int cnt, string ans);



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;

	Find_Erathos();
	DFS(0, "");

	for (int i = 0; i < answer.size()-1; i++) {
		cout << answer[i] << "\n";
	}
	cout << answer[answer.size() - 1];

	return 0;
}

void Find_Erathos()
{
	Sosu.insert(0);
	Sosu.insert(1);

	for (int i = 2; i <= sqrt(100000000); i++) {
		if (Sosu.find(i)!=Sosu.end())continue;
		for (int j = i + i; j <= sqrt(100000000); j += i) {
			if (Sosu.find(j) != Sosu.end())continue;
			Sosu.insert(j);
		}
	}
}

void DFS(int cnt, string ans) {

	if (cnt == N) {
		answer.push_back(ans);
		return;
	}

	for (int i = 0; i < 10; i++) {
		string next = ans + to_string(usenum[i]);
		int s = atoi(next.c_str());
		if (Sosu.find(s)==Sosu.end()) {
			DFS(cnt + 1, next);
		}
	}
}
