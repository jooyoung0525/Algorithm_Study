#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct shark { int x, y, dir; };
struct fish { int id, x, y, dir; bool die; };

shark S;
vector<fish>F;
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,-1,-1,-1,0,1,1,1 };


bool cmp(fish a, fish b) {
	return a.id < b.id;
}
void solution();
int play(int Map[5][5], vector<fish>fish, int x, int y);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}


void solution() {

	int Map[5][5] = { 0 };

	F.push_back({ 0,0,0,0,false });

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int n, d;
			cin >> n >> d;
			Map[i][j] = n;
			F.push_back({ n,i,j,d - 1,false }); //������ 0~7
		}
	}

	sort(F.begin(), F.end(), cmp);

	cout << play(Map, F, 0, 0);

}

int play(int Map[5][5], vector<fish>F, int x, int y) {


	//dfs�����ߵǼ� ���̶� ��������� �����ؼ� ����
	vector<fish>newF;
	newF = F;

	int newM[5][5] = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			newM[i][j] = Map[i][j];
		}
	}



	//��� �ű��
	int nowfish = newM[x][y]; //���� �� �Դ� �����
	S = { x,y,newF[nowfish].dir };
	newF[nowfish].die = true; //����� ���̱�
	newM[x][y] = 0; //�� ����




	/*
	cout << "\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << newM[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";*/

	//����� �ű�� -> �ű� ����� ���ο� ���Ϳ� ����
	for (int i = 1; i < newF.size(); i++) {
		if (newF[i].die)continue;

		int cx = newF[i].x;
		int cy = newF[i].y;
		int cd = newF[i].dir;

		int nx = cx + dx[cd];
		int ny = cy + dy[cd];
		//cout << "cx" <<i<<" "<< cx << cy << "\n";
		if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || (S.x == nx && S.y == ny)) { //�����Ѿ�ų�, ����̸�
			//cout << i<<nx << ny << cd << "\n";
			int nd = cd;
			for (int j = 0; j < 7; j++) {
				nd = (nd + 1) % 8;
				int nnx = cx + dx[nd];
				int nny = cy + dy[nd];
				if (nnx < 0 || nny < 0 || nnx >= 4 || nny >= 4 || (S.x == nnx && S.y == nny)) continue;
				//cout << "nd" << nd << "\n";
				break;
			}
			nx = cx + dx[nd];
			ny = cy + dy[nd];
			newF[i].dir = nd;
		}

		if (newM[nx][ny] == 0) {
			newM[nx][ny] = i;
			newM[cx][cy] = 0;
			newF[i].x = nx;
			newF[i].y = ny;
		}
		else {
			int nidx = newM[nx][ny];
			newM[cx][cy] = nidx;
			newM[nx][ny] = i;

			newF[i].x = nx;
			newF[i].y = ny;

			newF[nidx].x = cx;
			newF[nidx].y = cy;
		}
	}
	/*
	cout << "newFish\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << newM[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	for (int i = 1; i < newF.size(); i++) {

		cout << "i : " << i << "    " << newF[i].x << " " << newF[i].y <<" dir : "<<newF[i].dir<< " die : "<<newF[i].die<<"\n";
	}*/
	int ans = 0;
	int sd = S.dir;
	int sx = S.x + dx[sd]; int sy = S.y + dy[sd];

	/*
	while (!(sx < 0 || sy < 0 || sx >= 4 || sy >= 4)) {
		if (newM[sx][sy] != 0) {
			ans = max(ans, play(newM, newF, sx, sy));
		}
		sx += dx[sd];
		sy += dy[sd];
	}

	return ans + nowfish;*/

	while (!(sx < 0 || sy < 0 || sx >= 4 || sy >= 4)) { //������ ����� �� ���̻� �� �� ����
		if (newM[sx][sy] != 0) { //��ĭ �ǳʶ� �κп� �� �� �� �����Ƿ� �� ���ǿ��� �ɷ��ָ� �ȵ�.
			ans = max(ans, play(newM, newF, sx, sy));
		}
		sx += dx[sd]; sy += dy[sd];
	}
	return ans + nowfish;
}