#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

/*
1. K������ ����ϴ��� Ȯ��.
2. 1~D���� ������ ����
   -> ������ ���ϸ鼭 K��������ϴ��� Ȯ��. -> ����Ѵٸ� �� ���
      --> ���վȿ��� A,B��ǰ ����
*/

int T, D, W, K;
int Cell[15][25];
bool flag = false;

void Init();
void IInput();
int Comb();
bool Check(int cell[15][25]);
void put_medicine(vector<int>n, int idx, int map[15][25]);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;

	for (int q = 1; q <= T; q++) {
		
		Init();
		IInput();
		int result = Comb();
		
		cout << "#" << q << " " << result << "\n";
	}

	return 0;
}


void Init() {
	D = 0;
	W = 0;
	K = 0;
	memset(Cell, 0, sizeof(Cell));
	flag = false;
}

void IInput() {
	cin >> D >> W >> K;
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			cin >> Cell[i][j];
		}
	}

	
}

bool Check(int cell[15][25]) {

	for (int i = 0; i < W; i++) {
		int a = 0; int b = 0;
		int before = cell[0][i]; //������ ���ǰ�̾����� ǥ���ؼ�, ���� ��ǰ�� �ٸ��� ������ǰ���� �ô��� �ʱ�ȭ.
		bool stop = false; //���ٸ��� K���� �����ϴ��� Ȯ��

		for (int j = 0; j < D; j++) {
			if (cell[j][i] == 0) {
				if (before != cell[j][i]) {
					if (before == 1) b = 0;
					before = cell[j][i];
				}
				a++;
				if (a >= K) { // K ���� ����
					stop = true;
					break;
				}

			}
			else {
				if (before != cell[j][i]) {
					if (before == 0) a = 0;
					before = cell[j][i];
				}
				b++;
				if (b >= K) { // K ���� ����
					stop = true;
					break;
				}
			}
		}

		if (!stop) return false; // K���� �ȵǸ� false�� �ɷ��� �޺κ� Ž�����ϰ� �ð����̱�
	}
	
	return true; 
}

int Comb() {

	
	int cpy[15][25] = {0};

	// ��ǰ�ȳ�����,
	if (Check(Cell)) return 0;

	//��ǰ ���� ������.
	for (int i = 0; i < D; i++) {
		memcpy(cpy, Cell, sizeof(Cell)); 
		for (int j = 0; j < W; j++) {
			cpy[i][j] = 1;
		}
		if (Check(cpy)) return 1;

		memcpy(cpy, Cell, sizeof(Cell));
		for (int j = 0; j < W; j++) {
			cpy[i][j] = 0;
		}
		if (Check(cpy)) return 1;
	}

	//2~K-1���� ���� -> K�� ��ǰó���ϸ� ������ �Ǵϱ�..
	for (int i = 2; i < K; i++) {

		vector<int>V;
		
		for (int j = 0; j < D - i; j++) {
			V.push_back(0);
		}

		for (int j = 0; j < i; j++) {
			V.push_back(1);
		}
		
		do {

			vector<int>Num;
			for(int j = 0; j < D; j++) {
				if (V[j] == 1) Num.push_back(j);
			}
			
			int cpy[15][25] = { 0 };
			memcpy(cpy, Cell, sizeof(Cell));

			put_medicine(Num, 0, cpy);
			if(flag) break;
			

		} while (next_permutation(V.begin(),V.end()));

		if (flag) {
			return i;
		}
	}


	return K; //��ǰ K�� ������ ������ ���Ǹ�����ų �� ����
}


void put_medicine(vector<int>v,int idx, int map[15][25]) {

	if (idx == v.size()) {

		if (Check(map)) flag = true;
		return;
	}

	for (int i = 0; i < W; i++) { //A��ǰ �ֱ�
		map[v[idx]][i] = 0;
	}
	put_medicine(v, idx + 1, map);


	for (int i = 0; i < W; i++) { //B��ǰ �ֱ�
		map[v[idx]][i] = 1;
	}
	put_medicine(v, idx + 1, map);
}

