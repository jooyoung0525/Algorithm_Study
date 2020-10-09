// 19:00 ~20:08

#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int T,K,Tot;
int Topni[5][10];
int check[5];

void Find(int num, int dir);
void Rot_clock(int num);
void Rot_unclock(int num);
void Cal_Ans();

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> T;
	for (int q = 1; q <= T; q++) {

		K = 0;
		Tot = 0;
		memset(Topni, 0, sizeof(Topni));

		cin >> K;

		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> Topni[i][j];
			}
		}

		for (int i = 0; i < K; i++) {
		
			memset(check, 0, sizeof(check));
			int num, dir; //dir : 1  -> 시계 , dir = -1 -> 반시계
			cin >> num >> dir;

			Find(num, dir);

			
			for (int j = 1; j <= 4; j++) {
				if (check[j] == 1) {
					Rot_clock(j);
				}
				else if (check[j] == -1) {
					Rot_unclock(j);
				}
			}
			
		}
		
		Cal_Ans();
		cout << '#' << q << ' ' << Tot << "\n";
	}
	return 0;
}


void Find(int num, int dir) {

	//cout << num << " " << dir << "\n";
	check[num] = dir;

	if (num - 1 >= 1) {
		if (Topni[num - 1][2] != Topni[num][6] && check[num-1] == 0) {
			check[num - 1] = (dir == 1) ? -1 : 1;
			Find(num - 1, check[num - 1]);
		}
	}
	if (num + 1 <= 4) {
		if (Topni[num + 1][6] != Topni[num][2] && check[num + 1] == 0) {
			check[num + 1] = (dir == 1) ? -1 : 1;
			Find(num + 1, check[num + 1]);
		}
	}

	return;
}

void Rot_clock(int num)
{
	queue<int>Q;
	for (int i = 0; i < 8; i++)
		Q.push(Topni[num][i]);

	for (int i = 1; i < 8; i++) {
		Topni[num][i] = Q.front();
		Q.pop();
	}

	Topni[num][0] = Q.front();
}


void Rot_unclock(int num)
{
	queue<int>Q;
	for (int i = 0; i < 8; i++)
		Q.push(Topni[num][i]);

	Topni[num][7] = Q.front();
	Q.pop();

	for (int i = 0; i < 7; i++) {
		Topni[num][i] = Q.front();
		Q.pop();
	}

}


void Cal_Ans() {

	if (Topni[1][0] == 1) Tot += 1;
	if (Topni[2][0] == 1) Tot += 2;
	if (Topni[3][0] == 1) Tot += 4;
	if (Topni[4][0] == 1) Tot += 8;
}