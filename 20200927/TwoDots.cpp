/*
 1. ���� ���鼭 ����Ŭ�� �ִ��� DFS
     -> 1.������ (���ƿ;��� ���� �����ϰ�), DFS�� ���鼭 ������(cnt == 4�̻�)�� ������ Yes
     ->�� ��, ��� No
*/

#include<iostream>
#include<cstring>

using namespace std;

struct dot { int x, y; char color; };
dot Start;

int N, M;
char map[55][55];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool Stop;
void DFS(int x, int y, int cnt, bool visit[55][55]);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    bool visit[55][55] = {false,};

    //��� ���� ���Ҹ� ���������� �ѹ��� ��Ƽ� DFS����
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            memset(visit, false, sizeof(visit)); //�湮üũ �迭�� ���������� ���Ӱ� ���� DFS�� �Ѱ���
            visit[i][j] = true;
            Start = { i,j,map[i][j] };
            DFS(i, j, 1, visit);
          
            if (Stop) break; //���� ������Ƿ� break;
        }
        if (Stop)break; //���� ������Ƿ� break;
    }

    if (!Stop)cout << "No"; //���� ��µ��� �ʾ����� No ���

	return 0;
}


void DFS(int x, int y, int cnt, bool visit[55][55]) {
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx == Start.x && ny == Start.y && map[nx][ny]==Start.color) { //�������� �������̰�, ������ ���� ��
            if (cnt < 3) continue; // ���� ���� ������ 3�� �̸��̸� ���������� ������ ���� 4���� �ȵǹǷ� �ǳ� ��
            cout << "Yes";
            Stop = true;
            return;
        }

        if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;

        if ((!visit[nx][ny] && map[nx][ny] == Start.color)) {
            visit[nx][ny] = true;
            DFS(nx, ny, cnt + 1, visit);
            if (Stop)return; //���� ������Ƿ� main������ ���ư�
        }
    }
}