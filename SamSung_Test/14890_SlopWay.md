
------------------------------------------------------------------------------------------------------------

### 7시간 걸렸다.....
### 엄청 어렵게 짠 코드...!!!!

## [ 내가 생각한 방법 ]
### 1. 가로/세로 0일때 각각 dfs돌려줌 (이때, 높이의 기준점은 처음시작한 점으로 잡음)
### 2. 각각의 dfs에서 다음지점(map의 끝)이 N-1 이면 리턴
### 3. 기준높이랑 다음지점의 높이랑 같으면 방문을 1로 체크하고, 다음지점에서 DFS
### 4. 기준높이가 다음지점의 높이랑 절댓값 1차이 날 때 (경사로 세울 가능성있는경우)
###    4-1) 기준높이랑 다음지점높이랑 -1 차이날 경우 ( 이전의 높이가 다음 높이보다 작다) 
###    4-2) 기준높이랑 다음지점높이랑 +1 차이날 경우 ( 이전의 높이가 다음 높이보다 크다) 
### 5. 각각의 조건안에서 세부조건을 정해준다.( 엄청 까다로워서..오래걸림 ㅠㅠ // 시험이었으면 틀렸을듯.. 반례때문)
### 6. 가로/세로 각각의 visit[][]에서 끝지점에 도달했을 경우 카운트를 해준다( >0 )

------------------------------------------------------------------------------------------------------------

### 풀이 1. (dfs이용)

```c
#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

int N,L;
int map[110][110] = { 0 };
int visitC[110][110] = { 0 };
int visitR[110][110] = { 0 };

void DFSC(int x, int y, int height);
void DFSR(int x, int y, int height);

int main()
{
	int result = 0;

	cin >> N>>L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		DFSC(i, 0, map[i][0]);
		DFSR(0, i, map[0][i]);
	}

	for (int i = 0; i < N; i++)
	{
		if (visitC[i][N - 1] > 0) //가로의 끝지점에 도달했을경우
			result++;
		if (visitR[N - 1][i] > 0) //세로의 끝지점에 도달했을 경우
			result++;
	}
	cout << result;
	
	return 0;
}

void DFSC(int x, int y, int height)
{
	if (y == N - 1)
	{
		return;
	}
	int ny = y + 1;
	if (ny < N) { //다음위치가 범위를 벗어나면 안됨

		if (height == map[x][ny] && visitC[x][ny] != 1)
		{
			visitC[x][ny] = 1;
			DFSC(x, ny, height);
		}

		int cnt = 0;

		if ((height - map[x][ny]) == -1)
		{
			int ny2 = y;
			for (int i = 0; i < L; i++)
			{
				if (map[x][ny2] == height && visitC[x][ny2] != 2)
				{
					cnt++;
					ny2--;
				}
			}
			if (cnt == L)
			{
				ny2 = y;
				for (int i = 0; i < L; i++)
				{
					visitC[x][ny2] = 2; //꼭 for문으로 경사로 모두 방문처리 해줘야 경사로가 겹쳐서 안생김!!
					ny2--;
				}
				DFSC(x, y, height + 1);
			}
		}
		if (height - map[x][ny] == 1&& (height - 1) >= map[x][y+L])
		{
			int ny2 = y;
			for (int i = 0; i < L; i++)
			{
				ny2++; //이거때매..계속틀림..ㅠㅠ
				if (map[x][ny2] == (height-1) && visitC[x][ny2] != 2)
				{
					cnt++;		
				}
			}
			if (cnt == L)
			{
				ny2 = y;
				for (int i = 0; i < L; i++)
				{
					ny2++;
					visitC[x][ny2] = 2;
				}
				DFSC(x, ny2, height - 1);
			}
		}
	}
}

void DFSR(int x, int y, int height)
{
	if (x == N - 1)
	{
		return;
	}
	int nx = x + 1;
	if (nx < N) {

		if (height == map[nx][y] && visitR[nx][y] != 1)
		{
			visitR[nx][y] = 1;
			DFSR(nx, y, height);
		}

		int cnt = 0;
		if ((height - map[nx][y]) == -1)
		{
			int nx2 = x;
			for (int i = 0; i < L; i++)
			{
				if (map[nx2][y] == height && visitR[nx2][y]!=2)
				{
					cnt++;
					nx2--;
				}
			}
			if (cnt == L)
			{
				nx2 = x;
				for (int i = 0; i < L; i++)
				{
					visitR[nx2][y] = 2;
					nx2--;
				}
				DFSR(x, y, height + 1);
			}
		}
		if (height - map[nx][y] == 1 && (height-1) >= map[nx+L][y]) //이조건도 까다로움! 다음높이가 기준높이보다 작을경우 경사로 다음칸 높이가 경사로랑 같아야함!!!!!!
		{
			int nx2 = x ;
			for (int i = 0; i < L; i++)
			{
				nx2++;
				if (map[nx2][y] == (height-1) && visitR[nx2][y] != 2)
				{
					cnt++;	
				}
			}
			if (cnt == L)
			{
				nx2 = x;
				for (int i = 0; i < L; i++)
				{
					nx2++;
					visitR[nx2][y] = 2;
						
				}
				DFSR(nx2, y, height - 1);
			}
		}
	}
}

```
