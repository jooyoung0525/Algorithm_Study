/*
	30-40분?
	DFS(start,요금,비용);
*/
#include<iostream>
#include<cstring>

#define MAX 987654321 

using namespace std;

int MMin = MAX;
int cost[4]; //0:1일, 1:1달, 2:3달, 3:1년
int yearPlan[13]; //1부터~

void initialize();
void Input();
void solve();
void DFS(int month, int fee, int allCost);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}



void solve(){
	
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		initialize();
		Input();
		DFS(0, 0, 0);
		cout << '#' << tc << " " << MMin << "\n";
	}
}



void initialize() {

	MMin = MAX;
	memset(cost, 0, sizeof(cost));
	memset(yearPlan, 0, sizeof(yearPlan));
}

void Input() {
 
	for (int i = 0; i < 4; i++) {
		cin >> cost[i];
	}

	for (int i = 1; i <= 12; i++) {
		cin >> yearPlan[i];
	}
}


void DFS(int month, int fee, int allCost) {
	
	if (month >= 13) {
	
		if (MMin > allCost)
			MMin = allCost;
		return;
	}

	if (fee == 0) { //1일
		int nextcost = allCost + (yearPlan[month] * cost[fee]);
		DFS(month + 1, 0,nextcost);
		DFS(month + 1, 1,nextcost);
		DFS(month + 1, 2,nextcost);
		DFS(month + 13, 3, allCost+cost[3]);
	}
	else if (fee == 1) { //1달
		if (yearPlan[month] == 0) {
			DFS(month + 1, 0, allCost);
			DFS(month + 1, 1, allCost);
			DFS(month + 1, 2, allCost);
			DFS(month+13, 3, allCost+cost[3]);
		}
		else {
			DFS(month + 1, 0, allCost + cost[fee]);
			DFS(month + 1, 1, allCost + cost[fee]);
			DFS(month + 1, 2, allCost + cost[fee]);
			DFS(13, 3, allCost + cost[3]);
		}
	}
	else if (fee == 2) { //3달
		DFS(month + 3, 0, allCost + cost[fee]);
		DFS(month + 3, 1, allCost + cost[fee]);
		DFS(month + 3, 2, allCost + cost[fee]);
		DFS(month + 12, 3, allCost + cost[3]);
	}
	
}