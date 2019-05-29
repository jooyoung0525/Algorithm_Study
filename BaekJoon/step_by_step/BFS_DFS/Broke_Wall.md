```c
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;    //queue 쓰기 위해 꼭 필요

queue<pair<pair<int,int>,int>>Q;

int map[1000][1000];
int visit[1000][1000][3] = { 0 }; //map배열 방문확인 + 벽 깼는지 유무확인
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };


int BFS(int N, int M,int canbroken) {     //int형 함수 이용해서 void보다 코드길이 줄일 수 있다

	visit[0][0][canbroken] = 1;      //초기값 방문체크
	Q.push(make_pair(make_pair(0, 0), canbroken));  //queue에 초기값 넣어줌

	while (!Q.empty())   
	{

		int curx = Q.front().first.first;
		int cury = Q.front().first.second;
		int isbroken = Q.front().second;
    Q.pop();
    
		printf("%d %d %d\n", curx, cury, isbroken);  //큐에 알맞은 값이 들어가는지 디버깅 (확인 차)

		if (curx == N-1 && cury == M - 1)      //만약에 현재 좌표가 마지막지점까지 도착했다면 정답 리턴
			return visit[curx][cury][isbroken];

		for (int i = 0; i < 4; i++)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];

			if (nx < 0 || ny < 0 || nx > N-1 || ny > M-1)continue;

			if (map[nx][ny] == 0 && visit[nx][ny][isbroken] == 0)
			{
				Q.push(make_pair(make_pair(nx, ny), isbroken));
				visit[nx][ny][isbroken] = visit[curx][cury][isbroken] + 1;
			}

			if (map[nx][ny] == 1 && isbroken == 1)    // 벽이 있고, 벽을 깰 수 있는 상태이면
			{
				Q.push(make_pair(make_pair(nx, ny), isbroken-1)); //다음 좌표와 벽을 깬 상태를 Q에 넣어줌
				visit[nx][ny][isbroken-1] = visit[curx][cury][isbroken] + 1; // 벽을 깬 상태의 (nx,ny)좌표의 방문은 벽을 깨지 않은 현재 위치좌표 + 1
			}
		}

	}
	return -1; //만약 도착좌표에 도달하지 않았을 경우 -1 반환

}



int main() {

	int N, M, i, j;
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%1d",&map[i][j]); //스페이스바 이용하지 않는 입력 사용할때 
		}
	}

	int result = BFS(N,M,1);

	printf("%d", result);
	//system("pause");

	return 0; 
}
```
