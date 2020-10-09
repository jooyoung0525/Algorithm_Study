/*
 1. 맵을 돌면서 사이클이 있는지 DFS
     -> 1.시작점 (돌아와야할 점을 저장하고), DFS를 돌면서 시작점(cnt == 4이상)을 만나면 Yes
     ->그 외, 모두 No
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

    //모든 맵의 원소를 시작점으로 한번씩 잡아서 DFS돌림
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            memset(visit, false, sizeof(visit)); //방문체크 배열도 시작점마다 새롭게 만들어서 DFS에 넘겨줌
            visit[i][j] = true;
            Start = { i,j,map[i][j] };
            DFS(i, j, 1, visit);
          
            if (Stop) break; //답이 출력됬으므로 break;
        }
        if (Stop)break; //답이 출력됬으므로 break;
    }

    if (!Stop)cout << "No"; //답이 출력되지 않았으면 No 출력

	return 0;
}


void DFS(int x, int y, int cnt, bool visit[55][55]) {
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx == Start.x && ny == Start.y && map[nx][ny]==Start.color) { //다음점이 시작점이고, 색깔이 같을 때
            if (cnt < 3) continue; // 현재 점의 개수가 3개 미만이면 시작점으로 만나도 점이 4개가 안되므로 건너 뜀
            cout << "Yes";
            Stop = true;
            return;
        }

        if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;

        if ((!visit[nx][ny] && map[nx][ny] == Start.color)) {
            visit[nx][ny] = true;
            DFS(nx, ny, cnt + 1, visit);
            if (Stop)return; //답이 출력됬으므로 main문으로 돌아감
        }
    }
}