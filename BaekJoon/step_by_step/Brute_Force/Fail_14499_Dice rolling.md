---------------------------------------------------------------------------------------------------------------
###주사위 동작, 문제는 이해가는데 map의 범위를 벗어날때 처리하는것에서 멈춤....ㅠㅠ
----------------------------------------------------------------------------------------------------------------

```c
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

int map[30][30] = {0};
int visit[30][30] = {0};
int dice[4][3] = {0};
int N, M,x,y;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>>Q;

void Roll_dice(int dir)
{
	int dice_temp[4];
	
	if (dir == 1 || dir == 2)
	{
		dice_temp[0] = dice[1][0];
		dice_temp[1] = dice[1][1];
		dice_temp[2] = dice[1][2];
		dice_temp[3] = dice[3][1];
		if (dir == 1)
		{	
			dice[1][0] = dice_temp[3];
			dice[1][1] = dice_temp[0];
			dice[1][2] = dice_temp[1];
			dice[3][1] = dice_temp[2];
		}
		else if (dir == 2)
		{
			dice[1][0] = dice_temp[1];
			dice[1][1] = dice_temp[2];
			dice[1][2] = dice_temp[3];
			dice[3][1] = dice_temp[0];
		}
	}
	else if (dir == 3 || dir == 4)
	{
		dice_temp[0] = dice[0][1];	
		dice_temp[1] = dice[1][1];
		dice_temp[2] = dice[2][1];
		dice_temp[3] = dice[3][1];

		if (dir == 3)
		{
			dice[0][1] = dice_temp[1];
			dice[1][1] = dice_temp[2];
			dice[2][1] = dice_temp[3];
			dice[3][1] = dice_temp[0];
		}
		else if (dir == 4)
		{
			dice[0][1] = dice_temp[3];
			dice[1][1] = dice_temp[0];
			dice[2][1] = dice_temp[1];
			dice[3][1] = dice_temp[2];				
		}
	}
}

int main() {

	int k,dir;
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &k);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	


	for (int i = 0; i < k; i++)
	{
		scanf("%d", &dir);

		int nx = x + dx[dir-1];
		int ny = y + dy[dir-1];

		if (nx >= 0 || nx <= N - 1 || ny >= 0 || ny <= M - 1) {

			Roll_dice(dir);

			if (map[nx][ny] == 0)
				map[nx][ny] = dice[3][1];
			else {
				dice[3][1] = map[nx][ny];
				map[nx][ny] = 0;
			}

			printf("%d\n", dice[1][1]);
		}
		x = nx;
		y = ny;

		for (int j = 0; j < 4; j++)
		{
			for (int g = 0; g < 3; g++)
			{
				printf("%d ", dice[j][g]);
			}
			printf("\n");
		}
		printf("\n");
		printf("\n");
	}
				
	
	system("pause");
	return 0;
}
```
