#include<iostream>

using namespace std;

int Paper[11][11];
bool check[11][11];
int remainPaper[6] = { 0,5,5,5,5,5 };
int All = 0;
int MMin = 987654321;
bool Stop = false;

void IInput();
void Sticker();
bool Checkingsize(int x, int y, int cnt);
void patch_paper(int x, int y, int cnt, bool now);
void Print();

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	IInput(); //입력
	Sticker(); //스티커

	if (MMin == 987654321) cout << -1;
	else
		cout << MMin;

	return 0;
}


void IInput() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> Paper[i][j];
			if (Paper[i][j] == 1)All++;
		}
	}
}

void Sticker() {


	if (All == 0)
	{
		int mmin = 25;
		for (int i = 1; i <= 5; i++) {
			mmin -= remainPaper[i];
		}
		if (MMin > mmin)MMin = mmin;
		return;
	}

	int r, c = 0; bool flag = false;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			if (Paper[i][j] == 1 && !check[i][j]) { //맞는크기 색종이구하기
				r = i;
				c = j;
				flag = true;
				break;
			}
		}
		if (flag)break;
	}

	for (int k = 1; k <= 5; k++) { //색종이 크기 5가지

		if (remainPaper[k] > 0 && Checkingsize(r, c, k)) { //색종이가 남아있거나, 붙일수 있으면

			remainPaper[k]--;
			patch_paper(r, c, k, true);
			//Print();

			Sticker();

			remainPaper[k]++;
			patch_paper(r, c, k, false);
		}
		//else return; //색종이는 1~붙이니까 작은사이즈 못붙이면 큰사이즈도 못붙임.
	}
}

bool Checkingsize(int x, int y, int cnt)
{
	for (int i = x; i < x + cnt; i++) {
		for (int j = y; j < y + cnt; j++) {
			if (check[i][j] || Paper[i][j] == 0 || i >= 10 || j >= 10)return false;
		}
	}
	return true;
}


void patch_paper(int x, int y, int cnt, bool now) {

	if (now == true) {
		for (int i = x; i < x + cnt; i++) {
			for (int j = y; j < y + cnt; j++) {
				check[i][j] = now;
				All--;
			}
		}
		//Print();
	}
	else {
		for (int i = x; i < x + cnt; i++) {
			for (int j = y; j < y + cnt; j++) {
				check[i][j] = now;
				All++;
			}
		}
	}


}

void Print() {

	cout << "\n";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << check[i][j] << " ";
		}
		cout << "\n";
	}

}
