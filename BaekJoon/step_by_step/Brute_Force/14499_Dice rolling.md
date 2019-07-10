![주1](https://user-images.githubusercontent.com/29946480/60949574-c65a3a80-a2f5-11e9-9506-74025940b4ba.PNG)
![주2](https://user-images.githubusercontent.com/29946480/60949575-c65a3a80-a2f5-11e9-9708-7bdee8b54cba.PNG)
---------------------------------------------------------------------------------------------------------------
### 주사위 동작, 문제는 이해가는데 map의 범위를 벗어날때 처리하는것에서 멈춤....ㅠㅠ 
## ☞☞☞ Queue로 해결!!!!
----------------------------------------------------------------------------------------------------------------

↓↓↓ 1. 다른사람 풀이보고 푼거

-----------------------------------------------------------------------------------------------------------------

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
/*
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
				
*/	
	system("pause");
	return 0;
}
```
----------------------------------------------------------------------------------------------------------------

↓↓↓ 2. 내 생각으로 다시 푼거!!(Queue이용)

-----------------------------------------------------------------------------------------------------------------
```c
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

int cube[4][3] = {0};
int map[21][21] = {0};
int N, M;

queue<pair<int, int>>Q;//map의 범위를 벗어나는 경우를 queue로 해결

void rolling(int order) //주사위 굴리면 앞,뒤,양옆,위,아래 바뀌는거 표현
{
	int temp[4] = {0};
	if (order == 3 || order == 4)
	{
		temp[0] = cube[0][1];
		temp[1] = cube[1][1];
		temp[2] = cube[2][1];
		temp[3] = cube[3][1];

		if (order == 3)
		{
			cube[0][1] = temp[1];
			cube[1][1] = temp[2];
			cube[2][1] = temp[3];
			cube[3][1] = temp[0];
		}
		else if (order == 4)
		{
			cube[0][1] = temp[3];
			cube[1][1] = temp[0];
			cube[2][1] = temp[1];
			cube[3][1] = temp[2];
		}
	}
	else if (order == 1 || order == 2)
	{
		temp[0] = cube[1][0];
		temp[1] = cube[1][1];
		temp[2] = cube[1][2];
		temp[3] = cube[3][1];

		if (order == 1)
		{
			cube[1][0] = temp[3];
			cube[1][1] = temp[0];
			cube[1][2] = temp[1];
			cube[3][1] = temp[2];
		}
		else if (order == 2)
		{
			cube[1][0] = temp[1];
			cube[1][1] = temp[2];
			cube[1][2] = temp[3];
			cube[3][1] = temp[0];
		}
	}
}

void order_map(int go)
{
	int nx, ny;
	int X = Q.front().first; //queue의 처음 값
	int Y = Q.front().second; //queue의 두번째 값
	
	if (go == 1) //동쪽
	{
		nx = X; //다음 x위치
		ny = Y + 1; //다음 y위치
		if (nx < N && nx >= 0 && ny < M && ny >= 0) { //주사위가 다음으로 갈 위치가 지도 범위안에 있을 때,
			Q.pop(); //※queue에서 현재위치를 빼고※ ==> 지도 범위안에 있을 때만 현재위치를 뺄 수 있음!! 
			         //                           범위조건 만족안하는데 queue에서 현재 위치 빼면 queue가 빈 상태여서 작동안함!!
				 //☆★ queue를 사용안하고 그냥 위치를 계산할 경우 다음위치가 이상해짐 ☆★   
			Q.push({ nx, ny }); //※다음위치를 queue에 넣어줌※
			rolling(go);
			if (map[nx][ny] == 0)
			{
				map[nx][ny] = cube[3][1]; //다음 지도칸이 0일때, 주사위 바닥의 숫자를 지도 다음칸에 복사
			}
			else {                            //다음 지도칸이 0이 아닐 때,
				cube[3][1] = map[nx][ny]; //주사위 바닥에 다음 지도칸의 숫자를 복사하고
				map[nx][ny] = 0;          //그 지도칸의 숫자는 0으로 만듦
			}
			printf("%d\n", cube[1][1]);
		}
	}
	else if (go == 2) //서쪽
	{
		nx = X;
		ny = Y - 1;
		if (nx < N && nx >= 0 && ny < M && ny >= 0) {
			Q.pop();
			Q.push({ nx, ny });
			rolling(go);
			if (map[nx][ny] == 0)
			{
				map[nx][ny] = cube[3][1];
			}
			else {
				cube[3][1] = map[nx][ny];
				map[nx][ny] = 0;
			}
			printf("%d\n", cube[1][1]);
		}
	}
	else if (go == 3)
	{
		nx = X-1;
		ny = Y;
		if (nx < N && nx >= 0 && ny < M && ny >= 0) {
			Q.pop();
			Q.push({ nx, ny });
			rolling(go);
			if (map[nx][ny] == 0)
			{
				map[nx][ny] = cube[3][1];
			}
			else {
				cube[3][1] = map[nx][ny];
				map[nx][ny] = 0;
			}
			printf("%d\n", cube[1][1]);
		}
	}
	else if (go == 4)
	{
		nx = X + 1;
		ny = Y;
		if (nx < N && nx >= 0 && ny < M && ny >= 0) {
			Q.pop();
			Q.push({ nx, ny });
			rolling(go);
			if (map[nx][ny] == 0)
			{
				map[nx][ny] = cube[3][1];
			}
			else {
				cube[3][1] = map[nx][ny];
				map[nx][ny] = 0;
			}
			printf("%d\n", cube[1][1]);
		}
	}
	
}

int main()
{
	int x,y,k;
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &k);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]); // 지도입력받
	}
	
	Q.push({ x, y }); //queue에 초기 위치 값 넣어줌

	for (int i = 0; i < k; i++) //명령갯수만큼
	{
		int go; 
		scanf("%d", &go); //명령입력받음
		order_map(go); //함수실행
		
		
	}

	//system("pause");
	return 0;
}
```
